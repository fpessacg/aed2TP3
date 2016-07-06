#include "DiccString.cpp"
#include <iostream>
#include "aed2/TiposBasicos.h"
#include "Tipos.h"

int main(){
	tp3::DiccString<aed2::Nat> prueba;
	aed2::Nat sig(3);
	aed2::Nat sig2(4);
	aed2::Nat sig3(5);
	aed2::String clave("hola");
	aed2::String clave2("holaf");
	aed2::String clave3("hols");
	prueba.Definir(clave, sig);
	prueba.Definir(clave2, sig2);
	prueba.Definir(clave3, sig3);
	std::cout << "Esta def? " << prueba.Def(clave) << std::endl;
	std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave) << std::endl;
	std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave2) << std::endl;
	std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave3) << std::endl;
	return 0;
}