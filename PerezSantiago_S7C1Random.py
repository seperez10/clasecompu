#Ejercicio 0
#Lean el capitulo 5 del Landau (ver el programa del curso).
import numpy as np
import matplotlib.pyplot as plt
#Ejercicio 1
# Usando los generadores de numeros aleatorios de numpy (https://docs.scipy.org/doc/numpy-1.15.1/reference/routines.random.html):
# a) Genere 1000 numeros aleatorios que sigan una distribucion uniforme y esten entre -10 y 10. Haga un histograma y guardelo sin mostrarlo en un archivo llamado uniforme.pdf

random1 = np.random.uniform(-10,10,1000)
#print (random1)

plt.figure()
plt.hist(random1, bins=60)
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Uniforme aleatorio")
plt.grid(True)
plt.savefig("uniforme")

# a) Genere 1000 numeros aleatorios que sigan una distribucion gausiana centrada en 17 y de sigma 5. Haga un histograma y guardelo sin mostrarlo en un archivo llamado gausiana.pdf


random2 = np.random.normal(17,5,1000)
plt.figure()
plt.hist(random2, bins=60)
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Gauss aleatorio")
plt.grid(True)
plt.savefig("Gausiana")


# Ejercicio 2
# Escriba un programa en Python que: 
# Genere puntos aleatorios distribuidos uniformemente dentro de un cuadrado de lado 30.5. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado cuadrado.pdf. 
# Genere puntos aleatorios distribuidos uniformemente dentro de circulo de radio 23. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado circulo.pdf. 


random3 = np.random.uniform(-15.25,15.25,1000)
random4 = np.random.uniform(-15.25,15.25,1000)
plt.figure()
plt.scatter(random3,random4)
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Cuadrado aleatorio")
plt.grid(True)
plt.savefig("Cuadrado")




R5=[]
R6=[]
random5 = np.random.uniform(-23,23,1000)
random6 = np.random.uniform(-23,23,1000)
for i in range (len(random3)):
    if (((random5[i]**2+random6[i]**2)**0.5) <= 23  ):
        R5.append(random5[i])
        R6.append(random6[i])
#print (R3)    
plt.figure()
plt.scatter(R5,R6)
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Circulo aleatorio")
plt.grid(True)
plt.savefig("Circulo")

# Ejercicio 3 
# Lean sobre caminatas aleatorias.


# Ejercicio 4
# Tome los puntos distribuidos aleatoriamente dentro del cuadrado y haga que cada punto siga una caminata aleatoria de 100 pasos. 
# La magnitud de los pasos de esta caminata debe seguir una distribucion gaussiana centrada en el punto y de sigma igual a 0.25
# Implemente condiciones de frontera periodicas: si un punto se "sale" de cuadrado por un lado, "entra" por el otro 

#print(random3)

R3=[]
R4=[]
for k in range (1000):
    
    for j in range (100):
        
        caminata1= np.random.normal(random3[k],0.25,1)
        caminata2= np.random.normal(random4[k],0.25,1)
        R3.append(caminata1)
        R4.append(caminata2)
        if(R3[j] > 15.25):
            R3[j]= -15.25 + R3[j]-15.25
        elif(R3[j]< -15.25):
            R3[j]= 15.25 + R3[j]+15.25
        elif(R4[j]> 15.25):
            R4[j]= -15.25+ R4[j]-15.25
        elif(R4[j]< -15.25):
            R4[j]= 15.25+ R4[j]+15.25
      
        
#print(min(R3))       
#print(random3)
        
plt.figure()
plt.scatter(R3,R4, s=1)
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Caminata aleatorio")
plt.grid(True)
plt.savefig("DistCaminata")        
        

# Grafique la distribucion final de puntos y guarde dicha grafica sin mostrarla en un archivo llamado DistCaminata.pdf


# Grafique la caminata de UNO de sus puntos y guarde dicha grafica sin mostrarla en un archivo llamado puntoCaminata.pdf
R3P=[]
R4P=[]

for m in range (100):
    caminata1P= np.random.normal(random3[1],0.5,1)
    caminata2P= np.random.normal(random4[1],0.5,1)
    R3P.append(caminata1P)
    R4P.append(caminata2P)
        
        
plt.figure()
plt.plot(R3P,R4P)
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Caminata punto aleatorio")
plt.grid(True)
plt.savefig("PuntoCaminata")  

# Repita el proceso para sigma = 0.00025 y sigma= 2.5. Grafique la caminata de UNO de sus puntos para los distintos sigmas y guardela sin mostrarla en sigmaCaminata.pdf
r3025=[]
r4025=[]
r325=[]
r425=[]

