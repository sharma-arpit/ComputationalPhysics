#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;
const int n=5;
double x_new[5][5];

ofstream fp ("graph.txt");

void mult(double arr1[][5],double arr2[][5])
{
	double y[5][5];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	y[i][j]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				y[i][j]+=arr1[i][k]*arr2[k][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				x_new[i][j]=y[i][j];
			}
		}
	}
}
int main()
{

	double h[n][n];
	double x[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	h[i][j]=0.0;

	for(int i=0;i<n;i++)
		h[i][i]=(double)(((2*i)+1)/2.0);
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  x[i][j]=0;

	for(int i=0;i<n;i++)
	{
		x[i][i+1]=sqrt(i+1)/sqrt(2);
		x[i+1][i]=sqrt(i+1)/sqrt(2);
	}
	printf("\nx  matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{cout<<x[i][j]<<"  ";}
		cout<<endl;
	}
	mult(x,x);
	printf("\nx^2  matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{cout<<x_new[i][j]<<"  ";}
		cout<<endl;
	}
	cout<<endl<<endl;
	mult(x_new,x);
	printf("\nx^3  matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{cout<<x_new[i][j]<<"  ";}
		cout<<endl;
	}
	cout<<endl<<endl;
	mult(x_new,x);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{cout<<x_new[i][j]<<"  ";}
		cout<<endl;
	}
	cout<<endl<<endl;
	double lambda=0;
	double h1[n][n];
	double d[n][n];

  cout<<endl<<endl;
	lambda=0;
	for(lambda=0;lambda<=1;lambda+=0.1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				h1[i][j]=h[i][j]+(lambda*x_new[i][j]);
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=h1[i][j];

/*		cout<<"H1="<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{cout<<h1[i][j]<<" ";}
			cout<<endl;
		}
*/        cout<<endl<<endl;
		int count=0;
		while(count<30)
		{
			double max=0;
			int p=0,q=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j!=i)
					{
						if(fabs(h1[i][j])>max)
						{
							max=fabs(h1[i][j]);
							p=i;q=j;
						}
					}
				}
			}

			if(max<=0.0000001)
			break;
			double theta=(h1[q][q]-h1[p][p])/(2*h1[p][q]);
			double t;

			if(theta>=0)
			t=(1/(fabs(theta)+sqrt(theta*theta+1)));
			else
			{t=-(1/(fabs(theta)+sqrt(theta*theta+1)));}

			double c=sqrt(1/(1+t*t));
			double s=c*t;

			d[p][p]=(c*c*h1[p][p])+(s*s*h1[q][q])-(2*c*s*h1[p][q]);
			d[q][q]=(s*s*h1[p][p])+(c*c*h1[q][q])+(2*c*s*h1[p][q]);
			d[p][q]=0;d[q][p]=0;
			for(int j=0;j<n;j++)
			{
				if(j!=p && j!=q)
				{	d[j][p]=(c*h1[j][p])-(s*h1[j][q]);
					d[p][j]=d[j][p];
					d[j][q]=(c*h1[j][q])+(s*h1[j][p]);
					d[q][j]=d[j][q];
				}
			}

			for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				h1[i][j]=d[i][j];
			count+=1;
			
/*		cout<<endl<<"count="<<count<<endl;
      		for(int i=0;i<n;i++)
  		{
  		for(int j=0;j<n;j++)
  		{cout<<h1[i][j]<<"\t";}
  		cout<<endl;
  		}
      		cout<<endl;
		}
*/		

	
	}
	double arr[n];
	for(int i=0;i<n;i++)
	arr[i]=h1[i][i];
	double temp=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	cout<<lambda<<" ";
	fp<<lambda<<" ";
		for(int i=0;i<n;i++)
		{
      			cout<<arr[i]<<" ";
			fp<<arr[i]<<" ";
		}
		cout<<endl;
		fp<<endl;
	}


	
	
	fp.close();
	return 0;
}