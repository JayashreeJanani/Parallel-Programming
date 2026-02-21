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
//TODO1: Step 0: Clean file structure
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
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
    
    return 0;
}
