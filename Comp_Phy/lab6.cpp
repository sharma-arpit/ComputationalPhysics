#include<iostream>
#include<fstream>
using namespace std;
ofstream fp("aditya.txt");
float pow(float x,int y)
{
    int i;float sum=1,sumx;
    {
        for(i=0;i<y;i++)
         {
             sum=sum*x;
         }
    sumx=sum;
    }
    return sumx;
}
int main()
{
    int x,i;
    float arry1[20],y1[20],y[20],Y1[20],X[20],A[20],euler[20],errhm[20],erreu[20];//exact=X;Y1=average derivative,hm=heun ans,arry1=dy/dx
    float k,m,j=0,n=0;
    float em[20],hm[20];
    float h=0.5;
    //huens method
    for(x=0;x<9;x++)
    {
         arry1[x]=((-2*(pow(j,3))+12*(pow(j,2)))-20*(j)+8.5);
         j+=0.5;
    }
    X[0]=0;
    A[0]=euler[0]=hm[0]=y[0]=1;
    for(x=1;x<=8;x++)
    {   y[0]=1;
        y[x]=y[x-1]+arry1[x-1]*h;
        Y1[x]=(arry1[x]+ arry1[x-1])/2;
        y[x]=hm[x-1]+Y1[x]*h;
        hm[x]=y[x];
    }
    m=0;
    for(x=0;x<=8;x++)
    {
    cout<<"hm("<<m<<")="<<hm[x]<<endl;
    m+=0.5;
    }
    //euler method
    for(x=1;x<=8;x++)
    {   A[0]=1;
        A[x]=A[x-1]+arry1[x-1]*h;
        euler[x]=A[x];
    }
    k=0;
    for(x=1;x<=8;x++)
    {
    k+=0.5;
    cout<<"Euler X["<<k<<"]"<<euler[x]<<endl;
    }
    float z=0;
    for(x=1;x<=8;x++)
    {
    z+=0.5;
    X[x]=-0.5*(pow(z,4))+4*(pow(z,3))-10*(pow(z,2))+8.5*z+1;
    cout<<"Exact X["<<z<<"]"<<X[x]<<endl;
    }
    for(x=1;x<=8;x++)
    {
    errhm[x]=(hm[x]-X[x])*100/X[x];
    erreu[x]=(euler[x]-X[x])*100/X[x];
    }
    //output to file
    for(x=1;x<=8;x++)
    {
        n+=0.5;
        fp<<n<<" "<<X[x]<<" "<<hm[x]<<" "<<errhm[x]<<" "<<euler[x]<<" "<<erreu[x]<<endl;
        cout<<n<<" "<<X[x]<<" "<<hm[x]<<" "<<errhm[x]<<" "<<euler[x]<<" "<<erreu[x]<<endl;
    }
	fp.close();
}
