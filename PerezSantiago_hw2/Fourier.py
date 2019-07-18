import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm


datossonrisa= plt.imread("cara_03_grisesMF.png")
datosseria= plt.imread("cara_02_grisesMF.png")
#print (np.shape(datossonrisa))
#plt.figure()
#plt.imshow(datossonrisa, plt.cm.gray)
#plt.imshow(datosseria, plt.cm.gray)
#plt.savefig("hola")


Transsonrisa= np.fft.fft2(datossonrisa)
Transseria= np.fft.fft2(datosseria)

sonrisafreq= np.fft.fftshift(Transsonrisa)
seriafreq= np.fft.fftshift(Transseria)


plt.figure()
plt.imshow(abs(Transsonrisa), norm=LogNorm())
plt.colorbar()
plt.title("Transformada Sonrisa")
plt.savefig("Transsonrisa")

plt.figure()
plt.imshow(abs(Transseria), norm=LogNorm())
plt.colorbar()
plt.title("Transformada Seria")
plt.savefig("Transseria")

plt.figure()
plt.imshow(abs(sonrisafreq), norm=LogNorm())
plt.colorbar()
plt.title("Frecuencias Sonrisa")
plt.savefig("freqsonrisa")

plt.figure()
plt.imshow(abs(seriafreq), norm=LogNorm())
plt.colorbar()
plt.title("Frecuencias seria")
plt.savefig("freqseria")




