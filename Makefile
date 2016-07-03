OBJECTS={*.o}
//CPP={}


build: *.cpp *.h
	g++ -o tests testPropio.cpp  Tabla.cpp Dato.cpp BaseDatos.cpp DiccLog.cpp DiccString.cpp Registro.cpp

clean: 
	rm *.o
