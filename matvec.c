#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define MATRIXVECTOR_SIZE		4

int main(void)
{
	int matrix[MATRIXVECTOR_SIZE][MATRIXVECTOR_SIZE] = {{1, 0, 0, 0},
														{0, 1, 0, 0},
														{0, 0, 1, 0},
														{0, 0, 0, 1}};
	int rvector[MATRIXVECTOR_SIZE]={5,6,1,2};
	int SIZE = sizeof(int);
	int comm_sz, my_rank;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	int real_size=comm_sz-1;
	if(real_size!=MATRIXVECTOR_SIZE)
	{
		if (my_rank == 0)
			printf("Es necesario de %d procesos esclavos\n",MATRIXVECTOR_SIZE);
		MPI_Finalize();
		return 0;
	}
	int rec;
	if (my_rank < real_size)
	{
		rec=0;
		for (int i = 0; i <  MATRIXVECTOR_SIZE; ++i)
			rec+=matrix[my_rank][i]*rvector[i];
		MPI_Send(&rec, SIZE, MPI_INT, real_size, my_rank,MPI_COMM_WORLD);
	}
	else
	{
		for (int k=0; k<real_size; ++k)
		{
			MPI_Recv(&rec, SIZE, MPI_INT, k,k, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%d\n",rec);
		}
	}
	MPI_Finalize();
	return 0;
}