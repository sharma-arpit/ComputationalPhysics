#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Assignment 3
 * Gauss-Seidel method
 * This is similar to the Jacobi method except
 * Using x[] itself instead of y[] while calculating new x[] (line 18)
 * Update x[] simultaneously
 */
double A[5][5], B[5];
double x[5], y[5], lambda=0.4;

double jacobi(int i, int size)
{
    double X, constant = 0.0;
    for (int j=0; j<size; j++)
    {
        if (j != i)
            constant += A[i][j] * x[j];//(lambda*x[j] + (1-lambda)*y[j]);
    }
    X = (B[i] - constant)/A[i][i];
    return X;
}

int main()
{
    int size=0;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter matrix A: ");
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
            scanf("%lf", &A[i][j]);
    }
    printf("Enter vector B: ");
    for (int i=0; i<size; i++)
        scanf("%lf", &B[i]);
    printf("Enter initial values of x: ");
    for (int i=0;i<size;i++)
    {
        scanf("%lf", &x[i]);
        y[i] = x[i];
    }
    int count = 0;
    double temp[] = {0, 0, 0, 0, 0};
    do
    {
        count = 0;
        for (int i=0; i<size; i++)
        {
            if (fabs(x[i] - temp[i]) > 0.00000001)
            {
                x[i] = jacobi(i, size);
                count++;
            }
        }
        for (int i=0; i<size; i++)
        {
            temp[i] = y[i];
            y[i] = x[i];
        }
        for (int i=0; i<size; i++)
        {
			printf("%0.5lf  ", x[i]);
		}
		printf("\n");
    }while(count != 0);
    for (int i=0; i<size; i++)
        printf("x[%d] = %0.3lf\n", i+1, x[i]);
    return 0;
}
