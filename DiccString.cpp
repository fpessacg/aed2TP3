#include "DiccString.h"
#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "aed2/TiposBasicos.h"
#include <string>

template<class T>
int tp3::DiccString<T>::letter_tonum(char ch) const{
	char c[]= {',','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < 27 ; i++){
		if(c[i] == ch) return i;
	}

}

template<class T>
char tp3::DiccString<T>::nth_letter(int n) const
{
    //assert(n >= 1 && n <= 26)
    return "abcdefghijklmnopqrstuvwxyz"[n-1];
}

template<class T>
tp3::DiccString<T>::DiccString(){
	Nodo raizCopy(false,'l');
	this->raiz = &raizCopy;
	//this->raiz->hijos = new Nodo[256];
	for(int i = 0; i < 26; ++i){
		Nodo nodoCopy(false, nth_letter(i));
		this->raiz->hijos[i] = &nodoCopy;
	}
	aed2::Conj<aed2::String> clavesTemp;
	this->claves = clavesTemp;
}

template<class T>
void tp3::DiccString<T>::Definir(aed2::String& c, T& s){
	this->claves.AgregarRapido(c);

	struct Nodo* nodoRecorrer = this->raiz;
	for(int i = 0; i < c.length(); i++){
		if(!(nodoRecorrer->hijos[c[i]])){
			char nuevoChar = (char) c[i];
			//std::cout << "quien te conoce nuevoChar: " << nuevoChar << std::endl;
			Nodo nuevo(false, nuevoChar);
			nuevo.significado = 0;
			for(int j = 0; j < 26; j++) {
				Nodo nodoCopy(false, nth_letter(i));
				nuevo.hijos[i] = &nodoCopy;
			}
			//nodoRecorrer->hijos[c[i]] = 0;
			nodoRecorrer->hijos[letter_tonum(c[i])] = &nuevo;
			nodoRecorrer = nodoRecorrer->hijos[letter_tonum(c[i])];
		} else {
			std::cout << "Entro aca!" << std::endl;
			nodoRecorrer = nodoRecorrer->hijos[letter_tonum(c[i])];
		}

		if (i == c.length() - 1){
			char nuevoChar = (char) c[i];
			std::cout << nuevoChar << std::endl;
			Nodo nodoCopy(true, nuevoChar);
			for(int j = 0; j < 26; j++){
				Nodo nodoCopy2(false, nth_letter(j));
				nodoCopy2.hijos[j] = &nodoCopy2;
			}
			//std::cout << "LLEGAS PAPA, c[i] es: " << c[i] << std::endl;
			//nodoCopy.hijos[letter_tonum(c[i])]->significado = &s;
			nodoCopy.significado = &s;
			nodoRecorrer->hijos[c[i]] = &nodoCopy;
			//std::cout << *(nodoRecorrer->hijos[c[i]]) << std::endl;

		}
	}
}

template<class T>
void tp3::DiccString<T>::Borrar(aed2::String& c){
	this->claves.Eliminar(c);
	Nodo* nodoRecorrer = this->raiz;
	for(int i = 0; i < c.length(); ++i){
		nodoRecorrer = nodoRecorrer->hijos[c[i]];
		if(i == c.length() - 1){
			nodoRecorrer->significado = 0;
			nodoRecorrer->estaDef = false;
		}
	}	
}

template<class T>
bool tp3::DiccString<T>::Def(aed2::String& c) const{
	bool res = false;
	Nodo* nodoRecorrer = this->raiz;
	int i = 0;
	while(i < c.length() && nodoRecorrer->hijos[letter_tonum(c[i])] != NULL){
		nodoRecorrer = nodoRecorrer->hijos[letter_tonum(c[i])];
		if (i == c.length() - 1){
			res = nodoRecorrer->estaDef;
		}
		i++;
	}
	return res;
}

template<class T>
T tp3::DiccString<T>::Obtener(aed2::String& c) const{
	struct Nodo* nodoRecorrer = this->raiz;
	for(int i = 0; i < c.length(); ++i){
		//std::cout << "Como va? " << c[i] << " y soy el num: " << letter_tonum(c[i]) << std::endl;
		nodoRecorrer = nodoRecorrer->hijos[letter_tonum(c[i])];
		//std::cout << "AHI VA EL CAPITAN SEGMENTO" << std::endl;
		if(i == c.length() - 1) {
			return *(nodoRecorrer->significado);
		}
	}
}

template<class T>
aed2::String tp3::DiccString<T>::maxString() const{
	int i = 0; int j = 0;
	aed2::String res;
	struct Nodo* nodoRecorrer = this->raiz;
	struct Nodo* maximoNodo = nodoRecorrer->hijos[i];

	int maxIndice = 0;
	while(i < 26){
		if(nodoRecorrer->hijos[i]){
			maximoNodo = nodoRecorrer->hijos[i];
			maxIndice = i;
		}
		++i;
	}
	//res[j] = std::to_string(maxIndice);
	j++;

	bool termino = false;
	while (!(termino)){
		int i = 0;
		nodoRecorrer = maximoNodo;
		maximoNodo = NULL;
		while(i < 26){
			if(nodoRecorrer->hijos){
				maximoNodo = nodoRecorrer->hijos[i];
				maxIndice = i;
			}
			i++;
		}
		if(!maximoNodo){
			termino = true;
		} else {
			//res[j] = std::to_string(maxIndice);
			j++;
		}
	}
}

template<class T>
aed2::Conj<aed2::String>::Iterador tp3::DiccString<T>::Claves() const{
	return this->claves.CrearIt();
}
