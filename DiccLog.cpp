#include "DiccLog.h"

template<class T>
bool DiccLog<T>::Def(const DiccLog& d, Nat n){
	bool definido = false;
	Nodo* nodoRecorrer = d;

	while(nodoRecorrer && definido == false){
		if(nodoRecorrer->significado > n){
			nodoRecorrer = nodoRecorrer->izq;
		} else if(nodoRecorrer->significado < n){
			nodoRecorrer = nodoRecorrer->der;
		} else {
			definido = true;
		}
	}
	return definido;
}

template<class T>
T DiccLog<T>::Obtener(DiccLog& d, Nat n){
	Nodo* nodoRecorrer;

	while(true){
		if(nodoRecorrer->key == n){
			return nodo->significado;
		} else {
			if(nodoRecorrer->key > n){
				nodoRecorrer->izq;
			} else {
				nodoRecorrer->der;
			}
		}

	}
}

template<class T>
void DiccLog<T>::Definir(DiccLog& d, Nat n, T& sig){
	if !(d) {
		Nodo* nuevoNodo;
		nuevoNodo->significado = sig;
		nuevoNodo->izq = 0;
		nuevoNodo->der = 0;
		nuevoNodo->padre = 0;
		nuevoNodo->key = n;
		nuevoNodo->altura = 1;

		d->raiz = nuevoNodo;		
	} else {
		Nodo* nodoRecorrer = d->raiz;
		Nodo* elPadre = 0;
		
		while(true){
			if(n == nodoRecorrer->key) break;

			elPadre = nodoRecorrer;
			porIzq = ((nodoRecorrer->key) > num);
			if(porIzq){
				nodoRecorrer = nodoRecorrer->izq;
			} else {
				nodoRecorrer = nodoRecorrer->der;
			}

			if (nodoRecorrer == 0){
				if(porIzq){
					elPadre->izq->significado = sig;
					elPadre->izq->izq = 0;
					elPadre->izq->der = 0;
					elPadre->izq->padre = elPadre;
					elPadre->izq->key = n;
					elPadre->izq->altura = 1;
					break;
				} else {
					elPadre->der->significado = sig;
					elPadre->der->izq = 0;
					elPadre->der->der = 0;
					elPadre->der->padre = elPadre;
					elPadre->der->key = n;
					elPadre->der->altura = 1;
					break;
				}
			}
		}
	}
}

template<class T>
void DiccLog<T>::Borrar(DiccLog& d, Nat n){
	Nodo* nodoRecorrer = d->raiz;
	Nodo* elPadre = d->raiz;

	while(nodoRecorrer){
		if(nodoRecorrer->significado > num){
			nodoRecorrer = nodoRecorrer->izq;
			elPadre = nodoRecorrer;
		} else if(nodoRecorrer->significado < num){
			nodoRecorrer = nodoRecorrer->der;
			elPadre = nodoRecorrer;
		}

		if(cantHijos(nodoRecorrer) == 0) delete(nodoRecorrer);
		else{
			if(cantHijos(nodoRecorrer) == 1){
				if (!(nodoRecorrer->izq)){
					Nodo* hijoTemp = nodoRecorrer->der;
				} else {
					Nodo* hijoTemp = nodoRecorrer->izq;
				}
				delete(nodoRecorrer);
			}
		}

		if(!(elPadre->izq)){
			elPadre->izq = hijoTemp;
		} else {
			elPadre->der = hijoTemp;
		}
	}
	///Nodo* maxNodo = calcularArbolMax(nodoRecorrer->izq); 
	// -> Hay un error en la interfaz -> TURBIO
	// Nat maxValor = maxNodo->significado; 
	// delete (maxNodo);

    // nodoRecorrer->significado = maxValor;
}

template<class T>
Nat DiccLog<T>::calcularArbolMax(Nodo* n){
	nodoRecorrer = d->raiz;
	while(!(nodoRecorrer->der)){
		nodoRecorrer = nodoRecorrer->der;
	}
	return nodoRecorrer->significado;
}



