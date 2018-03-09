/* Assignment 10
 * Random modulo
 */
//#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max_x 0.8

double func(double x)
{
	double y = 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x;
	return y;
}

/*
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

int main(int argc, char* argv[])
{
	if (argc != 2 && argc != 3)
	{
		printf("Usage: ./a.out n [s]\n");
		return 1;
	}
	int n = atoi(argv[1]);
	if (argc == 3)
	{
		srand48((long int) atoi(argv[2]));
	}
	else
	{
		srand48((long int) time(NULL));
	}
	double *x = (double*)malloc(sizeof(double)*n);
	double *y = (double*)malloc(sizeof(double)*n);
	double *x_ = (double*)malloc(sizeof(double)*n);
	double *y_ = (double*)malloc(sizeof(double)*n);
	
	x_[0] = 0.0;

	int temp0=0, temp1=0;
	double sum =0, sum_ =0;
	for (int i=1; i<n; i++)
	{
		temp1 = (4 * temp0 + 5)%93;
		x_[i] = ((double)temp1)*0.8/94;
		temp0 = temp1;
		//printf("%lf\n", x_[i]);
	}
	for (int i = 0; i < n; i++)
	{
		y_[i] = (func(x_[i]));
		x[i] = (drand48() * max_x);
		y[i] = func(x[i]);
		sum += y[i];
		sum_ += y_[i];
	}
	
	double area = sum * 0.8/n;
	double area_ = sum_ * 0.8/n;

	printf("%lf\t%lf\n", area, area_);
	return 0;
}