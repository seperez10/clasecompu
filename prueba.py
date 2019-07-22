import numpy as np

import numpy as np
import matplotlib.pylab as plt

# Funcion a integrar
N=1000
x1= np.linspace(0,((3*np.pi)/2),N)
h=((3*np.pi)/2)/(N-1.0)
def funcion(x1):
	return np.cos(x1)

valoranal= np.sin(x1)
analitico= np.sin((3*np.pi)/2)-np.sin(0)
print ("El valor analitico segun funciones de python es", analitico)

#El intervalo de integracion es de 0 a 3pi/2. Divida el intervalo de integracion en M secciones para calcular sus integrales.

# 1a). Usando el metodo de suma de rectangulos, calcule la integral de la funcion. Compare su valor obtenido numericamente con el valor analitico e imprima ambos valores.

resultrec= np.sum(funcion(x1)*h)
print ("El valor encontrado por rectangulos es", resultrec)

resulttra= np.sum(funcion(x1))*h-(funcion(x1)[0]*h/2) -(funcion(x1)[-1]*h/2)
print ("El valor encontrado por trapezoides es", resulttra)



def simpson(y,N,h): 
    suma = 0.0
    suma2 = 0.0
    x1 = (((3*np.pi)/2)/N)
    for i in range(1, N-2, 2):
        suma = suma+(np.cos(i*h)*4) 
    for j in range(2, N-1, 2):
        suma2 = suma2 + (np.cos(j*h)*2)
        integralsimp = (h*(suma+suma2+(np.cos(0))+(np.cos((3*np.pi)/2))))/3
    return integralsimp
resultsimp= simpson(funcion(x1),N,h)
print ("El valor encontrado por simpson es", resultsimp)
errorsimp= abs(((resultsimp-analitico)/analitico)*100)



####Divisibles entre 3 de 20 a 50###
'''def funcion():
    #contador =20
    for i in range (20,51):
        if(i%3==0 ):
            #contador +=1
            print (i)
funcion()'''    





















import numpy as np
import matplotlib.pylab as plt

N=1000
x= np.linspace(0,2*np.pi,N)
h= (2*np.pi)/(N-1)

def funcion(x):
	return np.cos(x)

prueba= np.sin(x)

y= np.array(funcion(x))
#print (y)
y0= y[0:-2]
yH=y[1:-1]


def forward1(h):
    
    resultfor= ((yH-y0)/h)
    return resultfor

#print ("Por arreglos y forward", forward1(h))
#print (len(forward1(h)))
       
analitica= -(np.sin(2*np.pi))+np.sin(0)
#print (analitica)

# 1a.) Implemente el algoritmo que le permita calcular la derivada de la funcion en el intervalo 0 a 2pi usando forward difference.

'''def forward(h):
    cont=0
    if (cont != -1):
        resultado= (int(y[cont+1]-y[cont]))/(h)
        cont = cont+1
        
    return resultado
print ("Con un if y forward", forward(h))'''



# 1b.) Implemente el algoritmo que le permita calcular la derivada de la funcion en el intervalo 0 a 2pi usando diferencia central.

y0cen=y[0:-1]

def central(ymenh,ymash,h):
    resultcen=(ymash-ymenh)/(2*h)
    return resultcen
#print ("central difference", central(h))

ymenh=y[0:-2]
ymash=y[2:]

resultadofincen=central(ymenh,ymash,h) 
# 1c.) Haga una grafica de la funcion y sus derivadas obtenidas usando los dos metodos antes mencionado. Guarde dicha grafica sin mostrarla en DerivadaFun.pdf. 


plt.figure()
plt.plot(forward1(h),label="Forward")
plt.plot(-prueba,label="Sen")
plt.plot(central(ymenh,ymash,h),label = "Central")
plt.xlabel("Numero de puntos")
plt.ylabel("Derivada")
plt.legend()
plt.savefig("DerivadaFun.pdf")

# 1d.) Haga una grafica con dos subplots (uno por cada metodo) del error |(valor numerico - valor analitico)| en el intervalo. Guarde dicha grafica sin mostrarla en ErrorDerivada.pdf

pruebadef= prueba[1:-1]
forwarddef= forward1(h)
centraldef= central(ymenh,ymash,h)
#print (np.shape(forwarddef))
#print (np.shape(pruebadef))
#print (np.shape(centraldef))
errorfor=[]
errorcen=[]
for i in range (N-2):

    calculofor=abs((forwarddef[i]+pruebadef[i]))
    calculocen=abs((centraldef[i]+pruebadef[i]))
    errorfor.append(calculofor)
    errorcen.append(calculocen)
    
#print (errorfor)
#print (errorcen)

plt.figure()
plt.subplot(211)
plt.plot(errorfor)
plt.title("Error forward")
plt.subplot(212)
plt.plot(errorcen)
plt.title("Error Central")
plt.savefig("ErrorDerivada.pdf")

# 1e). Implemente el algoritmo que le permita calcular la segunda derivada de la funcion en el intervalo 0 a 2pi. Haga una grafica de la funcion y su segunda derivada. Guarde dicha grafica sin mostrarla en 2DerivadaFun.pdf.

analiticasegdev= -np.cos(x)

ysegmenh=resultadofincen[0:-2]
ysegmash=resultadofincen[2:]
segundaderi=central(ysegmenh,ysegmash,h)
plt.figure()
plt.plot(segundaderi, label="segunda derivada")
plt.plot(analiticasegdev, label= "-cos(x)")
plt.xlabel("Numero de puntos")
plt.ylabel("Derivada")
plt.legend()
plt.savefig("2DerivadaFun.pdf")

################################################################## clase ######################################################################################
# Ejercicio 2:

# 2a.) Descargue los datos del archivo datosfun.dat. La columna 1 es una variable x y la columna 2 es f(x)

datos= np.genfromtxt("datosfun.dat")
x2= datos[:,0]
y2= datos[:,1]
HN= (x2[-1]-x2[0])/(len(x2))
#print(HN)

# 2b.) Calcule la derivada de f(x) para los datos del archivo. 

y2mash=y2[2:]
y2menh=y2[0:-2]
resultderdat= central(y2menh,y2mash,HN)
print (resultderdat)

# 2c.) Haga una grafica de la funcion y su derivada. Guarde dicha grafica sin mostrarla en DerivadaDatos.pdf. 

plt.figure()
plt.plot(y2,label="f(x)")
plt.plot(resultderdat,label= "Derivada")
plt.legend()
plt.xlabel("Numero de puntos")
plt.ylabel("Derivada")
plt.savefig("DerivadaDatos")



################################################################## hacer en casa ######################################################################################

# Ejercicio 3:


# 3a.) Implemente el metodo de biseccion y el metodo de Newton-Raphson para encontrar el cero de la funcion e imprima sus resultados y el numero de pasos necesarios para encontrar el cero con la misma precision con ambos metodos.
def funcionbN(x):
	return x**3 +17*x-15

ybn=funcionbN(x)
def biseccion():
    for i in range(N):
        
        a=x[0]
        b=x[-1]
        intervalonuevo= np.linspace(a, b,N)
        m=(b-a)/2
        comprobar= funcionbN(m)
        fa= funcionbN(a)
        fb= funcionbN(b)
        pasos=0
    
        while (N<1000 and int(comprobar)!= 0):
            if (comprobar>0 and fa<0 or comprobar<0 and fa>0):
                b=m
                pasos =pasos+1
            elif (comprobar>0 and fb<0 or comprobar<0 and fb>0):
                a=m
                pasos=pasos+1
    return (a,b,m,funcionbN(m),pasos)
print (biseccion())
