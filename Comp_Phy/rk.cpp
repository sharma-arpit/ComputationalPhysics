#include<bits/stdc++.h>

using namespace std;
  double fy(double x,double y,double z)
     {
             double c=y*z+cos(x)-0.5*sin(2*x);
   // cout<<cos(x)<<" x "<<x<<endl;
 //cout<<c<<"c"<<endl;
              return c;
      }

    double fz(double x,double y,double z){
 // cout<<x<<" "<<y<<" "<<z<<endl;
              double c=y*y+z*z-(1+sin(x));
               return c;
      }
           int main(){
                int n=26;
                double x[n],y[n],z[n],ky1,ky2,ky3,ky4,kz1,kz2,kz3,kz4;
                x[0]=0;
                y[0]=0;
                z[0]=0;
                double h;
                h=0.08;
                cout<<"h="<<setprecision(8)<<h<<endl;
                for(int i=1;i<=25;i++)
                {
                        x[i]=x[i-1]+h;
						ky1=ky2=ky3=ky4=kz1=kz2=kz3=kz4=0;
                        ky1=fy(x[i-1],y[i-1],z[i-1]);
                        kz1=fz(x[i-1],y[i-1],z[i-1]);
//cout<<ky1<<endl;
                        ky2=fy(x[i-1]+0.5*h,y[i-1]+0.5*ky1*h,z[i-1]+0.5*kz1*h);
                        kz2=fz(x[i-1]+0.5*h,y[i-1]+0.5*ky1*h,z[i-1]+0.5*kz1*h);
 //cout<<"ky2="<<ky2<<" "<<endl;
                        ky3=fy(x[i-1]+0.5*h,y[i-1]+0.5*ky2*h,z[i-1]+0.5*kz2*h);
                        kz3=fz(x[i-1]+0.5*h,y[i-1]+0.5*ky2*h,z[i-1]+0.5*kz2*h);
  //cout<<ky3<<"ky3"<<endl;
   
                         ky4=fy(x[i-1]+h,y[i-1]+ky3*h,z[i-1]+kz3*h);
                         kz4=fz(x[i-1]+h,y[i-1]+ky3*h,z[i-1]+kz3*h);
//                       cout<<endl;
  //cout<<ky4<<" ky4"<<endl;
                       y[i]=y[i-1]+(ky1+2*ky2+2*ky3+ky4)*h/6;
//cout<<y[i-1]+1/6*(ky1+2*ky2+2*ky3+ky4)<<endl;
//cout<<y[i]<<endl;

//kz1=fz(x[i-1],y[i-1],z[i-1]);
  //cout<<kz1<<" kz1"<<endl;
      

                       z[i]=z[i-1]+(kz1+2*kz2+2*kz3+kz4)*h/6;
//cout<<kz2<<" kz2"<<endl;cout<<kz3<<" kz3"<<endl;cout<<kz4<<" kz4"<<endl;


}
                       for(int i=0;i<=25;i++){
                            cout<<y[i]<<" "<<z[i]<<" "<<x[i]<<endl;

                                 }


return 0;

}