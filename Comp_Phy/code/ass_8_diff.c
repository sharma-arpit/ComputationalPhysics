#include <stdio.h>
#include <stdlib.h>

# define step 0.5

// T[0] and T[10] are known

void gauss_jordan(double *matrix, double *x, int r, int c)
{
    for(int k=0; k<r; k++)
    {
        int row=k;
        for(int i=0; i<r ; i++)
        {
            if(i!=row)
            {
                float constant = *((matrix + c * i) + k)/(*((matrix + c * k) + k));
                for (int j=k; j<c;j++)
                {
                    *((matrix + c * i) + j) = *((matrix + c * i) + j) - constant * *((matrix + c * k) + j);
                }
            }
        }
    }
	printf("\n");
	printf("    x    |    T   \n");
    for (int i=0; i<r;i++)
        printf("%0.6lf   %0.6lf\n", x[i+1], *((matrix + c * i) + c-1)/(*((matrix + c * i) + i)));
    printf("\n");
}

int main(){
	int len = (10/step) + 1; // T[0] to T[10] 11 elements are there
	double h = step, h_ = 0.01, Ta = 20, T_initial = 40, T_final = 200;
	double *x = (double*) malloc(sizeof(double) * len);
	double *T_matrix = (double*)malloc(sizeof(double)*(len-2)*(len-1)); // we need to calculate T[1] to T[9] 9 elements

	x[0] = 0;
	for (int i=1; i<len; i++){
		x[i] = x[i-1] + h;
	}

	double k = 2 + h_ * h * h;
	double ka = h_ * h * h * Ta;
	for (int i = 0; i < len-2; i++) {
		// calculate T_matrix
		*((T_matrix + (len-1)*i) + i) = k;
		if (i > 0 && i < len-3){
			*((T_matrix + (len-1)*i) + i-1) = -1;
			*((T_matrix + (len-1)*i) + i+1) = -1;
		}
		else if (i == 0)
			*((T_matrix + (len-1)*i) + i+1) = -1;
		else if (i == len-3)
			*((T_matrix + (len-1)*i) + i-1) = -1;
		// calculate T_a
		if (i > 0 && i < len-3)
			*((T_matrix + (len-1)*i) + len-2) = ka;
		else if (i == 0)
			*((T_matrix + (len-1)*i) + len-2) = T_initial + ka;
		else if (i == len-3)
			*((T_matrix + (len-1)*i) + len-2) = T_final + ka;
	}
	for (int i=0; i <len-2; i++){
		for (int j=0; j<len-1; j++){
			printf("%0.3lf  ", *((T_matrix + (len-1)*i) + j));
		}
		printf("\n");
	}
	gauss_jordan(T_matrix, x, len-2, len-1);
return 0;
}
