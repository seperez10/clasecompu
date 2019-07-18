import numpy as np
import matplotlib.pyplot as plt



datosEuler1= np.genfromtxt("datoseuler1.dat", delimiter= ",")
datosleap1= np.genfromtxt("datosleap1.dat", delimiter= ",")

datosEuler2= np.genfromtxt("datoseuler2.dat", delimiter= ",")
datosleap2= np.genfromtxt("datosleap2.dat", delimiter= ",")

datosEuler3= np.genfromtxt("datoseuler3.dat", delimiter= ",")
datosleap3= np.genfromtxt("datosleap3.dat", delimiter= ",")

datosR1= np.genfromtxt("datosRunge.dat", delimiter= ",")
datosR2= np.genfromtxt("datosRunge2.dat", delimiter= ",")
datosR3= np.genfromtxt("datosRunge3.dat", delimiter= ",")

x= datosEuler1[:,0]
y= datosEuler1[:,1]
xL= datosleap1[:,0]
yL= datosleap1[:,1]
x2= datosEuler2[:,0]
y2= datosEuler2[:,1]
xL2= datosleap2[:,0]
yL2= datosleap2[:,1]
x3= datosEuler3[:,0]
y3= datosEuler3[:,1]
xL3= datosleap3[:,0]
yL3= datosleap3[:,1]
xR= datosR1[:,0]
yR= datosR1[:,1]
xR2= datosR2[:,0]
yR2= datosR2[:,1]
xR3= datosR3[:,0]
yR3= datosR3[:,1]

tiempo=datosEuler1[:,2]
energE1=datosEuler1[:,3]
energL1=datosleap1[:,2]

tiempo2=datosEuler2[:,2]
energE2=datosEuler2[:,3]
energL2=datosleap2[:,2]

tiempo3=datosEuler3[:,2]
energE3=datosEuler3[:,3]
energL3=datosleap3[:,2]




plt.figure()
plt.subplot(331)
plt.plot(x,y, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler con sigma 0.02")
plt.subplot(332)
plt.plot(xL,yL, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog con sigma 0.02")
plt.subplot(334)
plt.plot(x2,y2, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler con 0.001")
plt.subplot(335)
plt.plot(xL2,yL2, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog con sigma 0.001")
plt.subplot(337)
plt.plot(x3,y3, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler con sigma 0.0015")
plt.subplot(338)
plt.plot(xL3,yL3, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog con sigma 0.0015")
plt.subplot(333)
plt.plot(xR,yR, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta con dt 0.02")
plt.subplot(336)
plt.plot(xR2,yR2, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta con dt 0.001")
plt.subplot(339)
plt.plot(xR3,yR3, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta con dt 0.0015")

plt.savefig("Graficas")



plt.figure()
plt.subplot(331)
plt.plot(tiempo,energE1)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Energia Euler1")
plt.subplot(332)
plt.plot(tiempo,energL1)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Energia Leap1")
plt.subplot(334)
plt.plot(tiempo2,energE2)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Energia Euler2")
plt.subplot(335)
plt.plot(tiempo2,energL2)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Energia Leap2")
plt.subplot(337)
plt.plot(tiempo3,energE3)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Energia Euler3")
plt.subplot(338)
plt.plot(tiempo3,energL3)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Energia Leap3")
plt.savefig("Energia")
