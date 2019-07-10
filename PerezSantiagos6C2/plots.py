import numpy as np
import matplotlib.pyplot as plt


datosini = np.genfromtxt("datosini.dat")
datos1 = np.genfromtxt("datos1.dat")
plt.figure()
plt.plot(datosini, label="Inicial")
plt.plot(datos1, label="primero")
plt.legend()
plt.savefig("datosprueba")