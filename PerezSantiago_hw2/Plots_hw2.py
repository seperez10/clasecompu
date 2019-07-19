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
energR1=datosR1[:,2]

tiempo2=datosEuler2[:,2]
energE2=datosEuler2[:,3]
energL2=datosleap2[:,2]
energR2=datosR2[:,2]

tiempo3=datosEuler3[:,2]
energE3=datosEuler3[:,3]
energL3=datosleap3[:,2]
energR3=datosR3[:,2]


momentoE1= datosEuler1[:,4]
momentoE2= datosEuler2[:,4]
momentoE3= datosEuler3[:,4]
momentoL1= datosleap1[:,3]
momentoL2= datosleap2[:,3]
momentoL3= datosleap3[:,3]
momentoR1= datosR1[:,3]
momentoR2= datosR2[:,3]
momentoR3= datosR3[:,3]

veloxE1= datosEuler1[:,5]
veloxE2= datosEuler2[:,5]
veloxE3= datosEuler3[:,5]
veloxL1= datosleap1[:,4]
veloxL2= datosleap2[:,4]
veloxL3= datosleap3[:,4]
veloxR1= datosR1[:,4]
veloxR2= datosR2[:,4]
veloxR3= datosR3[:,4]

veloyE1= datosEuler1[:,6]
veloyE2= datosEuler2[:,6]
veloyE3= datosEuler3[:,6]
veloyL1= datosleap1[:,5]
veloyL2= datosleap2[:,5]
veloyL3= datosleap3[:,5]
veloyR1= datosR1[:,5]
veloyR2= datosR2[:,5]
veloyR3= datosR3[:,5]



plt.figure(figsize=(15,15))
plt.subplot(331)
plt.plot(x,y, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler-0.02")
plt.subplot(332)
plt.plot(xL,yL, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog-0.02")
plt.subplot(334)
plt.plot(x2,y2, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler-0.001")
plt.subplot(335)
plt.plot(xL2,yL2, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog-0.001")
plt.subplot(337)
plt.plot(x3,y3, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler-0.0015")
plt.subplot(338)
plt.plot(xL3,yL3, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Leap-frog-0.0015")
plt.subplot(333)
plt.plot(xR,yR, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta-0.02")
plt.subplot(336)
plt.plot(xR2,yR2, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta-0.001")
plt.subplot(339)
plt.plot(xR3,yR3, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Runge-Kutta-0.0015")

plt.savefig("XY_met_dt")



plt.figure(figsize=(16,16))
plt.subplot(331)
plt.plot(tiempo,energE1)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia Euler0.02")
plt.subplot(332)
plt.plot(tiempo,energL1)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia Leap0.02")
plt.subplot(334)
plt.plot(tiempo,energE2)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia Euler0.01")
plt.subplot(335)
plt.plot(tiempo,energL2)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia Leap0.01")
plt.subplot(337)
plt.plot(tiempo,energE3)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia Euler0.015")
plt.subplot(338)
plt.plot(tiempo,energL3)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia Leap0.015")
plt.subplot(333)
plt.plot(tiempo,energR1)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia R0.02")
plt.subplot(336)
plt.plot(tiempo,energR2)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia R0.01")
plt.subplot(339)
plt.plot(tiempo,energR3)
plt.xlabel("Tiempo")
plt.ylabel("Energia")
plt.title("Energia R0.015")
plt.savefig("Ener_met_dt")




plt.figure(figsize=(15,15))
plt.subplot(331)
plt.plot(tiempo,momentoE1)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Euler0.02")
plt.subplot(334)
plt.plot(tiempo,momentoE2)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Euler0.01")
plt.subplot(337)
plt.plot(tiempo,momentoE3)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Euler0.015")
plt.subplot(332)
plt.plot(tiempo,momentoL1)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Leap0.02")
plt.subplot(335)
plt.plot(tiempo,momentoL2)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Leap0.01")
plt.subplot(338)
plt.plot(tiempo,momentoL3)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Leap0.015")
plt.subplot(333)
plt.plot(tiempo,momentoR1)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Runge0.02")
plt.subplot(336)
plt.plot(tiempo,momentoR2)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Runge0.01")
plt.subplot(339)
plt.plot(tiempo,momentoR3)
plt.xlabel("X")
plt.ylabel("Momento")
plt.title("Momento Runge0.015")
plt.savefig("Mome_met_dt")






plt.figure(figsize=(15,15))
plt.subplot(331)
plt.plot(veloxE1,veloyE1)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Euler 0.02")
plt.subplot(334)
plt.plot(veloxE2,veloyE2)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Euler0.01")

plt.subplot(337)
plt.plot(veloxE3,veloyE3)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Euler0.015")

plt.subplot(332)
plt.plot(veloxL1,veloyL1)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Leap0.02")

plt.subplot(335)
plt.plot(veloxL2,veloyL2)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Leap0.01")
plt.subplot(338)
plt.plot(veloxL3,veloyL3)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Leap0.015")

plt.subplot(333)
plt.plot(veloxR1,veloyR1)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Runge0.02")

plt.subplot(336)
plt.plot(veloxR2,veloyR2)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Runge0.01")


plt.subplot(339)
plt.plot(veloxR3,veloyR3)
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.title("Velocidad Runge0.015")
plt.savefig("VxVy_met_dt")
