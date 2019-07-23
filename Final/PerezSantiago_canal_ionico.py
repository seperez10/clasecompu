import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("Canal_ionico.txt", delimiter ="	")
#print (datos)


plt.figure()
plt.scatter(datos[:,0],datos[:,1])
plt.savefig("Poros")

rx=[]
ry=[]
random1 = np.random.uniform(min(datos[:,0]),max(datos[:,0]),1000)
random2 = np.random.uniform(min(datos[:,1]),max(datos[:,1]),1000)
for i in range (len(random1)):
    if (((random1[i]**2+random2[i]**2)**0.5) <= (max(datos[:,0])**2+(max(datos[:,0])**2)**0.5)):
        rx.append(random1[i])
        ry.append(random2[i])
                            
                            
plt.figure()
plt.scatter(rx,ry)
plt.savefig("circulo")        
                            
                            