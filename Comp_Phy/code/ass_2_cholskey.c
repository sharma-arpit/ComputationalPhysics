/* Assignment 2
 * Cholskey method
 */
#include <stdio.h>
#include <math.h>

// multiply L and LT to give initial matrix back

void multiply(int r, double L[][5], double LT[][5])
{
	double A[5][5];
    for (int i=0; i<r;i++)
    {
        for (int j=0;j<r;j++)
        {
            for (int k=0; k<r; k++)
                A[i][j] += L[i][k] * LT[k][j];
        }
    }
// prints initial matrix
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<r; j++)
            printf("%f\t", A[i][j]);
        
        printf("\n");
    }
}

int main()
{
	double matrix[5][5], L[5][5], LT[5][5], sum=0, s=0;
	int r;
	scanf("%d", &r);
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<r;j++)
			scanf("%lf", &matrix[i][j]);
	}
// logic for L matrix
	for (int k=0;k<r;k++)
	{
		for (int j=0;j<=k;j++)
		{
			if(k==j)
			{
				sum = 0;
				for (int i=0;i<k;i++)
				{
					sum += L[k][i]*L[k][i];
				}
				L[k][j] = sqrt(matrix[k][j] - sum);
			}
			else
			{
				s = 0;
				for (int i=0;i<j;i++)
				{
					s += L[k][i]*L[j][i];
				}
				L[k][j] = (matrix[k][j] - s)/L[j][j];
			}
		}
	}
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<r;j++)
		{
			printf("%lf\t", L[i][j]);
			LT[j][i] = L[i][j];
		}
		printf("\n");
	}
	multiply(r, L, LT);
	
	return 0;
}
