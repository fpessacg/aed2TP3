#include "DiccLog.h"
#include <iostream>

using namespace std;

template<class T>
bool tp3::DiccLog<T>::Definido(const aed2::Nat n) const{
	bool definido = false;
	Nodo<T>* nodoRecorrera = this->raiz;

	while(nodoRecorrera != NULL && nodoRecorrera->key != n){
		if(nodoRecorrera->key > n){
			nodoRecorrera = nodoRecorrera->izq;
		} else if(nodoRecorrera->key < n){
			nodoRecorrera = nodoRecorrera->der;
		}
	}
	return (nodoRecorrera != NULL);
}

template<class T>
T tp3::DiccLog<T>::Obtener(const aed2::Nat n) const {
	Nodo<T>* nodoRecorrera = this->raiz;
	T res = (nodoRecorrera->signi);

	while(nodoRecorrera != 0 && nodoRecorrera->key != n){
		if(nodoRecorrera->key > n){
			nodoRecorrera = nodoRecorrera->izq;
			res = (nodoRecorrera->signi);
		} else if(nodoRecorrera->key < n){
			nodoRecorrera = nodoRecorrera->der;
			res = (nodoRecorrera->signi);
		}
	}
	return (res);
}

template<class T>
void tp3::DiccLog<T>::Definir(const aed2::Nat n, T sig){

		Nodo<T>* nodoRecorrer = (this->raiz);
		Nodo<T>* elPadre = NULL;
		while(nodoRecorrer != NULL && nodoRecorrer->key != n){
			elPadre = nodoRecorrer;
			if(n < nodoRecorrer->key) nodoRecorrer = nodoRecorrer->izq;
			else nodoRecorrer = nodoRecorrer->der;
		}

		if(nodoRecorrer == NULL){
			Nodo<T>* z = new Nodo<T>(n, sig);
			if(elPadre == NULL)
				this->raiz = z;
			else if(n < elPadre->key) {elPadre->izq = z; elPadre->izq->padre = elPadre;}
			else{ elPadre->der = z; elPadre->der->padre = elPadre;}
		}	
	}

	

template<class T>
void tp3::DiccLog<T>::Borrar(aed2::Nat n){
	Nodo<T>* nodoRecorrer = this->raiz;
	Nodo<T>* elPadre = this->raiz;

	while(nodoRecorrer != NULL && nodoRecorrer->key != n) {
		if (nodoRecorrer->key > n) {
			elPadre = nodoRecorrer;
			nodoRecorrer = nodoRecorrer->izq;
		} else if (nodoRecorrer->key < n) {
			elPadre = nodoRecorrer;
			nodoRecorrer = nodoRecorrer->der;
		}
	}
	Nodo<T> *hijoTemp = 0;
	if (cantHijos(nodoRecorrer) == 0)
	{
		//delete (nodoRecorrer);
		if(nodoRecorrer->padre->izq == nodoRecorrer) {
			delete (nodoRecorrer->padre->izq);
			nodoRecorrer->padre->izq = NULL;
		}
		else {
			delete (nodoRecorrer->padre->der);
			nodoRecorrer->padre->der = NULL;
		}
	}
	else if (cantHijos(nodoRecorrer) == 1) {
		if (!(nodoRecorrer->izq)) {
			hijoTemp = nodoRecorrer->der;
		} else {
			hijoTemp = nodoRecorrer->izq;
		}
		if(nodoRecorrer->padre->izq == nodoRecorrer) {
			elPadre = nodoRecorrer->padre;
			delete (nodoRecorrer->padre->izq);
			nodoRecorrer->padre->izq = NULL;
		}
		else
		{
			elPadre = nodoRecorrer->padre;
			delete (nodoRecorrer->padre->der);
			nodoRecorrer->padre->der = NULL;
		}
		if((elPadre->izq) == NULL){
			elPadre->izq = hijoTemp;
			hijoTemp->padre = elPadre;
		} else {
			elPadre->der = hijoTemp;
			hijoTemp->padre = elPadre;
		}
	}
	else {
		Nodo<T> *maxNodo;
		maxNodo = this->CalcularArbolMax(nodoRecorrer->izq);

		aed2::Nat maxValorKey = maxNodo->key;
		T maxValorSig = maxNodo->signi;

		if (cantHijos(maxNodo) == 1) {
			Nodo<T> *tempPtr = maxNodo->izq;
			delete (maxNodo->padre->der);
			maxNodo->padre->der = tempPtr;

		} else {
			if(maxNodo->padre->der == maxNodo) {
				delete (maxNodo->padre->der);
				maxNodo->padre->der = NULL;
			} else {
				delete (maxNodo->padre->izq);
				maxNodo->padre->izq = NULL;
			}
		}
		nodoRecorrer->key = maxValorKey;
		nodoRecorrer->signi = maxValorSig;
	}
}




template<class T>
tp3::Nodo<T>* tp3::DiccLog<T>::CalcularArbolMax(Nodo<T>* n){
	Nodo<T>* nodoRecorrer = n;
	while((nodoRecorrer->der) != NULL){
		nodoRecorrer = nodoRecorrer->der;
	}
	return nodoRecorrer;
}

//template<class T>
//aed2::Nat tp3::DiccLog<T>::CalcularArbolMax(const Nodo<T>* n){
//	nodoRecorrer = this->raiz;
//	while(!(nodoRecorrer->der)){
//		nodoRecorrer = nodoRecorrer->der;
//	}
//	return nodoRecorrer->signi;
//}

template<class T>
aed2::Nat tp3::DiccLog<T>::cantHijos(const Nodo<T>* nod){
	aed2::Nat res = 0;
	if(nod->der != NULL) res++;
	if(nod->izq != NULL) res++;
	return res;
}
