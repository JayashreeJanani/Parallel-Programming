/*
"The Program that we are going to execute is one executable."
 ./a1 N mode
 N = size of the matrix (NXN)
 mode = which implementation to run(serial, parallel-for, collapse, atomic/critical checksum, task, simd, etc.)
 Four big parts:
 1. Read inputs: (n,mode)
 2. Allocate A,B,C (dynamic 1D arrays)
 3. Initialize A and B 
 4. Run the selected mode
 */
//