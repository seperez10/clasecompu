import numpy as np
import matplotlib.pyplot as plt



datosEuler1= np.genfromtxt("datoseuler1.dat", delimiter= ",")
datosleap1= np.genfromtxt("datosleap1.dat", delimiter= ",")
datosR1= np.genfromtxt("datosRunge.dat", delimiter= ",")

x= datosEuler1[:,0]
y= datosEuler1[:,1]
xL= datosleap1[:,0]
yL= datosleap1[:,1]
xR= datosR1[:,0]
yR= datosR1[:,1]


plt.figure()
plt.subplot(131)
plt.plot(x,y, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler")
plt.subplot(132)
plt.plot(xL,yL, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog")
plt.subplot(133)
plt.plot(xR,yR, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta")
plt.savefig("Graficas")