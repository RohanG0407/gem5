# Repo Information

## Prerequistes

- Build gem5.opt for ARM ISA (<http://www.gem5.org/documentation/general_docs/building>)
- Install aarch64-linux-gnu-gcc cross compiler for x86 -> aarch64

## Current Repo Structure

- src/cpu/o3/comp_simp.cc && src/cpu/o3/comp_simp.hh contain logic for checking for fast pass before dispatch to FU
- src/cpu/o3/inst_queue.cc contains call for CompSimp::Analyze where we override inst latency if fast pass is detected
- micro-benchmarks/ contains framework for writing your own C programs to test with modified GEM5
  - change Makefile to ensure it builds correctly

## Run Command

In GEM5 base directory **scons build/ARM/gem5.opt -j16** builds gem5.opt for ARM with 16 cores

W/O Debug prints **./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="o3" "micro-benchmarks/hello-static"** runs program from micro-benchmarks/hello.c

W Debug prints **./build/ARM/gem5.opt --debug-flags=IQ,IEW configs/example/arm/starter_se.py --cpu="o3" "micro-benchmarks/hello-static" > IQ_IEW_output.txt**
