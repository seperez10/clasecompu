import numpy as np
import matplotlib.pyplot as plt


datos= np.genfromtxt("datos1.dat", delimiter= ",")

t= datos[:,0]
x= datos[:,1]

plt.figure()
plt.plot(t,x)
plt.savefig("datos")