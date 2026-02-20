 
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// Matrix Multiplication
// Given two square matrices A and B (size N×N, type double),
// compute:C = A x B
// #define N 10
//Building logic
static double* alloc_matrix(int N) {
    double *m = (double*)malloc((size_t)N * (size_t)N * sizeof(double));
    if (!m) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return m;
}
int main(int argc, char **argv){
if (argc < 3) {
    printf("Usage: %s N mode\n", argv[0]);
    return 1;
}
    int N = atoi(argv[1]);
    int mode = atoi(argv[2]);
 
    if (N <= 0) {
        printf("Error: N must be > 0\n");
        return 1;
    }
    //Allocating matrices by calling the function alloc_matrix
    double *A = alloc_matrix(N);
    double *B = alloc_matrix(N);
    double *C = alloc_matrix(N);
    //Initialize A and B
    double total_start_time = omp_get_wtime();
    for(int i =0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i*N + j] = 1.0;
            B[i*N + j] = 1.0;
            C[i*N + j] = 0.0;
           
 
        }
    }
//Mode 0: Serial matrix multiplication + kernel timing
 double t_kernel_start = omp_get_wtime();
 
    // Serial baseline (Mode 0)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }
 
    double t_kernel_end = omp_get_wtime();
    //sanity check
    printf("Sanity check: C[0] = %.6f\n", C[0]);
    printf("Sanity check: C[last] = %.6f\n", C[N*N - 1]);
    //compute analytics---> serial execution
    double sumC = 0.0;
    double maxC = C[0];
    long long checksum = 0;
 
    for (int idx = 0; idx < N*N; idx++) {
        double x = C[idx];
        sumC += x;
        if (x > maxC) maxC = x;
 
        checksum += (long long)(x * 1000.0) % 100000;
    }
   //Total timing + clean output
   double t_total_end = omp_get_wtime();
 
    printf("N = %d\n", N);
    printf("Mode = %d (Serial Baseline)\n", mode);
    printf("Threads used = 1\n");
    printf("Kernel time (s) = %.6f\n", (t_kernel_end - t_kernel_start));
    printf("Total time (s)  = %.6f\n", (t_total_end - total_start_time));
    printf("sumC = %.6f\n", sumC);
    printf("maxC = %.6f\n", maxC);
    printf("checksum = %lld\n", checksum);
    //Free allocated memory
    free(A);
    free(B);
    free(C);
    return 0;
}
 