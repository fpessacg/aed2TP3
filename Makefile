OBJECTS={*.o}
//CPP={}


build: *.cpp *.h
	g++ -o tests tests.cpp Driver.cpp Tabla.cpp Auxiliares.cpp BaseDatos.cpp DiccLog.cpp DiccString.cpp

clean: 
	rm *.o