for m in range (100):
    caminata1P025= np.random.normal(random3[1],0.00025,1)
    caminata2P025= np.random.normal(random4[1],0.00025,1)
    r3025.append(caminata1P025)
    r4025.append(caminata2P025)
    caminata1P25= np.random.normal(random3[1],2.5,1)
    caminata2P25= np.random.normal(random4[1],2.5,1)
    r325.append(caminata1P25)
    r425.append(caminata2P25)
    
    
plt.figure()
plt.subplot(121)
plt.plot(r3025,r4025, label="Sigma=0.00025")
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Caminata punto aleatorio 0.00025")
plt.legend()
plt.grid(True)
plt.subplot(122)
plt.plot(r325,r425, label="Sigma=2.5")
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Caminata punto aleatorio 2.5")
plt.legend()
plt.grid(True)
plt.savefig("sigmaCaminata") 

# Repita el proceso para condiciones abiertas: si un punto se "sale" del cuadrado deja de ser considerado en la simulacion.

# Si le queda tiempo puede:

##################################################################################################################################################################
############################################################ Ejercicio  ##########################################################################
##################################################################################################################################################################

#difusion: una gota de crema en un Cafe.
#
#Condiciones iniciales:
#Cafe: 10000 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 230


R1C=[]
R2C=[]
R1Cr=[]
R2Cr=[]
random1C = np.random.uniform(-230**0.5,230**0.5,10000)
random2C = np.random.uniform(-230**0.5,230**0.5,10000)
for i in range (len(random1C)):
    if (((random1C[i]**2+random2C[i]**2)**0.5) <= 230**0.5  ):
        R1C.append(random1C[i])
        R2C.append(random2C[i])
        
random1Cr = np.random.uniform(-2**0.5,2**0.5,100)
random2Cr = np.random.uniform(-2**0.5,2**0.5,100)
for i in range (len(random1Cr)):
    if (((random1Cr[i]**2+random2Cr[i]**2)**0.5) <= 2**0.5  ):
        R1Cr.append(random1Cr[i])
        R2Cr.append(random2Cr[i])        

#print (R3)    
plt.figure()
plt.scatter(R1C,R2C, color="brown")
plt.scatter(R1Cr,R2Cr, color="white")
plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Cafe con leche")
plt.grid(True)
plt.savefig("CafeLecheIni")

#Crema: 100 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 2
#
#Nota: si su codigo se esta demorando mucho en correr, puede usar 1000 particulas de cafe en vez de 10000.
#
# 1) Haga una grafica de las condiciones iniciales donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheIni.pdf
#
#2) Todas las particulas deben hacer una caminata aleatoria de 1000 pasos. Los pasos en las coordenadas x y deben seguir una distribucion gausiana de sigma 2.5. Si va a usar coordenadas polares elija un sigma apropiado.
R3Cr=[]
R4Cr=[]
for k in range (100):
    
    for j in range (1000):
        
        caminata1Cr= np.random.normal(random1Cr[k],2.5,1)
        caminata2Cr= np.random.normal(random2Cr[k],2.5,1)
        R3Cr.append(caminata1Cr)
        R4Cr.append(caminata2Cr)

     
        
plt.figure()
plt.scatter(R1C,R2C,color="brown",label="Cafe")
plt.scatter(R3Cr,R4Cr, label="Leche")

plt.xlabel("Numero")
plt.ylabel("Cantidad")
plt.title("Caminata aleatorio")
plt.grid(True)
plt.legend()
plt.savefig("Caminata Leche") 


#
#3) Condiciones de frontera: implemente unas condiciones tales que si la particulas "sale" del circulo, usted vuelva a dar el paso. Si no puede implementar solo las condiciones antes descritas, debe al menos escribir comentarios explicando que hace cada linea de codigo de las condiciones propuestas (comentado abajo)
#
# 4) Haga una grafica de las posiciones finales de las particulas despues de la caminata donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheFin.pdf
#

import numpy as np
import matplotlib.pylab as plt


#Una posible implementacion de condiciones de frontera. Trate de hacer la suya propia sin usar esta. 
#Si usa esta (obtiene menos puntos) debe comentar cada una de las lineas explicando en palabras que hace el codigo. Debe tambien naturalmente usar los nombres de variables que uso en el resto de su codigo propio.
#indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>230)
#indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>230)
#while(len(indexcafe[0])>1):
#	xcafenuevo[indexcafe]=xcafe[indexcafe] + np.random.normal(0,sigma)
#	ycafenuevo[indexcafe]=ycafe[indexcafe] + np.random.normal(0,sigma)
#	indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>=230)
#while(len(indexcrema[0])>1):
#	xcremanuevo[indexcrema]=xcrema[indexcrema] + np.random.normal(0,sigma)
#	ycremanuevo[indexcrema]=ycrema[indexcrema] + np.random.normal(0,sigma)
#	indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>=230) 



	
