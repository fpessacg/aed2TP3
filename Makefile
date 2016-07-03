OBJECTS={*.o}
//CPP={}


build: *.cpp *.h
	g++ -o tests -g testPropio.cpp  Tabla.cpp Dato.cpp BaseDatos.cpp Registro.cpp

clean: 
	rm *.o
