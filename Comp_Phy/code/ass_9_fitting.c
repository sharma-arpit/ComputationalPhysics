#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define r 5
#define c 6

double *gauss_jordan(double matrix[r][c])
{
    for(int k=0; k<r; k++)
    {
        int row=k;
        for(int i=0; i<r ; i++)
        {
            if(i!=row)
            {
                float constant = matrix[i][k]/matrix[k][k];
                for (int j=k; j<c;j++)
                {
                    matrix[i][j] = matrix[i][j] - constant * matrix[k][j];
                }
            }
        }
    }
    double *a = (double*)malloc(sizeof(double)*r);
    for (int i=0; i < r; i++)
    	a[r-1-i] = matrix[i][c-1]/matrix[i][i];
return a;
}

int main(){
	double matrix[r][c];
	for (int i=0; i<r; i++){
    	for (int j=0; j<c; j++)
    		matrix[i][j] = 0;
    }
	int n = 6;
	double x[] = {0, 1, 2, 3, 4, 5};
	double y[] = {2.1, 7.7, 13.6, 27.2, 40.9, 61.1};
	for (int i=0; i < r; i++){
		for (int j=0; j < c-1; j++){
			for (int p=0; p < n; p++){
				matrix[i][j] += pow(x[p], i+j);
			}
		}
		for (int j=0; j < n; j++){
			matrix[i][c-1] += pow(x[j], i) * y[j];
		}
	}

	double *a = gauss_jordan(matrix);
	double y_fit[] = {0, 0, 0, 0, 0, 0};
	for (int i=0; i<n; i++){
		for (int j=0; j<r; j++){
			//y_fit[i] = a[0]*x[i]*x[i] + a[1]*x[i] + a[2];
			y_fit[i] += a[j]*pow(x[i], r-1-j);
		}
		printf("%lf\t%lf\t%lf\n",x[i], y[i], y_fit[i]);
	}
	for (int i=0; i<r; i++){
		printf("%lf\t", a[i]);
	}
	printf("\n");
	return 0;
}