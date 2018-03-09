#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n=30;
double rng=10.0;

double funcT(double x,double y,double z)
{
	return z;
}

double funcZ(double x,double t,double z)
{
	return -0.01*(20.0-t);
}

double** rk4(double y0,double z0)
{
	int i=0,j=0,k=0;
	double h=rng/n;
	double c[2][4];
	double **y;
	y=(double**)calloc(2,sizeof(double));
	y[0]=(double *)calloc(n+1,sizeof(double));
	y[1]=(double *)calloc(n+1,sizeof(double));
	y[0][0]=y0;
	y[1][0]=z0;
	for(i=0;i<n;++i)
	{
		c[0][0]=h*funcT(i*h,y[0][i],y[1][i]);
		c[1][0]=h*funcZ(i*h,y[0][i],y[1][i]);
	   
		c[0][1]=h*funcT(i*h+h/2,y[0][i]+c[0][0]/2,y[1][i]+c[1][0]/2);
		c[1][1]=h*funcZ(i*h+h/2,y[0][i]+c[0][0]/2,y[1][i]+c[1][0]/2);
	   
		c[0][2]=h*funcT(i*h+h/2,y[0][i]+c[0][1]/2,y[1][i]+c[1][1]/2);
		c[1][2]=h*funcZ(i*h+h/2,y[0][i]+c[0][1]/2,y[1][i]+c[1][1]/2);
	   
		c[0][3]=h*funcT(i*h+h,y[0][i]+c[0][2],y[1][i]+c[1][2]);
		c[1][3]=h*funcZ(i*h+h,y[0][i]+c[0][2],y[1][i]+c[1][2]);
	   
		y[0][i+1]=y[0][i]+(c[0][0]+2*c[0][1]+2*c[0][2]+c[0][3])/6;
		y[1][i+1]=y[1][i]+(c[1][0]+2*c[1][1]+2*c[1][2]+c[1][3])/6;
	}
	 return y;
}

int main()
{
	int i=0;
	double **T,Ta=20.00,h=0.01, dx=10/n,del[2],x[2],inc=0.1;
	T=(double**)calloc(2,sizeof(double));
	T[0]=(double*)calloc(n+1,sizeof(double));
	T[1]=(double*)calloc(n+1,sizeof(double));
	T[0][0]=40;
	T[1][0]=20.00;
	del[1]=0.0;
	del[0]=0.0;
	T=rk4(T[0][0],T[1][0]); 
	del[1]=T[0][n]-200.0;

	do
	{
		del[0]=del[1];
		x[0]=x[1];
		T=rk4(T[0][0],T[1][0]); 
		del[1]=T[0][n]-200.0;
		  
		if(del[0]*del[1]<0)
		{

		 //inc=inc/10;
			break;
		}   

		if(del[1]>0)
		{
			T[1][0]=T[1][0]-inc;
			x[1]=T[1][0];  
		}
		  
		if(del[1]<0)
		{
		   T[1][0]=T[1][0]+inc;
		   x[1]=T[1][0];
		}
		printf("%lf\n",del[1]);
	}while(fabs(T[0][n]-200)>pow(10,-9));
 
	T[1][0]=x[0]+(inc)*(del[1])/(del[1]-del[0]);
	T=rk4(T[0][0],T[1][0]);

	printf("%lf\n",T[0][n]-200.0);
	for(i=0;i<=n;i++)
	{
		printf("%lf\n",T[0][i]);
	}

return 0;
}