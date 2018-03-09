/* Assignment 10
 * Multiple trapezoidal rule
 */

#include <stdio.h>
#include <math.h>

#define step 0.000008
#define points 100001

double func(double x)
{
	double y = 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x;
	return y;
}

int main()
{
	double x[points];
	double y[points];
	x[0] = 0.0;
	y[0] = func(x[0]);
	for (int i=1; i<points; i++)
	{
		x[i] = x[i-1] + step;
		y[i] = func(x[i]);
	}

	double area =0;
	for (int i=1; i<points; i++)
		area += step * (y[i]+y[i-1])/2;
	
	printf("%lf\n", area);
	return 0;
}