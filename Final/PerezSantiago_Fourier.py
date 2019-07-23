# Tiene una serie de tiempo, donde los datos de tiempo estan almacenados en un arreglo t y los datos de amplitud en un arreglo amp.
#1) Usando los paquetes de scipy de la transformada de Fourier, haga un FILTRO de la senial que elimine las frecuencias mayores a 1000Hz en las senial original.
#2) Haga una grafica de la senial original y la senial filtarada y guardela SIN MOSTRARLA en filtro.pdf
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq, ifft

n = 1280 # number of point in the whole interval
f = 200.0 #  frequency in Hz
dt = 1 / (f * 320 ) #320 samples per unit frequency
t = np.linspace( 0, (n-1)*dt, n)
amp = np.cos(2 * np.pi * f * t) - 0.4 * np.sin(2 * np.pi * (2*f) * t ) + np.random.random(n)
#print (amp)
TransformadaAmp= np.fft.fft(amp)
#print (TransformadaAmp)
freq= np.fft.fftfreq(len(TransformadaAmp))*f
#print (max(freq))

# SU FILTRO
filtro=[]
for i in range(len(TransformadaAmp)):
    if(freq[i]>2 or freq[i]<-1):
        filtro.append(0)
    else:
        filtro.append(TransformadaAmp[i])
#print (filtro)
    
inversa= np.real(np.fft.ifft(filtro))
#print (inversa)
# SU GRAFICA
plt.figure(figsize=(15,15))
plt.plot(t,amp,label="Original")
plt.plot(t,inversa,label= "filtrada")
plt.xlabel("tiempo")
plt.ylabel("Amplitud")
plt.title("Original y filtrada")
plt.legend()
plt.savefig("filtro")

# Puede usar los siguientes paquetes:
#from scipy.fftpack import fft, fftfreq, ifft

