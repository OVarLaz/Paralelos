#include <stdio.h>
#include <string.h>
#include <mpi.h>
const int MAX_STRING = 100;
#define DIM 3
void read_matrix ( int A[DIM][DIM]);
void write_matrix (int A[DIM][DIM]);
void producto_matrices (int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM]);

int main(void) {

	int A[DIM][DIM],B[DIM][DIM],C[DIM][DIM];
    read_matrix(A);
    write_matrix(A);
    read_matrix(B);
    write_matrix(B);

	char greeting[MAX_STRING];
	int	comm_sz;/* Number of processes */
	int my_rank;/* My process rank */

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	if (my rank != 0) {
		sprintf(greeting, "Matrix greetings from process %d of %d!",my_rank, comm_sz);
		MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0, 	MPI_COMM_WORLD);
	}
	else {
		printf("Matrix greetings from process %d of %d!\n", my_rank, comm_sz);
		for (int q = 1; q < comm_sz; q++) {
			MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q,	0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%s\n", greeting);
			int i,j,k;
			 for (i=0;i<DIM;i++)
			     for(j=0;j<DIM;j++)
			      {   C[i][j] = 0;
			          for(k=0;k<DIM;k++)
			              C[i][j] = C[i][j] + A[i][j] * B[i][j];
		}
	}
	write_matrix(C);
	MPI_Finalize();

	return 0;
}

void read_matrix(int A[DIM][DIM])
{
  int i,j;
  for (i=0;i<DIM;i++)
      {
       printf("Dame los %d datos de la fila %d: n",DIM,i+1);
       for (j=0;j<DIM;j++)
           scanf("%d",&A[i][j]);
      }
}

void write_matrix(int A[DIM][DIM])
{
 int i, j;
 printf("Esta matrix es: n");
 for (i=0;i<DIM;i++)
 {
  for (j=0;j<DIM;j++)
      printf("%d  ", A[i][j]);
      printf("n");
  }
}

void producto_matrices (int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM])
{
 
      }
}