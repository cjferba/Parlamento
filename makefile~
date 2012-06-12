# Fichero makefile
# Construye parlamento

all:  bin/parlamento clean

bin/parlamento:obj/parlamento.o lib/libciudad.a
	g++ -o bin/parlamento obj/parlamento.o -L./lib -lciudad

obj/partido.o:src/partido.cpp include/partido.h
	g++ -c -o obj/partido.o src/partido.cpp -I./include
	
obj/provincia.o:src/provincia.cpp include/provincia.h
	g++ -c -o obj/provincia.o src/provincia.cpp -I./include

obj/parlamento.o:src/parlamento.cpp include/provincia.h include/partido.h 
	g++ -c -o obj/parlamento.o src/parlamento.cpp -I./include

lib/libciudad.a:obj/provincia.o obj/partido.o
	ar rvs lib/libciudad.a obj/provincia.o obj/partido.o

clean:
	rm obj/*.o

all:bin/tabula 

bin/tabula:	obj/tabula.o
	g++ -o bin/tabula obj/tabula.o
obj/tabula.o:src/tabula.cpp
	g++ -c -o obj/tabula.o src/tabula.cpp 


