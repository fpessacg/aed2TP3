#ifndef TABLA_H_
#define TABLA_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Auxiliares.h"
#include "Registro.h"
#include "aed2/TiposBasicos.h"


namespace aed2 {

	class Tabla {
		public:
			Tabla(const NombreTabla & nombre, const aed2::Conj < NombreCampo > &claves, const Registro & columnas)
			:nombre(nombre), cantAccesos(0) {
			} 
			
				// Agrego un registor a la tabla
			void AgregarRegistro(const Registro& r);

			// Borro un registro de la tabla
			void BorrarRegistro(Registro& crit);

			// Creo un Indice en el campo c de la tabla
			void Indexar(const NombreCampo& c);

			//Devuelvo el nombre de la tabla
			NombreTabla Nombre() const;

			//Devuelvo un conjunto de las claves de la tabla
			Conj<NombreCampo>::Iterador Claves();  

			// Devuelvo el conjunto de indices de la tabla
			Conj<NombreCampo>::Iterador Indices() const;

			// Devuelvo un iterador al conjunto de campos de la tabla
			Conj<NombreCampo>::Iterador CamposTabla() const;

			// Devuelvo el tipo del campo c de la tabla
			//~ TipoCampo TipoCampo(const NombreCampo& c) const;

			// Devuelvo un iterador a la lista de registros de la tabla
			Lista<Registro>::Iterador Registros();

			//Devuelvo la cantidad de accesos de la tabla 
			Nat CantidadDeAccesos() const;

			// Devuelvo el minimo dato de todos los registros para la tabla
			Dato Minimo(const NombreCampo& c) const;

			// Devuelvo el Maximo dato de todos los registros para la tabla
			Dato Maximo(const NombreCampo& c) const;

			// Devuelvo un bool que es true si se puede crear un indice en ese campo
			bool PuedeIndexar(const NombreCampo& c) const;
			
		private:
			typedef Lista < Registro >::Iterador ItLista;
			
			struct IndicesString {
				Dicc < String, Conj < ItLista > >indiceString;
				NombreCampo campo;
				String maxString;
				String minString;
			};
			struct IndicesNat {
				Dicc<Nat, Conj<ItLista> > indiceNat;
				NombreCampo campo;
				Nat maxNat;
				Nat minNat;
			};
			NombreTabla nombre;
			Nat cantAccesos;
			Dupla < IndicesString, IndicesNat > indices;
			Conj < NombreCampo > campos;
			Lista < Registro > registros;
			Conj < NombreCampo > claves;
	};



				/**
				 * inicializa una tabla vacía.
				 */
				//~ void aed2::Tabla( const NombreTabla& nombre, const aed2::Conj<NombreCampo>& claves, const Registro& columnas){}
				//~ :nombre(nombre), cantAccesos(0){}
				/**
				 * destruye el contenido de la tabla, liberando la memoria dinámica alocada.
				 */
				//~ ~Tabla();


	// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
	bool HayCoincidencia(const Registro& r, const Conj<NombreCampo>& cc, const Conj<Registro>& cr);

	// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
	Conj<Lista<Registro>::Iterador>::Iterador Coincidencias(const Registro& r, Lista<Registro>::Iterador itLisReg);

	// Devuelve la comlumna de c en cr
	Conj<Dato> DameColumna(const NombreCampo& r, const Conj<Registro>& cr);

	// Devuelve true si los campos del registros son los mismos que de la tabla
	bool MismosTipos(const Registro& r, const Tabla& t);



	//~ // Agrego un registor a la tabla
	//~ void Tabla::AgregarRegistro(const Registro& r){
		//~ Lista<Registro> registros =  registros;
		//~ registros;
		//~ int a =1;
	//~ }




}
#endif          // TABLA_H_
