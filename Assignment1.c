#include <stdio.h>
#include <stdlib.h>
// Matrix Multiplication
// Given two square matrices A and B (size N×N, type double), 
// compute:C = A x B
#define N 10
//Building logic

int main(){
int i,j;
int a[N][N];
int b[N][N];
int c[N][N];
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        a[i][j] = 1;
    }
}
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        b[i][j] = 1;
    }
}
for(i=0; i<N;i++){
    for(j=0; j<N; j++)
    c[i][j] = a[i][j] * b[i][j];
}
printf("The Result: %d",c[i][j]);

return 0;
}