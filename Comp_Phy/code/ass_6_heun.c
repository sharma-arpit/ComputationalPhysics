#include<stdio.h>
#include<stdlib.h>

# define data_points 400
# define step_size 0.01

double slope(double x)
{
	double s = -2*x*x*x + 12*x*x - 20*x +8.5;
	return s;
}

int main()
{
	double h=step_size, x_initial=0.0;
	int len = data_points;
	double *x = (double*)malloc(sizeof(double)*len);
	double *y_heun = (double*)malloc(sizeof(double)*len);
	double *y_euler = (double*)malloc(sizeof(double)*len);
	double *y_exact = (double*)malloc(sizeof(double)*len);
	double *error_euler = (double*)malloc(sizeof(double)*len);
	double *error_heun = (double*)malloc(sizeof(double)*len);

	x[0] = x_initial;
	for (int i=1; i<=len; i++)
		x[i] = x[i-1] + h;

	for (int i=0; i<=len; i++)
		y_exact[i] = -0.5*x[i]*x[i]*x[i]*x[i] + 4*x[i]*x[i]*x[i] - 10*x[i]*x[i] + 8.5*x[i] + 1;

	y_euler[0] = 1.0;
	y_heun[0] = 1.0;
	// heuns method
	for (int i=1; i<=len; i++)
		y_heun[i] = y_heun[i-1] + ((slope(x[i-1]) + slope(x[i]))/2)*h;

	// euler method
	for (int i=1; i<=len; i++)
		y_euler[i] = y_euler[i-1] + slope(x[i-1])*h;

	printf("|   x   | y_exact | y_heun  | heun_err | y_euler | euler_err |\n");
	for (int i=0; i<=len; i++)
	{
		error_euler[i] = 100*(y_euler[i] - y_exact[i])/y_exact[i];
		error_heun[i] = 100*(y_heun[i] - y_exact[i])/y_exact[i];
		printf("%8.6lf  %8.6lf  %8.6lf  %8.6lf  %8.6lf  %8.6lf \n", x[i], y_exact[i], y_heun[i], error_heun[i], y_euler[i], error_euler[i]);
	}

	return 0;
}
