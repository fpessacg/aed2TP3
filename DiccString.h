#ifndef AED2_DICCSTRING_H_
#define AED2_DICCSTRING_H_

//REVISAR INCLUDE
#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "aed2/TiposBasicos.h"
#include <string>

namespace tp3
{
	template<typename T>
	class DiccString
	{
		private:
			struct Nodo
			{
				Nodo(bool b, char ca) : estaDef(b), c(ca){}
				bool estaDef;
				Nodo* hijos[256];
				T* significado; 
				char c;
			};

			Nodo* raiz;
			aed2::Conj<aed2::String> claves;

		public:
			// Constructor
			DiccString();

			// Constructor por copia
			DiccString(const DiccString& copyDic);

			// Toma un dicString, un dato y un string. Define una nueva clave
			// con dicha cadena de caracteres, cuyo significado asignado es el dato.
			void Definir(aed2::String& c, T& s);

			// Toma un string y un dicString. Borra la clave con su significado en el
			// diccionario otorgado.
			void Borrar(aed2::String& c);

			// Toma un dicString y devuelve el mayor caracter.
			aed2::String maxString() const;

			// Dado un string y un diccionario, determina si la clave c se encuentra
			// en el diccionario d.
			bool Def(aed2::String& c) const;

			// Dado un string y un diccionario, devuelve el significado asociado a la 
			// clave c en el diccionario otorgado.
			T Obtener(aed2::String& c) const;

			// Dado un diccionario, retorna un iterador apuntando al primer elemento
			// del conjunto de claves del diccionario.
			aed2::Conj<aed2::String>::Iterador Claves() const;


			char nth_letter(int n) const;

			int letter_tonum(char ch) const;
			/*class Iterador{
				public:
					// Dado un diccionarioLog, crea un iterador que al significado pasado
					// por parametro
					Iterador(const DiccString& d, T significado);

					const T& Siguiente() const;

					bool HaySiguiente() const;

				private:
			//		friend Nodo* iterator; 

			};*/
	};


	//char intToAlphabet( int i )
	//{
   	//	return static_cast<char>('A' - 1 + i);
	//}
}
#endif // AED2_DICCSTRING_H_INCLUDED
