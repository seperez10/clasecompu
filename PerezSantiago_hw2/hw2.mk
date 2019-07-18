plot: Plots_hw2.py datos.dat  Fourier.py
	python Plots_hw2.py 
	python Fourier.py    
datos.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out