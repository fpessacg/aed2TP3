#ifndef BASEDATOS_H_
#define BASEDATOS_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dupla.h"
#include "aed2/Dicc.h"
#include "Auxiliares.h"
#include "Registro.h"
#include "Tabla.h"
#include "DiccLog.h"
#include "DiccString.h"
#include "aed2/TiposBasicos.h"

namespace aed2
{
	class BaseDatos
	{
		public:	
			
		
		private:
			
			struct InfoJoin
			{
			  NombreCampo campo;
			  Lista<Dupla<Registro, bool> > regActualizar;	   
			  Tabla registroJoin;
			};
			
			struct InfoTabla
			{
			  Dicc<NombreTabla, InfoJoin>  joins;
			  Tabla tablaData;
			};
			
			Dicc<NombreTabla, InfoTabla> tablasBD;
			Nat cantAccesoMax;
			NombreTabla nombreAccesoMax;
			Lista<NombreTabla> tablaLista;
	};


	// Agrego una nueva tabla a la BD
	void AgregarTabla(Tabla& t, BaseDatos& bd);

	// Agrego un Registro a una Tabla
	void InstertarEntrada(const Registro& r, Tabla& t, BaseDatos& b);

	//borrar un registro de una tabla
	void Borrar(const Registro& r, Tabla& t, BaseDatos& bd);

	// Devuelvo un iterador a los nombres de las tablas de la BD
	Lista<NombreTabla>::Iterador Tablas(const BaseDatos& bd);

	// Devuelvo la tabla que me piden
	Tabla& DameTabla(const NombreTabla&, const BaseDatos& bd);

	// Devuelve la tabla con mayor cantidad de accesos en BD
	NombreTabla& TablaMaxima(const BaseDatos& bd);

	// Devuelve el campo para los cuales dos tablas estan vinculadas
	NombreCampo& CampoJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd);

	// Devuelve true si hay joint entra las dos tablas 
	bool HayJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd);

	// Elimina el Joint entre tablas
	void BorrarJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd);

	// Genera el Join entre dos tablas 
	void GenerarVistaJoin(const Tabla& t1, const Tabla& t2, const NombreCampo& ca, const BaseDatos& bd);

	// Visualiza el Join entre dos tablas 
	Conj<Registro> VistaJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd);

	// Busca los registro que conincidan con r en la tabla de la base de datos
	Conj<Registro> Buscar(const Registro& r, const Tabla& t, const BaseDatos& bd);

	// Devuelve el nombre de la tabla que tuvo mayor cant de Accesos
	NombreTabla EncontrarMaximo(const NombreTabla& t, const Conj<NombreTabla>&  conjTab, const BaseDatos& bd);

	// devuelve la cantidad de acsesos de una tabla
	Nat CantidadDeAccesos(const NombreTabla& t, const BaseDatos& bd);

	// devuelve los registros de una tabla
	Conj<Registro> Registros(const Tabla& t, const BaseDatos& bd);




}
#endif // BASEDATOS_H_
