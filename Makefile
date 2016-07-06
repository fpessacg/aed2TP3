OBJECTS={*.o}
//CPP={}


build: *.cpp *.h
	g++ -o tests -g main.cpp Tabla.cpp Dato.cpp BaseDatos.cpp Registro.cpp DiccString.cpp

clean: 
	rm *.o
