mkdir -p .amd64 .arm64
cc -O2 -Wall -Wno-unused-function -MMD -MF .ht.dep -c ht.c -o .ht.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .main.dep -c main.c -o .main.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .op.dep -c op.c -o .op.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .util.dep -c util.c -o .util.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/fixup.dep -c arm64/fixup.c -o .arm64/fixup.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/arm64.dep -c arm64/arm64.c -o .arm64/arm64.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/flags.dep -c arm64/flags.c -o .arm64/flags.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/display.dep -c amd64/display.c -o .amd64/display.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/amd64.dep -c amd64/amd64.c -o .amd64/amd64.o -I.
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/flags.dep -c amd64/flags.c -o .amd64/flags.o -I.
(cd arm64; leg -P -o branch.leg.c branch.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/branch.leg.dep -c arm64/branch.leg.c -o .arm64/branch.leg.o -I.
(cd arm64; leg -P -o guardelim.leg.c guardelim.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/guardelim.leg.dep -c arm64/guardelim.leg.c -o .arm64/guardelim.leg.o -I.
(cd arm64; leg -P -o loads.leg.c loads.leg addr.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/loads.leg.dep -c arm64/loads.leg.c -o .arm64/loads.leg.o -I.
(cd arm64; leg -P -o stores.leg.c stores.leg addr.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/stores.leg.dep -c arm64/stores.leg.c -o .arm64/stores.leg.o -I.
(cd arm64; leg -P -o parse.leg.c parse.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/parse.leg.dep -c arm64/parse.leg.c -o .arm64/parse.leg.o -I.
(cd arm64; leg -P -o poc.leg.c poc.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/poc.leg.dep -c arm64/poc.leg.c -o .arm64/poc.leg.o -I.
(cd arm64; leg -P -o special.leg.c special.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/special.leg.dep -c arm64/special.leg.c -o .arm64/special.leg.o -I.
(cd arm64; leg -P -o meter.leg.c meter.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/meter.leg.dep -c arm64/meter.leg.c -o .arm64/meter.leg.o -I.
(cd arm64; leg -P -o syscall.leg.c syscall.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .arm64/syscall.leg.dep -c arm64/syscall.leg.c -o .arm64/syscall.leg.o -I.
(cd amd64; leg -P -o parse.leg.c parse.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/parse.leg.dep -c amd64/parse.leg.c -o .amd64/parse.leg.o -I.
(cd amd64; leg -P -o syscall.leg.c syscall.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/syscall.leg.dep -c amd64/syscall.leg.c -o .amd64/syscall.leg.o -I.
(cd amd64; leg -P -o special.leg.c special.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/special.leg.dep -c amd64/special.leg.c -o .amd64/special.leg.o -I.
(cd amd64; leg -P -o branch.leg.c branch.leg addr.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/branch.leg.dep -c amd64/branch.leg.c -o .amd64/branch.leg.o -I.
(cd amd64; leg -P -o stores.leg.c stores.leg addr.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/stores.leg.dep -c amd64/stores.leg.c -o .amd64/stores.leg.o -I.
(cd amd64; leg -P -o loads.leg.c loads.leg addr.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/loads.leg.dep -c amd64/loads.leg.c -o .amd64/loads.leg.o -I.
(cd amd64; leg -P -o decl.leg.c decl.leg common.leg)
cc -O2 -Wall -Wno-unused-function -MMD -MF .amd64/decl.leg.dep -c amd64/decl.leg.c -o .amd64/decl.leg.o -I.
cc .ht.o .main.o .op.o .util.o .arm64/fixup.o .arm64/arm64.o .arm64/flags.o .amd64/display.o .amd64/amd64.o .amd64/flags.o .arm64/branch.leg.o .arm64/guardelim.leg.o .arm64/loads.leg.o .arm64/stores.leg.o .arm64/parse.leg.o .arm64/poc.leg.o .arm64/special.leg.o .arm64/meter.leg.o .arm64/syscall.leg.o .amd64/parse.leg.o .amd64/syscall.leg.o .amd64/special.leg.o .amd64/branch.leg.o .amd64/stores.leg.o .amd64/loads.leg.o .amd64/decl.leg.o -o lfi-leg -static
