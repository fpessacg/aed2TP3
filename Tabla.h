#ifndef TABLA_H_
#define TABLA_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "Registro.h"
#include "aed2/TiposBasicos.h"


class Tabla {
	public:
		typedef aed2::Lista < Registro >::Iterador ItLista;
		typedef aed2::Lista < Registro >::const_Iterador const_ItLista;
		
		 			
		
		
		Tabla(const aed2::NombreTabla & nombre, const aed2::Conj < aed2::NombreCampo > &claves, const Registro & columnas)
		:nombre(nombre), cantAccesos(0) {} 
		
			// Agrego un registor a la tabla
		void AgregarRegistro(const Registro& r);

		// Borro un registro de la tabla
		void BorrarRegistro(const Registro& crit);

		// Creo un Indice en el campo c de la tabla
		void Indexar(const NombreCampo& c);

		//Devuelvo el nombre de la tabla
		const NombreTabla& Nombre() const;

		//Devuelvo un conjunto de las claves de la tabla
		aed2::Conj<NombreCampo>::const_Iterador Claves() const;  

		// Devuelvo el conjunto de indices de la tabla
		aed2::Conj<NombreCampo> Indices() const;

		// Devuelvo un iterador al conjunto de campos de la tabla
		aed2::Conj<NombreCampo>::const_Iterador CamposTabla() const;

		// Devuelvo el tipo del campo c de la tabla
		TipoCampo TipoDelCampo(const NombreCampo& c) const;

		// Devuelvo un iterador a la lista de registros de la tabla
		aed2::Lista<Registro>::const_Iterador Registros() const;
		aed2::Lista<Registro>::Iterador Registros();
		
		//Devuelvo la cantidad de accesos de la tabla 
		aed2::Nat CantidadDeAccesos() const;

		// Devuelvo el minimo dato de todos los registros para la tabla
		const Dato Minimo(const NombreCampo& c) const;

		// Devuelvo el Maximo dato de todos los registros para la tabla
		const Dato Maximo(const NombreCampo& c) const;

		// Devuelvo un bool que es true si se puede crear un indice en ese campo
		bool PuedeIndexar(const NombreCampo& c) const;

		// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
		static bool HayCoincidencia(const Registro& r, const aed2::Conj<NombreCampo>& cc, const aed2::Conj<Registro>& cr);

		// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
		aed2::Conj<ItLista>::Iterador Coincidencias(const Registro& r, ItLista itLisReg);

		// Devuelve la comlumna de c en cr
		static aed2::Conj<Dato> DameColumna(const NombreCampo& c, const aed2::Lista<Registro>& lr);

		// Devuelve true si los campos del registros son los mismos que de la tabla
		bool MismosTipos(const Registro& r);
		
	private:
		struct IndicesString {
			aed2::Dicc<aed2::String, aed2::Conj<ItLista> >indiceString;
			NombreCampo campo;
			Dato* maxString;		//Uso un puntero a dato porq no tengo constructor sin parametros
			Dato* minString;		// Cuando no tengo dato apunta a NULL y si no al dato correspondiente
		};
		struct IndicesNat {
			aed2::Dicc<aed2::Nat, aed2::Conj<ItLista> > indiceNat;
			NombreCampo campo;
			Dato* maxNat;
			Dato* minNat;
		};
		NombreTabla nombre;
		aed2::Nat cantAccesos;
		Dupla < IndicesString, IndicesNat > indices;
		aed2::Conj < NombreCampo > campos;
		aed2::Lista< Registro > registros;
		aed2::Conj < NombreCampo > claves;
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



//~ // Agrego un registor a la tabla
//~ void Tabla::AgregarRegistro(const Registro& r){
	//~ Lista<Registro> registros =  registros;
	//~ registros;
	//~ int a =1;
//~ }

#endif          // TABLA_H_
