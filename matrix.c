#include <stdio.h>

int matrix(int a[][], int b[][], int c[][], int aa, int bb, int cc){

	for (i = 0; i < aa; ++i)
    	for (j = 0; j < cc; ++j)
        	for (k = 0; k < bb; ++k)
            	c[i][j] += a[i][k] * b[k][j];
            printf(c[i][j]);
}

int main(int ac, char **av){
	aa = 2;
	bb = 4; 
	cc = 3;
	int a[aa][bb]={{1,2,3,4};{5,6,7,8}};
	int b[bb][cc]={{1,2,3};{4,5,6};{7,8,9};{10,11,12}};
	int c[aa][cc];
	matrix(a,b,c);
}