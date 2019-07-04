import numpy as np
import matplotlib.pyplot as plt


datos= np.genfromtxt("datos.dat",skip_header=3)


plt.figure()
plt.plot(datos)
plt.savefig("plotsS5C1")