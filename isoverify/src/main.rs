use std::env;
use std::fs;
use std::process;
use std::time::Instant;

use peekmore::PeekMore;
use verifier::check;
use xmas_elf::ElfFile;

mod inst;
mod verifier;

fn main() {
    let argv: Vec<String> = env::args().collect();
    if argv.len() != 2 {
        eprintln!("Usage: {} <elf>", argv[0]);
        process::exit(1);
    }

    let buf = fs::read(&argv[1]).unwrap();

    let elf = ElfFile::new(&buf).unwrap();

    let text_section = elf.find_section_by_name(".text").unwrap();

    let base = text_section.address();
    let size = text_section.size();
    let bytes = text_section.raw_data(&elf);

    println!("verifying {}: {} bytes", argv[1], size);

    let start = Instant::now();

    let mut iter = bad64::disasm(bytes, base).peekmore();
    while let Some(maybe_decoded) = iter.next() {
        match maybe_decoded {
            Ok(inst) => {
                check(&inst, &mut iter);
            }
            Err(e) => eprintln!("{:x}: unknown instruction: {}", e.address(), e),
        }
    }

    let duration = start.elapsed();

    if unsafe { verifier::FAILED } {
        eprintln!("verification failed");
        process::exit(1);
    }

    println!(
        "verification passed ({:.1} MB/s)",
        (size as f64) / duration.as_secs_f64() / 1_000_000.0
    );
}
