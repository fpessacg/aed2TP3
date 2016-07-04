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


class BaseDatos
{
	public:	
		
	
	private:
		
		struct InfoJoin
		{
		  NombreCampo campo;
		  aed2::Lista<Dupla<Registro, bool> > regActualizar;	   
		  Tabla registroJoin;
		};
		
		struct InfoTabla
		{
		  aed2::Dicc<NombreTabla, InfoJoin>  joins;
		  Tabla tablaData;
		};
		
		aed2::Dicc<NombreTabla, InfoTabla> tablasBD;
		aed2::Nat cantAccesoMax;
		NombreTabla nombreAccesoMax;
		aed2::Lista<NombreTabla> tablaLista;
};

BaseDatos();

// Agrego una nueva tabla a la BD
void AgregarTabla(Tabla& t);

// Agrego un Registro a una Tabla
void InstertarEntrada(const Registro& r, Tabla& t);

//borrar un registro de una tabla
void Borrar(const Registro& r, Tabla& t);

// Devuelvo un iterador a los nombres de las tablas de la BD
aed2::Lista<NombreTabla>::Iterador Tablas() const;

// Devuelvo la tabla que me piden
Tabla& DameTabla(const NombreTabla&) const;

// Devuelve la tabla con mayor cantidad de accesos en BD
NombreTabla& TablaMaxima() const;

// Devuelve el campo para los cuales dos tablas estan vinculadas
NombreCampo& CampoJoin(const Tabla& t1, const Tabla& t2) const;

// Devuelve true si hay joint entra las dos tablas 
bool HayJoin(const Tabla& t1, const Tabla& t2) const;

// Elimina el Joint entre tablas
void BorrarJoin(const Tabla& t1, const Tabla& t2) const;

// Genera el Join entre dos tablas 
void GenerarVistaJoin(const Tabla& t1, const Tabla& t2, const NombreCampo& ca) const;

// Visualiza el Join entre dos tablas 
aed2::Conj<Registro> VistaJoin(const Tabla& t1, const Tabla& t2) const;

// Busca los registro que conincidan con r en la tabla de la base de datos
aed2::Conj<Registro> Buscar(const Registro& r, const Tabla& t) const;

// Devuelve el nombre de la tabla que tuvo mayor cant de Accesos
NombreTabla EncontrarMaximo(const NombreTabla& t, const aed2::Conj<NombreTabla>&  conjTab) const;
 
// devuelve la cantidad de acsesos de una tabla
aed2::Nat CantidadDeAccesos(const NombreTabla& t) const;

// devuelve los registros de una tabla
aed2::Conj<Registro>::Iterador Registros(const Tabla& t) const;

#endif // BASEDATOS_H_
