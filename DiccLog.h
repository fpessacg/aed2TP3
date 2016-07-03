#ifndef AED2_DICCLOG_H_
#define AED2_DICCLOG_H_

//REVISAR INCLUDE
#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Auxiliares.h"
#include "aed2/TiposBasicos.h"

namespace aed2

{
	template<typename T>
	class DiccLog
	{
		private:
			struct Nodo
			{
				T* significado;
				Nodo* der;
				Nodo* izq;
				Nodo* padre;
				Nat key;
				Nat altura;
			};

			Nodo* raiz;

			// Dado un nodo, determina cuantos hijos posee.
			Nat cantHijos(const Nodo* nodo);

		public:
			// Constructor
			DiccLog(){
				this->raiz = 0;
			}

			// Toma un diccionarioLog y un valor natural. Revisa si existe clave
			// con el valor n.
			bool Def(const DiccLog& d, Nat n);

			// Toma un diccionarioLog y un valor natural. Devuelve el significado
			// que esta asociado al valor n.
			T Obtener(const DiccLog& d, Nat n);

			// Toma un diccionarioLog, un valor natural y un dato. Define una nueva clave
			// tomando el significado de parametro.
			void Definir(DiccLog& d, Nat n, T& sig);

			// Toma un diccionarioLog y un valor natural. Elimina la clave (y su significado)
			// del diccionario.
			void Borrar(DiccLog& d, Nat n);

			// Toma un nodo. Devuelve el nodo cuyo significado
			// contiene al valor que es maximo en d arbol.
			Nat CalcularMaxArbol(const Nodo* n);
			

	};


}
#endif // AED2_DICCLOG_H_INCLUDED
