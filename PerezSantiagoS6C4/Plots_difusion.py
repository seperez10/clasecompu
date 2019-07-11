import numpy as np
import matplotlib.pyplot as plt


iniciales= np.loadtxt("iniciales.dat")
Fijas100= np.loadtxt("Fijas100.dat")
Fijas2500= np.loadtxt("Fijas2500.dat")
Abiertas100= np.loadtxt("Abiertas100.dat")
Abiertas2500= np.loadtxt("Abiertas2500.dat")
Periodicas100= np.loadtxt("Periodicas100.dat")


plt.subplot(131)
plt.imshow(iniciales)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Condiciones iniciales")
plt.subplot(132)
plt.imshow(Fijas100)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Fijas 100")
plt.subplot(133)
plt.imshow(Fijas2500)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Fijas 2500")
plt.savefig("Fijas")

plt.figure()
plt.subplot(121)
plt.imshow(Abiertas100)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Abiertas 100")
plt.subplot(122)
plt.imshow(Abiertas2500)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Abiertas 2500")
plt.savefig("Abiertas")


plt.figure()
plt.subplot(121)
plt.imshow(Periodicas100)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Periodicas 100")
'''plt.subplot(122)
plt.imshow(Abiertas2500)
plt.xlabel("x")
plt.ylabel("Y")
plt.title("Abiertas 2500")'''
plt.savefig("Periodicas")