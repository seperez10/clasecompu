import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("Canal_ionico.txt", delimiter ="	")
#print (datos)


plt.figure()
plt.scatter(datos[:,0],datos[:,1])
plt.savefig("Poros")