#include "DiccString.h"

template<class T>
DiccString<T>::DiccString(){
	this->raiz->estaDef = false;
	this->raiz->hijos = new char[256];
	this->raiz->significado = 0;
	for(int i = 0; i < this->raiz->hijos; ++i){
		this->raiz->hijos = 0;
	}
	this->claves = Conj();
}

template<class T>
void DiccString<T>::Definir(String& c, T& s, DiccString& d){
	this->claves.AgregarRapido(c);

	Nodo* nodoRecorrer = d->raiz;
	for(int i = 0; i < c.length; i++){
		if(!(nodoRecorrer->hijos[c[i]])){
			Nodo* nuevo;
			nuevo->estaDef = false;
			nuevo->hijos = new char[256];
			nuevo->significado = 0;
			for(int j = 0; j < 256; j++) nuevo->hijos = 0;

			nodoRecorrer->hijos[c[i]] = 0;
			nodoRecorrer = nuevo;
		} else {
			nodoRecorrer = nodoRecorrer->hijos[c[i]];
		}

		if (i == c.length - 1){
			nodoRecorrer->hijos[c[i]]->estaDef = true;
			nodoRecorrer->hijos[c[i]]->significado = s;
		}
	}
}

template<class T>
void DiccString<T>::Borrar(String& c, DiccString& d){
	d.claves.Eliminar(c);
	Nodo* nodoRecorrer = d->raiz;
	for(int i = 0; i < c.length; ++i){
		nodoRecorrer = nodoRecorrer->hijos[c[i]];
		if(i == c.length-1){
			nodoRecorrer->significado = 0;
			nodoRecorrer->estaDef = false;
		}
	}	
}

template<class T>
T DiccString<T>::Obtener(String& c, const DiccString& d){
	Nodo* nodoRecorrer = d->raiz;
	for(int i = 0; i < c.length; ++i){
		nodoRecorrer = nodoRecorrer->hijos[c[i]];
		if(i == c.length - 1) return (nodoRecorrer->significado);
	}
}

template<class T>
String maxString(const DiccString& d){
	int i = 0; int j = 0;
	String res;
	Nodo* nodoRecorrer = d->raiz;
	Nodo* maximoNodo = nodoRecorrer->hijos[i];

	int maxIndice = 0;
	while(i < 256){
		if(nodoRecorrer->hijos[i]){
			maximoNodo = nodoRecorrer->hijos[i];
			maxIndice = i;
		}
		++i;
	}
	res[j] = std::stoi(maxIndice);
	j++;

	bool termino = false
	while (!termino){
		int i = 0;
		nodoRecorrer = maximoNodo;
		maximoNodo = 0;
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
			res[j] = std::stoi(maxIndice);
			j++;
		}
	}
}

template<class T>
Conj<String>::Iterador DiccString<T>::Claves(const DiccString& d){
	return d->claves.CrearIt();
}
