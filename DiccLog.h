#ifndef AED2_DICCLOG_H_
#define AED2_DICCLOG_H_

//REVISAR INCLUDE
#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "aed2/TiposBasicos.h"

namespace tp3
{
template<typename T>
	struct Nodo
	{
		Nodo(aed2::Nat k, T sig): key(k), signi(sig)
				, izq(NULL),der(NULL){}
		T signi;
		Nodo* der;
		Nodo* izq;
		Nodo* padre;
		aed2::Nat key;
		aed2::Nat altura;
		~Nodo(){
			//delete this;
		}
	};

	template <typename T>
	class DiccLog
	{


	private:
			Nodo<T>* raiz;

			// Dado un nodo, determina cuantos hijos posee.
			aed2::Nat cantHijos(const Nodo<T>* nodo);

		public:
			// Constructor
			DiccLog(){
				this->raiz = NULL;
			}

			// Toma un diccionarioLog y un valor natural. Revisa si existe clave
			// con el valor n.
			bool Def(const aed2::Nat n) const;

			// Toma un diccionarioLog y un valor natural. Devuelve el significado
			// que esta asociado al valor n.
			T Obtener(const aed2::Nat n) const;

			// Toma un diccionarioLog, un valor natural y un dato. Define una nueva clave
			// tomando el significado de parametro.
			void Definir(const aed2::Nat n, T sig);

			// Toma un diccionarioLog y un valor natural. Elimina la clave (y su significado)
			// del diccionario.
			void Borrar(aed2::Nat n);

			// Toma un nodo. Devuelve el nodo cuyo significado
			// contiene al valor que es maximo en d arbol.
			Nodo<T>* CalcularArbolMax(Nodo<T>* n);
			
	};
}
#endif // AED2_DICCLOG_H_INCLUDED
