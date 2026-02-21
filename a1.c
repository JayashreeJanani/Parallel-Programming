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
 =====================================================================
 Steps to be completed
 Step 0: Understanding inputs/ outputs===============================100%
 Step 1: Parse N, mode and allocate A,B, C memory space==============100%
 Step 2: Initialization of matrices==================================100%
 Step 3: Mode 0(Serial Baseline)
 Step 4: Mode 1(threads + scheduling)
 Step 5: Mode 2(Collapse(2))
 Step 6: Mode 3(sync comparison: atomic vs critical)
 Step 7: Mode 4(tasks)
 Step 8: SIMD modes 
 Step 9: Performance experiments

 */
//TODO1: Step 0: Clean file structure
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//4.1. Step 1C--> allocation of memory spaces of matrix A, B, C
static double* alloc_matrix(int N) {
    double *m = (double*)malloc((size_t)N * (size_t)N * sizeof(double));
    //condition to check if malloc fails and returns NULL
    if (m == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return m;
}
int main(int argc, char **argv){
    printf("\n The number of arguments in argc = %d",argc);
    //1. the condition below checks whether this argc has < 3 values 
    //meaning size of matrix and number of threads are nnot giverm
    if (argc < 3) {
    printf("\n Usage: ./a1 N mode\n");
    return 1;
}
    
    if(argc==3){
        for(int i = 0;i<argc;i++){
        printf("%s\n",argv[i]);
    }

    }
    //2. Step 1A: Extracting argument values of argv, and converting them to integer
    int N = atoi(argv[1]);
    int mode = atoi(argv[2]);
    // printf("N = %d and mode = %d\n",N,mode);
    //3. Step 1B: Basic safety Check for N
    if (N<1){
        printf("Error! N should be greater than 0\n");
        return 1;
    }
    //4. Step 1C: Allocate Matrices
    double *A = alloc_matrix(N);
    double *B = alloc_matrix(N);
    double *C = alloc_matrix(N);
    
    return 0;
}
