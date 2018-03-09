/* Assignment 2
 * LU decomposition
 */

#include <stdio.h>
double X[5], Y[5], B[5], Inverse[5][5];

void back_subs(int r, double matrix[][5], double L[][5])
{
	int i=0, k=0;
    double constant=0.0;
// forward substitution
    for (i=0;i<=r-1;i++)
    {
        constant=0.0;
        for (k=0;k<=i-1;k++)
        {
            constant += L[i][k]*Y[k];
        }
        Y[i] = (B[i] - constant)/L[i][i];
    }
// back substitution on U
    for (i=r-1;i>=0;i--)
    {
        constant=0.0;
        for (k=r-1;k>=i+1;k--)
        {
            constant += matrix[i][k]*X[k];
        }
        X[i] = (Y[i] - constant)/matrix[i][i];
    }
}
void elimination(double matrix[][5], double L[][5], int r, int c)
{
// upper triangular matrix
    for(int k=0; k<r; k++)
    {
        int row=k;
        for(int i=0; i<r ; i++)
        {
            if(i>row)
            {
                L[i][k] = matrix[i][k]/matrix[k][k];
                for (int j=k; j<c-1;j++)
                {
                    matrix[i][j] = matrix[i][j] - L[i][k] * matrix[k][j];
                }
            }
        }
    }
// lower triangular matrix
    for (int i=0;i<r;i++)
	{
		for (int j=0;j<r;j++)
		{
			if (i==j)
				L[i][j] = 1;
			else if (i<j)
				L[i][j] = 0;
		}
	}
//prints both matrix
	for (int i=0; i<r; i++)
    {
        for (int j=0; j<r; j++)
            printf("%lf\t", L[i][j]);
        
        printf("\n");
    }
    printf("\n");
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<r; j++)
            printf("%lf\t", matrix[i][j]);
        
        printf("\n");
    }
    
    back_subs(r, matrix, L);
// prints solution
    for (int i=0;i<r;i++)
        printf("X[%d] = %lf\n", i+1, X[i]);
}

int main()
{
	double matrix[5][5], L[5][5];
    int i=0, j=0, k=0, r;
    printf("Enter size: ");
    scanf("%d", &r);
    int c=r+1;
    for (i=0;i<r;i++)  // input matrix
    {
        for (j=0;j<r;j++)
            scanf("%lf", &matrix[i][j]);
    }
    printf("\n");
    for (i=0;i<r;i++)  // input vector
		scanf("%lf", &B[i]);
	
    
    elimination(matrix, L, r, c);
    
    double I[5][5];
// identity matrix
    for (i=0;i<r;i++)
	{
		for (j=0;j<r;j++)
		{
			if (i!=j)
				I[i][j] = 0;
			else
				I[i][j] = 1;
		}
	}
// computing inverse
	for (i=0;i<r;i++)
	{
		for (j=0;j<r;j++)
		{
			B[j] = I[j][i];
		}
		back_subs(r, matrix, L);
		for(k=0;k<r;k++)
		{
			Inverse[k][i] = X[k];
		}
	}
// prints Inverse
	for(i=0;i<r;i++)
	{
		for (j=0;j<r;j++)
			printf("%lf\t", Inverse[i][j]);
		printf("\n");
	}
    return 0;
}
