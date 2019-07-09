import numpy as np
import matplotlib.pyplot as plt


datos = np.genfromtxt("datos.dat")

plt.figure()
plt.plot(datos)
plt.xlabel("X")
plt.ylabel("Upre")
plt.savefig("datos")