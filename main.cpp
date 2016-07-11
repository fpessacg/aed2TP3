#include "DiccString.cpp"
#include "DiccLog.cpp"
#include <iostream>
#include "aed2/TiposBasicos.h"
#include "Tipos.h"

using namespace std;


int main(){
//    tp3::DiccLog<aed2::Nat> prueba;
//    aed2::Nat clave(10);
//    aed2::Nat clave2(8);
//    aed2::Nat clave3(9);
//    aed2::Nat clave4(4);
//    aed2::Nat clave5(5);
//    aed2::Nat clave6(7);
//    aed2::Nat clave7(6);
//
//    aed2::Nat sig(1);
//    aed2::Nat sig2(2);
//    aed2::Nat sig3(3);
//    aed2::Nat sig4(4);
//    aed2::Nat sig5(5);
//    aed2::Nat sig6(6);
//    aed2::Nat sig7(7);
//
//    prueba.Definir(clave,sig);
//    prueba.Definir(clave2,sig2);
//    prueba.Definir(clave3,sig3);
//    prueba.Definir(clave4, sig4);
//    prueba.Definir(clave5, sig5);
//    prueba.Definir(clave6, sig6);
//    prueba.Definir(clave7, sig7);
//
//    prueba.Borrar(clave2);
//    if(prueba.Definido(clave2)) {
//        cout << "Vale: " << prueba.Obtener(clave2) << endl;
//    } else {
//        cout << "Quiero ver el nuevo: " << prueba.Obtener(clave4) << endl;
//    }

    tp3::DiccString<aed2::Nat> prueba;
    aed2::Nat sig(3);
    aed2::Nat sig2(4);
    aed2::Nat sig3(5);
    aed2::String clave("hola");
    aed2::String clave2("hols");
    aed2::String clave3("tete");
    prueba.Definir(clave, sig);
    prueba.Definir(clave2, sig2);
    prueba.Definir(clave3, sig3);
    // std::cout << "Esta def? " << prueba.Def(clave) << std::endl;
    std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave) << std::endl;
    std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave2) << std::endl;
    std::cout << "Orga 2 no te ayuda: " << prueba.Obtener(clave3) << std::endl;
    std::cout << "Orga 2 no te ayuda (parte 2): " << prueba.Def(clave3) << " y tambien "
        << prueba.Def(clave2) << endl;
    prueba.Borrar(clave2);
    std::cout << "Esto tiene que dar q no: " << prueba.Def(clave2) << " y " <<
            prueba.Def(clave) << std::endl;
	 //int a[3];
	 //a['a'] = 2;
	 //for(int i = 0; i < 256; i++) std::cout << a[13] << std::endl;

    return 0;
}