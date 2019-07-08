plot: PerezSantiagoS5C3plots.py  datos1.dat
	python PerezSantiagoS5C3plots.py
datos1.dat  : PerezSantiagoS5C3casa.cpp
	g++ PerezSantiagoS5C3casa.cpp
	./a.out