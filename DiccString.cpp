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
tp3::DiccString<T>::DiccString(){
	this->raiz->estaDef = false;
	this->raiz->significado = 0;
	for(int i = 0; i < 256; ++i){
		this->raiz->hijos[i] = new Nodo;
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
			struct Nodo* nuevo;
			nuevo->estaDef = false;
			nuevo->hijos = new char[256];
			nuevo->significado = 0;
			for(int j = 0; j < 256; j++) nuevo->hijos = 0;

			nodoRecorrer->hijos[c[i]] = 0;
			nodoRecorrer = nuevo;
		} else {
			nodoRecorrer = nodoRecorrer->hijos[c[i]];
		}

		if (i == c.length() - 1){
			nodoRecorrer->hijos[c[i]]->estaDef = true;
			nodoRecorrer->hijos[c[i]]->significado = s;
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
T tp3::DiccString<T>::Obtener(aed2::String& c) const{
	struct Nodo* nodoRecorrer = this->raiz;
	for(int i = 0; i < c.length(); ++i){
		nodoRecorrer = nodoRecorrer->hijos[c[i]];
		if(i == c.length() - 1) return (nodoRecorrer->significado);
	}
}

template<class T>
aed2::String tp3::DiccString<T>::maxString() const{
	int i = 0; int j = 0;
	aed2::String res;
	struct Nodo* nodoRecorrer = this->raiz;
	struct Nodo* maximoNodo = nodoRecorrer->hijos[i];

	int maxIndice = 0;
	while(i < 256){
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
		while(i < 256){
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
