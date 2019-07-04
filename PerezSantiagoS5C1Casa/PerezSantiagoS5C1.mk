

plot: S5C1PLOT.py datos.dat
	python S5C1PLOT.py
datos.dat: S5C1Deriv.cpp
	g++ S5C1Deriv.cpp
	./a.out > datos.dat