mkdir -p .core .buddy .cwalk .arch/amd64
ldc2 -makedeps=.elf.dep -c elf.d -of .elf.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.fd.dep -c fd.d -of .fd.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.file.dep -c file.d -of .file.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.main.dep -c main.d -of .main.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.object.dep -c object.d -of .object.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.pipe.dep -c pipe.d -of .pipe.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.proc.dep -c proc.d -of .proc.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.queue.dep -c queue.d -of .queue.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.sched.dep -c sched.d -of .sched.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.signal.dep -c signal.d -of .signal.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.sys.dep -c sys.d -of .sys.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.arch/amd64/regs.dep -c arch/amd64/regs.d -of .arch/amd64/regs.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.arch/amd64/sys.dep -c arch/amd64/sys.d -of .arch/amd64/sys.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.core/alloc.dep -c core/alloc.d -of .core/alloc.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.core/emplace.dep -c core/emplace.d -of .core/emplace.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.core/exception.dep -c core/exception.d -of .core/exception.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.core/lib.dep -c core/lib.d -of .core/lib.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.core/math.dep -c core/math.d -of .core/math.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.core/vector.dep -c core/vector.d -of .core/vector.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.lfi/package.dep -c lfi/package.d -of .lfi/package.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.buddy/package.dep -c buddy/package.d -of .buddy/package.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
ldc2 -makedeps=.cwalk/package.dep -c cwalk/package.d -of .cwalk/package.o -O2 -betterC -function-sections -data-sections -relocation-model=static -g -d-version=amd64
gcc -c arch/amd64/switch.S -o .arch/amd64/switch.o -DAMD64
gcc -O2 -Wall -c buddy/buddy.c -o .buddy/buddy.o -I.
gcc -O2 -Wall -c cwalk/cwalk.c -o .cwalk/cwalk.o -I.
gcc .elf.o .fd.o .file.o .main.o .object.o .pipe.o .proc.o .queue.o .sched.o .signal.o .sys.o .arch/amd64/regs.o .arch/amd64/sys.o .core/alloc.o .core/emplace.o .core/exception.o .core/lib.o .core/math.o .core/vector.o .lfi/package.o .buddy/package.o .cwalk/package.o .arch/amd64/switch.o .buddy/buddy.o .cwalk/cwalk.o -o lfi-run -static -Wl,--gc-sections -fno-pic -L../liblfi -L../lfi-veribdd -llfi -llfiveribdd
