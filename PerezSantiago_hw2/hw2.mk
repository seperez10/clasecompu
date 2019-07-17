plot: Plots_hw2.py datos.dat 
	python Plots_hw2.py
datos.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out