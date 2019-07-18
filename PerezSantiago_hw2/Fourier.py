import numpy as np
import matplotlib.pyplot as plt


datossonrisa= plt.imread("cara_03_grisesMF.png")
datosseria= plt.imread("cara_02_grisesMF.png")
#print (np.shape(datossonrisa))
#plt.figure()
#plt.imshow(datossonrisa, plt.cm.gray)
#plt.imshow(datosseria, plt.cm.gray)
#plt.savefig("hola")


Transsonrisa= np.fft.fft2(datossonrisa)
Transseria= np.fft.fft2(datosseria)