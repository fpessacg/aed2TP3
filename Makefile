OBJECTS={*.o}
//CPP={}


build: *.cpp *.h
	g++ -o tests -g main.cpp Tabla.cpp Dato.cpp DiccString.cpp Registro.cpp 


clean: 
	rm *.o
