OBJECTS={*.o}
//CPP={}


build: *.cpp *.h
	g++ -o tests -g tests.cpp -std=c++11 Tabla.cpp Dato.cpp BaseDatos.cpp Registro.cpp Driver.cpp


clean: 
	rm *.o
