#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define DIM 3

void read_vec ( int A[DIM]);
void write_vec (int A[DIM]);
void vectmult(int A[DIM], int B[DIM], int c);

int main(int argc, char* argv[]) {
	int thread_count = strtol(argv[1], NULL, 10);
	int A[DIM], B[DIM];
	int c=0;

	read_vec(A);
    write_vec(A);
    read_vec(B);
    write_vec(B);


    #pragma omp parallel num threads(thread count)
	vectmult(A,B,c);
	return 0;
}

void read_vec(int A[DIM])
{
  int i;
  for (i=0;i<DIM;i++)
  	scanf("%d",&A[i]);
}

void write_vec(int A[DIM])
{
	int i;
	for (i=0;i<DIM;i++)
 	printf("%d  ", A[i]);
}

void vectmult(int A[DIM], int B[DIM], int c) {
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
	int i;
	for (i=0;i<DIM;i++){
		c=c+(A[i]*B[i]);
		printf(" Resolviendo el producto punto y estoy en %d de %d\n", my_rank, thread_count);
	}
	printf("La respuesta de tu producto punto es %d\n", c);
}



