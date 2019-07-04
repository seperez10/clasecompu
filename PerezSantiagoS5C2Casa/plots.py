import numpy as np
import matplotlib.pyplot as plt


datos= np.genfromtxt("datos.dat", delimiter= ",")

X= datos[:,0]
Y=datos[:,1]


plt.figure()
plt.plot(X,Y, label= "Euler")
plt.xlabel("X")
plt.ylabel("y(x)")
plt.savefig("plotsS5C2")