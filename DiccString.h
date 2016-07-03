#ifndef AED2_DICCSTRING_H_
#define AED2_DICCSTRING_H_

//REVISAR INCLUDE
#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Auxiliares.h"
#include "aed2/TiposBasicos.h"
#include <string>

namespace aed2
{
	template<typename T>
	class DiccString
	{
		private:
			struct Nodo
			{
				bool estaDef;
				Nodo* hijos[];
				T* significado; 
			};

			Nodo* raiz;
			Conj<String> claves;

		public:
			// Constructor
			DiccString();

			// Constructor por copia
			DiccString(const DiccString& copyDic);

			// Toma un dicString, un dato y un string. Define una nueva clave
			// con dicha cadena de caracteres, cuyo significado asignado es el dato.
			void Definir(String& c, T& s, DiccString& d);

			// Toma un string y un dicString. Borra la clave con su significado en el
			// diccionario otorgado.
			void Borrar(String& c, DiccString& d);

			// Toma un dicString y devuelve el mayor caracter.
			String maxString(const DiccString& d);

			// Dado un string y un diccionario, determina si la clave c se encuentra
			// en el diccionario d.
			bool Def(String& c, const DiccString& d);

			// Dado un string y un diccionario, devuelve el significado asociado a la 
			// clave c en el diccionario otorgado.
			T Obtener(String& c, const DiccString& d);

			// Dado un diccionario, retorna un iterador apuntando al primer elemento
			// del conjunto de claves del diccionario.
			Conj<String>::Iterador Claves(const DiccString& d);

			class Iterador{
				public:
					// Dado un diccionarioLog, crea un iterador que al significado pasado
					// por parametro
					Iterador(const DiccString& d, T significado);

					const T& Siguiente() const;

					bool HaySiguiente() const;

				private:
			//		friend Nodo* iterator; 

			};

	};


}
#endif // AED2_DICCSTRING_H_INCLUDED
