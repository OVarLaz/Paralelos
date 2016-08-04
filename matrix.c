#include <stdio.h>
#include <stdlib.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

 #define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#define DIM 3
void leer_matriz ( int A[DIM][DIM]);
void escribe_matriz (int A[DIM][DIM]);
void producto_matrices (int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM]);
int main()
{
    int A[DIM][DIM],B[DIM][DIM],C[DIM][DIM];
    leer_matriz(A);
    escribe_matriz(A);
    leer_matriz(B);
    escribe_matriz(B);

    producto_matrices(A,B,C);
    printf("El producto vale: n");
    escribe_matriz(C);

      system("PAUSE");
      return 0;
}
void leer_matriz(int A[DIM][DIM])
{
  int i,j;
  for (i=0;i<DIM;i++)
      {
       printf("Dame los %d datos de la fila %d: n",DIM,i+1);
       for (j=0;j<DIM;j++)
           scanf("%d",&A[i][j]);
      }
}

void escribe_matriz(int A[DIM][DIM])
{
 int i, j;
 printf("Esta matriz es: n");
 for (i=0;i<DIM;i++)
 {
  for (j=0;j<DIM;j++)
      printf("%d  ", A[i][j]);
      printf("n");
  }
}

void producto_matrices (int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM])
{
 int i,j,k;
 for (i=0;i<DIM;i++)
     for(j=0;j<DIM;j++)
      {   C[i][j] = 0;
          for(k=0;k<DIM;k++)
              C[i][j] = C[i][j] + A[i][j] * B[i][j];
      }
}

void producto_matrices_cache (int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM])
{
 int i,j,k;
 for (i=0;i<DIM;i++)
     for(j=0;j<DIM;j++)
      {   C[i][j] = 0;
          for(k=0;k<DIM;k++)
          	C[i][j] = C[i][j] + A[i][k] * B[k][j];
          	for (int ii=i;ii<min(i,DIM);ii++):
          		for (int jj=j;jj<min(j,DIM);jj++){
          			sum=0;
          			for (int kk=k;kk<min(k,DIM);kk++):
          				sum+=A[ii][kk] * B[kk][jj];
          			C[]
          		}


      }
}