import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("Canal_ionico.txt", delimiter ="	")
#print (datos)


plt.figure()
plt.scatter(datos[:,0],datos[:,1])
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Poros")
plt.savefig("Poros")

rx=[]
ry=[]
random1 = np.random.uniform(min(datos[:,0]),max(datos[:,0]),1)
random2 = np.random.uniform(min(datos[:,1]),max(datos[:,1]),1)


for i in range (len(datos[:,0])):
    pasox=np.random.normal(random1,0.1) 
    pasoy=np.random.normal(random2,0.1) 
    actual=(random1**2+random2**2)**0.5
    propuesta= (((pasox)**2+(pasoy)**2)**0.5)
    alpha= propuesta/actual
    r= np.random.uniform(0,1)
    if(alpha<r):
        rx.append(pasox)
        ry.append(pasoy)
        random1=pasox
        random2=pasoy
        
    else:
        rx.append(random1)
        ry.append(random2)
        random1=random1
        random2=random2
        
#print (rx,ry)
                            
                            
plt.figure()
plt.scatter(rx,ry)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Circulo")
plt.savefig("circulo")        
                            
                            