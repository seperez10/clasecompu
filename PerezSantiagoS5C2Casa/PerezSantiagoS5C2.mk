
plot: plots.py datos.dat datos1.dat
	python plots.py
datos.dat datos1.dat datos2.dat : PerezSantiagoS5C2.cpp
	g++ PerezSantiagoS5C2.cpp
	./a.out