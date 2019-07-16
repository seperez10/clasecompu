import numpy as np
import matplotlib.pyplot as plt



datosEuler1= np.genfromtxt("datoseuler1.dat", delimiter= ",")

x= datosEuler1[:,0]
y= datosEuler1[:,1]


plt.figure()
plt.plot(x,y, color= "red")
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Euler")
plt.savefig("Euler1")