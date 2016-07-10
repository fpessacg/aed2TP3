#include "DiccString.h"
#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "aed2/TiposBasicos.h"
#include <string>

using namespace std;

template<class T>
tp3::DiccString<T>::DiccString(){
	Nodo raizCopy(false,true);
	this->raiz = &raizCopy;
	//this->raiz->hijos = new Nodo[256];
	for(int i = 0; i < 256; ++i){
		Nodo nodoCopy(false,false);
		this->raiz->hijos[i] = &nodoCopy;
	}
	aed2::Conj<aed2::String> clavesTemp;
	this->claves = clavesTemp;
}

template<class T>
void tp3::DiccString<T>::Definir(aed2::String& c, T& s){
	this->claves.AgregarRapido(c);

	// Comienzo desde la raiz
	struct Nodo* nodoRecorrer = this->raiz;
		// Recorro hasta la longitud de la clave
	for(int i = 0; i < c.length(); i++){
		// Pregunto si el caracter al que se esta evaluando ya fue creado
		// anteriormente.
		//cout << "i ahora vale: " << i << endl;
		//std::cout << "bool: " << (bool) nodoRecorrer->hijos[c[i]]->fueUsado 
		//	<< std::endl;
		
		if(!(nodoRecorrer->hijos[c[i]]->fueUsado)){
			//nodoRecorrer = nodoRecorrer->hijos[c[i]];
			// Caso negativo, creo el nuevo nodo conteniendo los hijos
			// En vacio
			char nuevoChar = (char) c[i];
			std::cout << "quien te conoce nuevoChar: " << nuevoChar << std::endl;
			Nodo nuevo(false,true);
			//nuevo.significado = 0;
			for(int j = 0; j < 256; j++) {
				// Nodos hijos del nuevo caracter
				Nodo nodoCopy(false,false);
				nuevo.hijos[j] = &nodoCopy;
			}
			// Asigno el nuevo y avanzo al proximo
			nodoRecorrer->hijos[c[i]] = &nuevo;
			nodoRecorrer = nodoRecorrer->hijos[c[i]];
			if(i == c.length() - 1) cout << c[i];
			if (i == c.length() - 1){
			std::cout << "LLEGAS PAPA, c[i] es: " << c[i] << std::endl;
			//nodoCopy.hijos[letter_tonum(c[i])]->significado = &s;
			Nodo nuevo(false,true);
			//nuevo.significado = 0;
			for(int j = 0; j < 256; j++) {
				// Nodos hijos del nuevo caracter
				Nodo nodoCopy(false,false);
				nuevo.hijos[j] = &nodoCopy;
			}
			nodoRecorrer = &nuevo;
			nodoRecorrer->significado = &s;
			break;
			//std::cout << *(nodoRecorrer->hijos[c[i]]->significado) << std::endl;
			}
			//std::cout << (bool) nodoRecorrer->hijos[c[i]]->fueUsado 
			//<< std::endl;
		} else {
			std::cout << "Entro aca! con i = " << i << std::endl;
			nodoRecorrer = nodoRecorrer->hijos[c[i]]->hijos[c[i+1]];
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
	Nodo* nodoRecorrer = this->raiz;
	for(int i = 0; i < c.length(); ++i){
		if(i == c.length() - 1) {
			return *(nodoRecorrer->significado);
		}
		std::cout << "Como va? " << c[i] << " y soy el num: " << i << std::endl;
		nodoRecorrer = nodoRecorrer->hijos[c[i]];

		//std::cout << "u" << std::endl;
		//std::cout << "AHI VA EL CAPITAN SEGMENTO con " << *(nodoRecorrer->significado) 
		//	<< std::endl;
		
	}
}

template<class T>
aed2::String tp3::DiccString<T>::maxString() const{
	int i = 0; int j = 0;
	aed2::String res;
	struct Nodo* nodoRecorrer = this->raiz;
	struct Nodo* maximoNodo = nodoRecorrer->hijos[i];

	int maxIndice = 0;
	while(i < 27){
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
		while(i < 27){
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
