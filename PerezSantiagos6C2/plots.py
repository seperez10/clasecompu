import numpy as np
import matplotlib.pyplot as plt


datosini = np.genfromtxt("datosini.dat")
datosfijas1 = np.genfromtxt("datosfijas1.dat")
datosfijas2 = np.genfromtxt("datosfijas2.dat")
datosfijas3 = np.genfromtxt("datosfijas3.dat")
datosfijaslibres1 = np.genfromtxt("datosfijaslibres1.dat")

plt.figure()
plt.plot(datosini, label="Inicial")
plt.plot(datosfijas1, label="Fijas t1")
plt.plot(datosfijas2, label="Fijas t2")
plt.plot(datosfijas3, label="Fijas t3")

plt.xlabel("tiempo")
plt.ylabel("Amplitud")
plt.legend()
plt.savefig("Analisis Fijas")


plt.figure()
plt.plot(datosfijaslibres1, label="Fijas libres t1")
plt.xlabel("tiempo")
plt.ylabel("Amplitud")
plt.legend()
plt.savefig("Analisis Fijas-Libres")