import numpy as np
import matplotlib.pyplot as plt


iniciales= np.loadtxt("iniciales.dat")
Fijas100= np.loadtxt("Fijas100.dat")

plt.figure()
#print (np.shape(iniciales))
plt.imshow(iniciales)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Condiciones iniciales")
plt.savefig("Iniciales")

plt.figure()
plt.imshow(Fijas100)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Fijas 100")
plt.savefig("Fijas100")
           