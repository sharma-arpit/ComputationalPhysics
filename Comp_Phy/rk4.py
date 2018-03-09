import math as m
#h = float(1/12)
#n = int(2/h)+1
n = 25
h = 1/12

x=[0]
y=[0]
z=[0]
 # y=[0 for i in range(n)]
for i in range(n):
 	x1 = i*h
 	ky1 = y[i]*z[i] + m.cos(x1)- 0.5*m.sin(2*x1)
 	kz1 = (y[i]**2)+(z[i]**2)-(1+m.sin(x1))


 	x2 = x1+(h/2.0)
 	y2 = y[i]+(ky1*h/2.0)
 	z2 = z[i] + (kz1*h/2.0)
 	ky2 = y2*z2 + m.cos(x2) - 0.5*m.sin(2*x2)
 	kz2 = ((y2)**2) + ((z2)**2) - (1+m.sin(x2))

 	x3 = x2
 	y3 = y[i]+(ky2*h/2.0)
 	z3 = z[i]+(kz2*h/2.0)
 	ky3 = y3*z3 + m.cos(x3) - 0.5*m.sin(2*x3)
 	kz3 = (y3**2)+(z3**2)-(1+m.sin(x3))

 	x4 = x1+h
 	y4 = y[i] + (ky3*h)
 	z4 = z[i] + (kz3*h)
 	ky4 = y4*z4 + m.cos(x4) - 0.5*m.sin(2*x4)
 	kz4 = (y4**2)+(z4**2)-(1+m.sin(x4))

 	ans_x = x1+h
 	ans_y = y[i] + (ky1+2*ky2+2*ky3+ky4)*h/6.0
 	ans_z = z[i] + (kz1+2*kz2+2*kz3+kz4)*h/6.0

 	x.append(ans_x)
 	y.append(ans_y)
 	z.append(ans_z)


y_heun=[0]
z_heun=[0]
x3=0.0
for i in range(1,n):###heuns method for solution
    x1=x3
    y1=y_heun[i-1]
    z1=z_heun[i-1]
    y1_slope=y1*z1+m.cos(x1)-0.5*m.sin(2*x1)
    z1_slope=y1*y1+z1*z1-(1+m.sin(x1))
    x2=x1+h
    y2=y1+h*y1_slope
    z2=z1+h*z1_slope
    y2_slope=y2*z2+m.cos(x2)-0.5*m.sin(2*x2)
    z2_slope=y2*y2+z2*z2-(1+m.sin(x2))
    y_slope=(y1_slope+y2_slope)/2
    z_slope=(z1_slope+z2_slope)/2
    y_heun.append(y1+h*y_slope)
    z_heun.append(z1+h*z_slope)
    x3=x3+h


y_euler=[0]
z_euler=[0]
x2=0.0
for i in range(1,n): ### euler mehod
    x1=x2
    y1=y_euler[i-1]
    z1=z_euler[i-1]
    y1_slope=y1*z1+m.cos(x1)-0.5*m.sin(2*x1)
    z1_slope=y1*y1+z1*z1-(1+m.sin(x1))
    y_euler.append(y1+h*y1_slope)
    z_euler.append(z1+h*z1_slope)
    x2=x2+h

for i in range(0,n):
    print("%.15lf\t%.15lf\t%.15lf\t%.15lf\t%.15lf\t%.15lf\t%.15lf"%(x[i], y[i], z[i], y_heun[i],z_heun[i], y_euler[i], z_euler[i]))
