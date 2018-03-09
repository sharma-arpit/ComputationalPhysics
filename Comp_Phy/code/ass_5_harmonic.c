/* Assignment 5
 * Calculating Eigenvalues of H (H = H_o + lambda * x^4)
 * Using Jacobi method (Rotation)
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define size 5
double x[size][size];

void multiply(double L[][size], double LT[][size])
{
	double y[size][size];
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			y[i][j] = 0;
			for (int k=0; k<size; k++)
				y[i][j] += L[i][k] * LT[k][j];
		}
	}
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
			x[i][j] = y[i][j];
	}
}

int main()
{
	int p, q, sign, n=0;
	double H[size][size], lambda=0.0, eigen[size], D[size][size], H_old[size][size], H_o[size][size], x_o[size][size], theta, C, S, T, largest=0.0;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			if (j==i+1)
				x_o[i][j] = sqrt(j)/sqrt(2);
			else if (i == j+1)
				x_o[i][j] = sqrt(i)/sqrt(2);
			else if (i == j)
			{
				H_o[i][j] = i+0.5;
				x_o[i][j] = 0;
			}
			else
				x_o[i][j] = 0;
		}
	}
	multiply(x_o, x_o);
	multiply(x, x);
	for (lambda = 0.0; lambda <=1; lambda+=0.1)
	{
		n=0;
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{

				H[i][j] = H_o[i][j] + lambda*x[i][j];
				H_old[i][j] = H[i][j];
				D[i][j] = H[i][j];
			}
		}
		do
		{
			for (int i=0; i<size; i++)
			{
				for (int j=0; j<size; j++)
				{
					if((fabs(H[i][j]) > 0.0000001) && (i!=j))
					{
						p=i;
						q=j;
						theta = (H[q][q] - H[p][p])/(2*H[p][q]);
						sign = fabs(theta)/theta;
						T = sign/(fabs(theta) + sqrt(theta*theta + 1));
						C = 1/sqrt(1 + T*T);
						S = C*T;
						D[p][p] = C*C*H[p][p] + S*S*H[q][q] - 2*C*S*H[p][q];
						D[q][q] = S*S*H[p][p] + C*C*H[q][q] + 2*C*S*H[p][q];
						D[p][q] = 0;
						D[q][p] = 0;
						for (int k=0; k<size; k++)
						{
							if ((k != p) && (k != q))
							{

								D[k][p] = C*H[k][p] - S*H[k][q];
								D[p][k] = D[k][p];
								D[k][q] = S*H[k][p] + C*H[k][q];
								D[q][k] = D[k][q];
							}
						}
						for (int i=0; i<size; i++)
						{
							for (int j=0; j<size; j++)
								H[i][j] = D[i][j];
						}
					}
				}
			}
			largest = 0.0;
			for (int i=0; i<size; i++)
			{
				for (int j=0; j<size; j++)
				{
					if ((largest < fabs(H[i][j])) && (i!=j))
						largest = fabs(H[i][j]);
				}
			}
		n++;
		}while(largest>0.0000001);
		printf("%0.1lf ", lambda);
		for (int i=0; i<size; i++)
		{
			eigen[i] = D[i][i];
		}
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size-i-1; j++)
			{
				if (eigen[j] > eigen[j+1])
				{
					double temp = eigen[j];
					eigen[j] = eigen[j+1];
					eigen[j+1] = temp;
				}
			}
		}
		for (int i=0 ;i<size; i++)
		{
			printf("%lf ", eigen[i]);
		}
		printf("\n");
	}
	return 0;
}