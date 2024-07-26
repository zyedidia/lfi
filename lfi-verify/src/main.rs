use std::env;
use std::fs;
use std::process;
use std::time::Instant;

use verifier::Verifier;
use xmas_elf::{program::SegmentData, ElfFile};

mod inst;
mod verifier;
mod autogen;
mod reg;

fn show_error(bytes: *const u8, size: usize) {
    let s = unsafe { String::from_utf8_lossy(std::slice::from_raw_parts(bytes, size)) };
    eprintln!("error: {}", s);
}

fn main() {
    let argv: Vec<String> = env::args().collect();
    if argv.len() != 2 {
        eprintln!("Usage: {} <elf>", argv[0]);
        process::exit(1);
    }

    let buf = fs::read(&argv[1]).unwrap();

    let elf = ElfFile::new(&buf).unwrap();

    println!("verifying {}", argv[1]);

    let mut size = 0;

    let start = Instant::now();

    let mut verif = Verifier {
        failed: false,
        message: Some(show_error),
    };

    for prog in elf.program_iter() {
        if !prog.flags().is_execute() {
            continue;
        }
        let base = prog.virtual_addr();
        size += prog.file_size();

        if let Ok(SegmentData::Undefined(bytes)) = prog.get_data(&elf) {
            let mut iter = bad64::disasm(bytes, base);
            while let Some(maybe_decoded) = iter.next() {
                match maybe_decoded {
                    Ok(inst) => {
                        verif.check_insn(&inst);
                    }
                    Err(e) => {
                        verif.failed = true;
                        eprintln!("{:x}: unknown instruction: {}", e.address(), e);
                    }
                }
            }
        } else {
            eprintln!("error reading segment data");
            process::exit(1);
        }
    }

    let duration = start.elapsed();

    if verif.failed {
        eprintln!("verification failed");
        process::exit(1);
    }

    println!(
        "verification passed ({:.1} MB/s)",
        (size as f64) / duration.as_secs_f64() / 1_000_000.0
    );
}
