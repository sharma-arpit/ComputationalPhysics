/* Assignment 4
 * Power method to find the maximum and minimum eigen values for a given matrix
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define r 10

double X1[r], X2[r], A[r][r], AI[r][r], X3[r], X4[r];

void mul(double a[][r], double x1[r], double x2[r], int size)
{
	for (int i=0; i<size;i++)
	{
		for (int k=0; k<size; k++)
			x2[i] += a[i][k] * x1[k];
	}
}
int main()
{
	double eigen1=0.0, eigen2=1.0, matrix[r][2*r];
	double eigen3=0.0, eigen4=1.0;
	int size=0;
	scanf("%d", &size);
	// input augmented matrix (3x6)
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size+size; j++)
		{
			if (j<size)
			{
				scanf("%lf", &matrix[i][j]);
				A[i][j] = matrix[i][j];
			}
			else
			{
				if (i == j-size)
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
		}	
	}
	// computing AI (inverse)
	double constant=0.0;
	int row=0;
	for(int k=0; k<size; k++)
	{
		row=k;
		for(int i=0; i<size; i++)
		{
			if(i!=row)
			{
				constant = matrix[i][k]/matrix[k][k];
				for (int j=k; j<size+size; j++)
				{
					matrix[i][j] = matrix[i][j] - constant * matrix[k][j];
				}
			}
		}
	}
	for (int i=0; i<size; i++)
	{
		for (int j=size; j<size+size;j++)
			AI[i][j-size] = matrix[i][j]/matrix[i][i];
	}
	for (int i=0; i<size; i++)
	{
		X2[i] = 0.0;
		scanf("%lf", &X1[i]);
		X4[i] = 0.0;
		scanf("%lf", &X3[i]);
	}
	int n=0;
	do
	{
		eigen1 = eigen2;
		eigen3 = eigen4;
		mul(A, X1, X2, size);
		mul(AI, X3, X4, size);
		eigen2 = fabs(X2[0]);
		eigen4 = fabs(X4[0]);
		for (int i=0; i<size; i++)
		{
			if (eigen2 < fabs(X2[i]))
			eigen2 = X2[i];
			if (eigen4 < fabs(X4[i]))
			eigen4 = X4[i];
		}
		for (int i=0; i<size; i++)
		{
			X1[i] = X2[i]/eigen2;
			X3[i] = X4[i]/eigen4;
		}
		n++;
		for (int i=0; i<size; i++)
		{
			X2[i] = 0.0;
			X4[i] = 0.0;
		}
		printf("%d ->  %0.9lf  %0.9lf\n", n, eigen2, 1/eigen4);
	}while((fabs(eigen1 - eigen2) > 0.000000001) || (fabs(1/eigen3 - 1/eigen4) > 0.0000001));
return 0;
}
