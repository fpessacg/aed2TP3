#include "DiccLog.h"

template<class T>
bool tp3::DiccLog<T>::Def(const aed2::Nat n) const{
	bool definido = false;
	Nodo* nodoRecorrera = this->raiz;

	while(nodoRecorrera != NULL && nodoRecorrera->key != n){
		if(nodoRecorrera->key > n){
			cout << "Aca " << nodoRecorrera->key << endl;
			nodoRecorrera = nodoRecorrera->izq;
		} else if(nodoRecorrera->key < n){
			nodoRecorrera = nodoRecorrera->der;
			cout << "Aca seg" << endl;
		}
	}
	return (nodoRecorrera != NULL);
}

template<class T>
T tp3::DiccLog<T>::Obtener(const aed2::Nat n) const {
	Nodo* nodoRecorrera = this->raiz;
	T res = *(nodoRecorrera->significado);

	while(nodoRecorrera != NULL && nodoRecorrera->key != n){
			//cout << "ACA NO" << endl;
		if(nodoRecorrera->key > n){
			nodoRecorrera = nodoRecorrera->izq;
			res = *(nodoRecorrera->significado);
		} else if(nodoRecorrera->key < n){
			nodoRecorrera = nodoRecorrera->der;
			res = *(nodoRecorrera->significado);
		}
	}
	return (res);
}

template<class T>
void tp3::DiccLog<T>::Definir(const aed2::Nat n, T sig){

		Nodo* nodoRecorrer = (this->raiz);
		Nodo* elPadre = NULL;
		while(nodoRecorrer != NULL && nodoRecorrer->key != n){
			elPadre = nodoRecorrer;
			if(n < nodoRecorrer->key) nodoRecorrer = nodoRecorrer->izq;
			else nodoRecorrer = nodoRecorrer->der;
		}

		if(nodoRecorrer == NULL){
			Nodo * z = new Nodo(n, sig);
			if(elPadre == NULL)
				this->raiz = z;
			else if(n < elPadre->key) elPadre->izq = z;
			else elPadre->der = z;
		}	
	}

	

template<class T>
void tp3::DiccLog<T>::Borrar(aed2::Nat n){
	Nodo* nodoRecorrer = this->raiz;
	Nodo* elPadre = this->raiz;

	while(nodoRecorrer){
		if(nodoRecorrer->significado > n){
			nodoRecorrer = nodoRecorrer->izq;
			elPadre = nodoRecorrer;
		} else if(nodoRecorrer->significado < n){
			nodoRecorrer = nodoRecorrer->der;
			elPadre = nodoRecorrer;
		}
		Nodo * hijoTemp = 0;
		if(cantHijos(nodoRecorrer) == 0) delete(nodoRecorrer);
		else{
			if(cantHijos(nodoRecorrer) == 1){
				if (!(nodoRecorrer->izq)){
					hijoTemp = nodoRecorrer->der;
				} else {
					hijoTemp = nodoRecorrer->izq;
				}
				delete (nodoRecorrer);
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

// template<class T>
// aed2::Nat DiccLog<T>::CalcularArbolMax(const Nodo* n){
// 	nodoRecorrer = this->raiz;
// 	while(!(nodoRecorrer->der)){
// 		nodoRecorrer = nodoRecorrer->der;
// 	}
// 	return nodoRecorrer->significado;
// }



