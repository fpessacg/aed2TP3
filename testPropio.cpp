// compilar usando:
//   g++ -o tests tests.cpp Driver.cpp <lista de archivos *.cpp propios>

#include "Driver.h"
#include "mini_test.h"

#include <string>
#include <iostream>
 
void ejemplo_simple(){
	int a = 1 + 1; 
}

int main(int argc, char **argv)
{
  RUN_TEST( ejemplo_simple );

  /********************************************************************
   * TODO: escribir casos de test exhaustivos para todas              *
   * las funcionalidades de cada módulo.                              *
   * La interacción con el TAD principal se debe hacer exclusivamente *
   * a través de la interfaz del driver.                              *
   ********************************************************************/

	return 0;
}

