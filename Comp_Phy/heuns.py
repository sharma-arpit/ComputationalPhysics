#import numpy as np

def heun(x1,y0):
    h=0.5   
    x=x1-h
    y1=-2*x**3+12*x**2-20*x+8.5
    x=x1
    y2=-2*x**3+12*x**2-20*x+8.5
    y=(y1+y2)/2
    yout=y0+h*y
    return yout
    
    
def euler(x1,y0):
     h=0.5
     x=x1-h
     y1=-2*x**3+12*x**2-20*x+8.5
     yout=y0+h*y1
     return yout
    
y_heun=[1]
x=[0, .5, 1, 1.5, 2, 2.5, 3, 3.5, 4]
z=[1, 2,  3,  4,   5, 6,  7,  8,   9]
for i in range(1,9):
      y_heun.append(heun(x[i],y_heun[i-1]))
      
####print(y_heun)
 
y_euler=[1]
for i in range(1,9):
      y_euler.append(euler(x[i],y_euler[i-1]))
      
###print(y_euler)

y_actual=[1]

##y=-0.5*x1**4+4*x1**3-10*x1**2+8.85*x1+1
for i in range(1,9):
     x1=x[i]
     y=-0.5*x1**4+4*x1**3-10*x1**2+8.5*x1+1
     y_actual.append(y)

##print(y_actual)
#y_actual1=np.array(y_actual)
#y_euler1=np.array(y_euler)
#y_heun1=np.array(y_heun)
error_euler=[]
error_heun=[]

for i in range(0,9):
    error_euler.append(((-y_actual[i]+y_euler[i])*100)/(y_actual[i]))
    error_heun.append(((-y_actual[i]+y_heun[i])*100)/(y_actual[i]))
    
###print(error_euler)
####print(error_heun)
 
print("value_x\t\t\tvalue_actual\t\tvalue_heun\t\theun_error\t\tvalue_euler\t\teuler_error")
for i in range(0,9):
   print("%.6lf\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\t%.6lf" %(float(x[i]),float(y_actual[i]),float(y_heun[i]),float(error_heun[i]),float(y_euler[i]),float(error_euler[i])))

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
