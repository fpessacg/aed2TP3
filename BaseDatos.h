#ifndef BASEDATOS_H_
#define BASEDATOS_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dupla.h"
#include "aed2/Dicc.h"
#include "Dato.h"
#include "Registro.h"
#include "Tabla.h"
#include "DiccLog.h"
#include "DiccString.h"
#include "aed2/TiposBasicos.h"

		typedef aed2::Lista < Registro >::Iterador ItLista;
		typedef aed2::Lista < Registro >::const_Iterador const_ItLista;

class BaseDatos
{
	public:
		BaseDatos():cantAccesoMax(0){}

		// Agrego una nueva tabla a la BD
		void AgregarTabla(const Tabla& t);

		// Agrego un Registro a una Tabla
		void InsertarEntrada(const Registro& r,const aed2::NombreTabla& t);

		//borrar un registro de una tabla
		void Borrar(const Registro& r, const aed2::NombreTabla& t);

		// Devuelvo un iterador a los nombres de las tablas de la BD
		aed2::Lista<aed2::NombreTabla>Tablas() const;

		// Devuelvo la tabla que me piden
		Tabla& DameTabla(const aed2::NombreTabla&);

		// Devuelve la tabla con mayor cantidad de accesos en BD
		const aed2::NombreTabla& TablaMaxima() const;

		// Devuelve el campo para los cuales dos tablas estan vinculadas
		const aed2::NombreCampo& CampoJoin(const aed2::NombreTabla& t1, const aed2::NombreTabla& t2) const;

		// Devuelve true si hay joint entra las dos tablas 
		bool HayJoin(const aed2::NombreTabla& t1, const aed2::NombreTabla& t2) const;

		// Elimina el Joint entre tablas
		void BorrarJoin(const aed2::NombreTabla& t1, const aed2::NombreTabla& t2);

		// Genera el Join entre dos tablas 
		void GenerarVistaJoin(const aed2::NombreTabla& t1, const aed2::NombreTabla& t2, const aed2::NombreCampo& ca) ;

		// Visualiza el Join entre dos tablas 

		aed2::Lista<Registro>::const_Iterador VistaJoin(const aed2::NombreTabla& t1, const aed2::NombreTabla& t2);


		// Busca los registro que conincidan con r en la tabla de la base de datos
		aed2::Lista<ItLista>::Iterador Buscar(const Registro& r, const aed2::NombreTabla& t) const;

		// Devuelve el nombre de la tabla que tuvo mayor cant de Accesos
		const aed2::NombreTabla& EncontrarMaximo( aed2::NombreTabla& t, const aed2::Conj<aed2::NombreTabla>&  conjTab);
		 
		// devuelve la cantidad de acsesos de una tabla
		aed2::Nat  CantidadDeAccesos(const aed2::NombreTabla& t) const;

		// devuelve los registros de una tabla
		aed2::Lista<Registro>::Iterador Registros(const aed2::NombreTabla& t) ;

	
	private:
		
		struct InfoJoin
		{
			InfoJoin(const Tabla& tabla, const aed2::NombreCampo& campo);
			aed2::NombreCampo campo;
			aed2::Lista<Dupla<Registro, bool> > regActualizar;   
			Tabla registroJoin;
		};
		
		struct InfoTabla
		{
			InfoTabla(const Tabla& tablaData);
			aed2::Dicc<aed2::NombreTabla, InfoJoin>  joins;
			Tabla tablaData;
		};
		
		aed2::Dicc<aed2::NombreTabla, InfoTabla> tablasBD;
		aed2::Nat cantAccesoMax;
		aed2::NombreTabla nombreAccesoMax;
		aed2::Lista<aed2::NombreTabla> tablaLista;
};


#endif // BASEDATOS_H_
