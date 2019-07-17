# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2))/((x-x_0)**2 + a**2)
x= np.linspace(-4,4,10000)
h= (mifun(x)[-1]-mifun(x)[0])/(10000-1)
# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 
def inte(x):
    h= (x[-1]-x[0])/(10000-1)
    return np.sum(mifun(x))*h


normalfunc= mifun(x)/inte(x)
print(normalfunc)

def Metropolis(pasos, sigma):
    Resultado= np.zeros(pasos)
    Resultado[0]= np.random.uniform(-4,4,1)
    #print (Resultado[0])
    for i in range(pasos-1):
        xini=Resultado[i]
        xguess= xini+np.random.normal(0,sigma,1)
        #print(xini)
        #print (xguess)
        actual=mifun(xini)
        propuesta=mifun(xguess)
        alpha=propuesta/actual
        r=np.random.uniform(low=0.0,high=1.0)
        if(r < alpha):
            Resultado[i+1]=xguess
        else:
            Resultado[i+1]=xini          
    return Resultado

#print (Metropolis(10000,5))
def plot(sigma,pasos):
    plt.figure()
    plt.hist(Metropolis(pasos,sigma),bins=60,label="sigma="+str(sigma)+" "+ str(pasos)+"=pasos",density=True)
    plt.plot(x,normalfunc)
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.legend()
    plt.title("sigma="+str(sigma)+" "+ str(pasos)+"=pasos")
    plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".png")


plot(0.1,100000)
plot(0.2,100000)
plot(0.01,100000)
plot(0.1,1000)
plot(5,100000)
plot(0.1,500000)
             
         

# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000 
# sigma = 0.2, pasos =100000 
# sigma = 0.01, pasos =100000 
# sigma = 0.1, pasos =1000 
# sigma = 0.1, pasos =100000 
# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
