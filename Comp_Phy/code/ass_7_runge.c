#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double y_slope(double x, double y, double z)
{
    double y_ = y * z + cos(x) - 0.5 * sin(2*x);
    return y_;
}
double z_slope(double x, double y, double z)
{
    double z_ = y*y + z*z - (1 + sin(x));
    return z_;
}

int main() {
	double x_initial=0, y, z, k1y, k2y, k3y, k4y, k1z, k2z, k3z, k4z, h = 0.08;
	int len = 26;

	double *x = (double*)malloc(sizeof(double)*len);
	double *y_runge = (double*)malloc(sizeof(double)*len);
	double *y_heun = (double*)malloc(sizeof(double)*len);
	double *y_euler = (double*)malloc(sizeof(double)*len);
	double *z_heun = (double*)malloc(sizeof(double)*len);
	double *z_euler = (double*)malloc(sizeof(double)*len);
	double *z_runge = (double*)malloc(sizeof(double)*len);

	x[0] = x_initial;
	for (int i=1; i < len; i++)
		x[i] = x[i-1] + h;

    for (int i = 1; i < len; i++) {
		k1y = y_slope(x[i-1], y_runge[i-1], z_runge[i-1]);
		k1z = z_slope(x[i-1], y_runge[i-1], z_runge[i-1]);

		k2y = y_slope(x[i-1] + (h * 0.5), y_runge[i-1] + k1y * (h * 0.5), z_runge[i-1] + k1z * (h * 0.5));
		k2z = z_slope(x[i-1] + (h * 0.5), y_runge[i-1] + k1y * (h * 0.5), z_runge[i-1] + k1z * (h * 0.5));

		k3y = y_slope(x[i-1] + (h * 0.5), y_runge[i-1] + k2y * (h * 0.5), z_runge[i-1] + k2z * (h * 0.5));
		k3z = z_slope(x[i-1] + (h * 0.5), y_runge[i-1] + k2y * (h * 0.5), z_runge[i-1] + k2z * (h * 0.5));

		k4y = y_slope(x[i-1] + h, y_runge[i-1] + k3y * h, z_runge[i-1] + k3z * h);
		k4z = z_slope(x[i-1] + h, y_runge[i-1] + k3y * h, z_runge[i-1] + k3z * h);

		y_runge[i] = y_runge[i-1] + (k1y + 2*k2y + 2*k3y + k4y) * h/6;
		z_runge[i] = z_runge[i-1] + (k1z + 2*k2z + 2*k3z + k4z) * h/6;
    }
    // heuns method
    for (int i=1; i<=len; i++) {
		y = y_heun[i-1] + h * y_slope(x[i-1], y_heun[i-1], z_heun[i-1]);
		z = z_heun[i-1] + h * y_slope(x[i-1], y_heun[i-1], z_heun[i-1]);
		y_heun[i] = y_heun[i-1] + ((y_slope(x[i-1], y_heun[i-1], z_heun[i-1]) + y_slope(x[i], y, z))/2)*h;
		z_heun[i] = z_heun[i-1] + ((z_slope(x[i-1], y_heun[i-1], z_heun[i-1]) + z_slope(x[i], y, z))/2)*h;
    }
    // euler method
    for (int i=1; i<=len; i++) {
        y_euler[i] = y_euler[i-1] + y_slope(x[i-1], y_euler[i-1], z_euler[i-1])*h;
        z_euler[i] = z_euler[i-1] + z_slope(x[i-1], y_euler[i-1], z_euler[i-1])*h;
    }
    printf("    x   |  y_runge  |  z_runge  |  y_euler  |  z_euler  |  y_heun  |  z_heun\n");
    for (int i=1; i<len; i++)
        printf("%lf   %lf   %lf   %lf   %lf   %lf   %lf\n", x[i], y_runge[i], z_runge[i], y_euler[i], z_euler[i], y_heun[i], z_heun[i]);
    return 0;
}
