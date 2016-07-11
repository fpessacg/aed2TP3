#include "DiccString.cpp"
#include "DiccLog.cpp"
#include <iostream>
#include "aed2/TiposBasicos.h"
#include "Tipos.h"

using namespace std;


int main(){
    tp3::DiccLog<aed2::Nat> prueba;
    aed2::Nat clave(3);
    aed2::Nat clave2(5);
    aed2::Nat clave3(2);
    aed2::Nat clave4(1);
    aed2::Nat sig(4);
    aed2::Nat sig2(6);
    aed2::Nat sig3(3);
    aed2::Nat sig4(8);
    prueba.Definir(clave,sig);
    prueba.Definir(clave2,sig2);
    prueba.Definir(clave3,sig3);
    prueba.Definir(clave4, sig4);
    prueba.Borrar(clave);
    cout << prueba.Def(clave4) << endl;

 //    tp3::DiccString<aed2::Nat> prueba;
	// aed2::Nat sig(3);
	//  aed2::Nat sig2(4);
	//  aed2::Nat sig3(5);
	//  aed2::String clave("hola");
	//  aed2::String clave2("hols");
	//  aed2::String clave3("tete");
	//  prueba.Definir(clave, sig);
	//  prueba.Definir(clave2, sig2);
	//  prueba.Definir(clave3, sig3);
	// // std::cout << "Esta def? " << prueba.Def(clave) << std::endl;
	//  std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave) << std::endl;
	//  std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave2) << std::endl;
	//  std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave3) << std::endl;
	// //int a[3];
	// //a['a'] = 2;
	// //for(int i = 0; i < 256; i++) std::cout << a[13] << std::endl;
	  return 0;
}