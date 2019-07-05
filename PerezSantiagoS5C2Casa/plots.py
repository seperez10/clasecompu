import numpy as np
import matplotlib.pyplot as plt


datos= np.genfromtxt("datos.dat", delimiter= ",")
datos1= np.genfromtxt("datos1.dat", delimiter= ",")
datos2= np.genfromtxt("datos2.dat", delimiter= ",")

X= datos[:,0]
Y=datos[:,1]
x1= datos1[:,0]
y1=datos1[:,1]
x2= datos2[:,0]
y2=datos2[:,1]

plt.figure()
plt.plot(X,Y, label= "Euler")
plt.plot(x1,y1, label= "RungeKutta")
plt.plot(x2,y2, label= "Leapfrog")
plt.xlabel("X")
plt.ylabel("y(x)")
plt.title("ODE")
plt.legend()
plt.savefig("plotsS5C2")