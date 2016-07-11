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
		typedef aed2::Lista < tp3::Registro >::Iterador ItLista;
		typedef aed2::Lista < tp3::Registro >::const_Iterador const_ItLista;
		
		
		
		Tabla(const aed2::NombreTabla& nombre, const aed2::Conj <aed2::NombreCampo>& claves, const aed2::Conj<aed2::Columna>& columnas);
		//~ :nombre(nombre), claves(claves), cantAccesos(0), campos(columnas.campos());
		
		~Tabla();
			// Agrego un registor a la tabla
		void AgregarRegistro(const tp3::Registro& r);

		// Borro un registro de la tabla
		void BorrarRegistro(const tp3::Registro& crit);

		// Creo un Indice en el campo c de la tabla
		void Indexar(const aed2::NombreCampo& c);

		//Devuelvo el nombre de la tabla
		const aed2::NombreTabla& Nombre() const;

		//Devuelvo un conjunto de las claves de la tabla
		aed2::Conj<aed2::NombreCampo> Claves() const;  

		// Devuelvo el conjunto de indices de la tabla
		aed2::Conj<aed2::NombreCampo> Indices() const;

		// Devuelvo el conjunto de campos de la tabla
		aed2::Conj<aed2::NombreCampo> CamposTabla() const;

		// Devuelvo el tipo del campo c de la tabla
		aed2::TipoCampo TipoDelCampo(const aed2::NombreCampo& c) const;

		// Devuelvo un iterador a la lista de registros de la tabla
		const aed2::Lista<tp3::Registro>& Registros() const;
		aed2::Lista<tp3::Registro>& Registros();
		
		//Devuelvo la cantidad de accesos de la tabla 
		aed2::Nat CantidadDeAccesos() const;

		// Devuelvo el minimo dato de todos los registros para la tabla
		const tp3::Dato Minimo(const aed2::NombreCampo& c) const;

		// Devuelvo el Maximo dato de todos los registros para la tabla
		const tp3::Dato Maximo(const aed2::NombreCampo& c) const;

		// Devuelvo un bool que es true si se puede crear un indice en ese campo
		bool PuedeIndexar(const aed2::NombreCampo& c) const;

		// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
		static bool HayCoincidencia(const tp3::Registro& r, const aed2::Conj<aed2::NombreCampo>& cc, const aed2::Conj<tp3::Registro>& cr);

		// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
		aed2::Lista<ItLista> Coincidencias(const tp3::Registro& r, aed2::Lista<tp3::Registro>& lisReg);

		// Devuelve la comlumna de c en cr
		static aed2::Conj<tp3::Dato> DameColumna(const aed2::NombreCampo& c, const aed2::Lista<tp3::Registro>& lr);

		// Devuelve true si los campos del registros son los mismos que de la tabla
		bool MismosTipos(const tp3::Registro& r);

		// Devuelvo el conjunto de Columnas de la tabla
		aed2::Conj<aed2::Columna> dameColumnas() const;
		
	private:
		struct IndicesString {
			aed2::Dicc<aed2::String, aed2::Lista<ItLista> >indiceString;
			aed2::NombreCampo campo;
			tp3::Dato* maxString;		//Uso un puntero a dato porq no tengo constructor sin parametros
			tp3::Dato* minString;		// Cuando no tengo dato apunta a NULL y si no al dato correspondiente
		};
		struct IndicesNat {
			aed2::Dicc<aed2::Nat, aed2::Lista<ItLista> > indiceNat;
			aed2::NombreCampo campo;
			tp3::Dato* maxNat;
			tp3::Dato* minNat;
		};
		aed2::NombreTabla nombre;
		aed2::Nat cantAccesos;
		Dupla<IndicesString, IndicesNat> indices;
		aed2::Conj<aed2::NombreCampo> campos;
		aed2::Conj<aed2::Columna> columnas; 
		aed2::Lista<tp3::Registro> registros;
		aed2::Conj<aed2::NombreCampo> claves;
};



			/**
			 * inicializa una tabla vacía.
			 */
			//~ void aed2::Tabla( const aed2::NombreTabla& nombre, const aed2::Conj<aed2::NombreCampo>& claves, const Registro& columnas){}
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
