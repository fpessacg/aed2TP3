#include "DiccLog.h"
#include <iostream>
#include <assert.h>
#include "DiccString.h"

using namespace aed2;
using namespace std;

int main() {

	DiccLog<int> prueba;
	prueba.Definir(3,4);
	prueba.Definir(2,5);
	prueba.Definir(1,6);
	prueba.Definir(4,100);

	//assert(prueba.Def(4) == true);
	//assert(prueba.Obtener(4) == 100);
	//assert(prueba.Def(3) == true);

	prueba.Borrar(4);

	//assert(prueba.Def(4) == false);
	return 0;
}