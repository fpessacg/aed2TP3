#include "DiccString.cpp"
#include <iostream>
#include "aed2/TiposBasicos.h"
#include "Tipos.h"

int main(){
	tp3::DiccString<aed2::Nat> prueba;
	aed2::Nat sig(3);
	aed2::String clave("hola");
	prueba.Definir(clave, sig);
	std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave) << std::endl;
	return 0;
}