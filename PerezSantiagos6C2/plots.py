import numpy as np
import matplotlib.pyplot as plt


datosini = np.genfromtxt("datosini.dat")
datosfijas1 = np.genfromtxt("datosfijas1.dat")
datosfijas2 = np.genfromtxt("datosfijas2.dat")
datosfijas3 = np.genfromtxt("datosfijas3.dat")
datosfijaslibres1 = np.genfromtxt("datosfijaslibres1.dat")
datosfijaslibres2 = np.genfromtxt("datosfijaslibres2.dat")
datosfijaslibres3 = np.genfromtxt("datosfijaslibres3.dat")
datosperiodicas1 = np.genfromtxt("datosperiodicas1.dat")
datosperiodicas2 = np.genfromtxt("datosperiodicas2.dat")

plt.figure()
plt.plot(datosini, label="Inicial")
plt.plot(datosfijas1, label="Fijas t1")
plt.plot(datosfijas2, label="Fijas t2")
plt.plot(datosfijas3, label="Fijas t3")

plt.xlabel("tiempo")
plt.ylabel("Amplitud")
plt.title("Analisis Fronteras Fijas") 
plt.legend()
plt.savefig("Analisis Fijas")


plt.figure()
plt.plot(datosfijaslibres1, label="Fijas libres t1")
plt.plot(datosfijaslibres2, label="Fijas libres t2")
plt.plot(datosfijaslibres3, label="Fijas libres t3")
plt.xlabel("tiempo")
plt.ylabel("Amplitud")
plt.title("Analisis Frontera Fija_libre") 
plt.legend()
plt.savefig("Analisis Fijas-Libres")

plt.figure()
plt.plot(datosperiodicas1, label="Periodicas t1")
plt.plot(datosperiodicas2, label="Periodicas t2")
plt.xlabel("tiempo")
plt.ylabel("Amplitud")
plt.title("Analisis Frontera periodica") 
plt.legend()
plt.savefig("Analisis Periodicas")