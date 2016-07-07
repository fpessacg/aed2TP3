#include "BaseDatos.h"

using namespace aed2;

//Cosas que faltan:
//------------------
	// AgregarTabla
	// vistaJoin tengo problemas con const_ 
	// -> Basicamente el problema con vistaJoin es que no tiene que ser const, lo saque
	// generarVistaJoin  falta terminar 


//~ BaseDatos::BaseDatos(){
	//~ Lista vacioL();
	//~ Dicc vacioD();
	//~ this->tablasBD = vacioD;
	//~ this->tablasLista = vacioL;
	//~ this->cantAccesoMax = 0;
	//~ this->nombreAccesoMax = "";
//~ }


// Agrego una nueva tabla a la BD
void BaseDatos::AgregarTabla(const Tabla& t){
	tablaLista.AgregarAtras(t.Nombre());
	//struct InfoTabla nueva;
	//nueva.tablaData = t; 
	//this->tablasBD.Definir(t.Nombre(), nueva);
}

// Devuelvo un iterador a los nombres de las tablas de la BD
aed2::Lista<NombreTabla> BaseDatos::Tablas() const{
	return  tablaLista;
}

// Devuelvo la tabla que me piden
Tabla& BaseDatos::DameTabla(const NombreTabla& t){
	return tablasBD.Significado(t).tablaData;
}

// Devuelve true si hay joint entra las dos tablas 
bool BaseDatos::HayJoin(const NombreTabla& t1, const NombreTabla& t2) const{
	return tablasBD.Significado(t1).joins.Definido(t2);
}

// Devuelve el campo para los cuales dos tablas estan vinculadas
const NombreCampo& BaseDatos::CampoJoin(const NombreTabla& t1, const NombreTabla& t2) const{
	struct InfoTabla t1Info = tablasBD.Significado(t1);
	return t1Info.joins.Significado(t2).campo;
}

// Agrego un Registro a una Tabla
void BaseDatos::InsertarEntrada(const Registro& r, const NombreTabla& t){
	struct InfoTabla infoT = tablasBD.Significado(t);
	infoT.tablaData.AgregarRegistro(r);
	if(infoT.tablaData.CantidadDeAccesos() > cantAccesoMax){
		cantAccesoMax = infoT.tablaData.CantidadDeAccesos();
		nombreAccesoMax = t;
	}
	Lista<NombreTabla>::Iterador itTablas = tablaLista.CrearIt();
	while(itTablas.HaySiguiente()){
		struct InfoTabla infoTabRev = tablasBD.Significado(itTablas.Siguiente());
		// Pregunto si hay alguna tabla que tenga join con la tabla que modifique t
		if(infoTabRev.joins.Definido(t)){
			struct InfoJoin infoJoinRev = infoTabRev.joins.Significado(t);
			Dupla<Registro, bool> dup;
			dup.x = r; dup.y = false;
			infoJoinRev.regActualizar.AgregarAtras(dup);
		}
		// Pregunto si la tabla t tiene join con alguna tabla 
		if(infoT.joins.Definido(itTablas.Siguiente())){
			struct InfoJoin infoJoinT = infoT.joins.Significado(itTablas.Siguiente());
			Dupla<Registro, bool> dup;
			dup.x = r; dup.y = false;
			infoJoinT.regActualizar.AgregarAtras(dup);
		}
		itTablas.Avanzar();
	}
}

//borrar un registro de una tabla
void BaseDatos::Borrar(const Registro& r, const NombreTabla& t){
	struct InfoTabla infoT = tablasBD.Significado(t);
	if(infoT.tablaData.CantidadDeAccesos() > cantAccesoMax){
		cantAccesoMax = infoT.tablaData.CantidadDeAccesos();
		nombreAccesoMax = t;
	}
	Lista<NombreTabla>::Iterador itTablas = tablaLista.CrearIt();
	while(itTablas.HaySiguiente()){
		struct InfoTabla infoTabRev = tablasBD.Significado(itTablas.Siguiente());
		// Pregunto si hay alguna tabla que tenga join con la tabla que modifique t
		if(infoTabRev.joins.Definido(t)){
			struct InfoJoin infoJoinRev = infoTabRev.joins.Significado(t);
			Dupla<Registro, bool> dup;
			dup.x = r; dup.y = true;
			infoJoinRev.regActualizar.AgregarAtras(dup);
		}
		// Pregunto si la tabla t tiene join con alguna tabla 
		if(infoT.joins.Definido(itTablas.Siguiente())){
			struct InfoJoin infoJoinT = infoT.joins.Significado(itTablas.Siguiente());
			Dupla<Registro, bool> dup;
			dup.x = r; dup.y = true;
			infoJoinT.regActualizar.AgregarAtras(dup);
		}
		itTablas.Avanzar();
	}
	infoT.tablaData.BorrarRegistro(r);
}

// Devuelve la tabla con mayor cantidad de accesos en BD
const NombreTabla& BaseDatos::TablaMaxima() const{
	return nombreAccesoMax;
}

// Elimina el Joint entre tablas
void BaseDatos::BorrarJoin(const NombreTabla& t1, const NombreTabla& t2){
	struct InfoTabla t1Info = tablasBD.Significado(t1);
	t1Info.joins.Borrar(t2);

	struct InfoTabla t2Info = tablasBD.Significado(t2);
	t2Info.joins.Borrar(t1);
}

// Busca los registro que conincidan con r en la tabla de la base de datos
aed2::Lista<ItLista>::Iterador BaseDatos::Buscar(const Registro& r, const NombreTabla& t) const{
	struct InfoTabla t1Info = tablasBD.Significado(t);
	return t1Info.tablaData.Coincidencias(r, t1Info.tablaData.Registros());
}




// Visualiza el Join entre dos tablas
aed2::Lista<Registro>::const_Iterador BaseDatos::VistaJoin( const  NombreTabla& t1, const NombreTabla& t2){
	struct InfoTabla t1Info = tablasBD.Significado(t1);
	struct InfoJoin joinsT1T2 = t1Info.joins.Significado(t2);
	aed2::Lista<Dupla<Registro, bool> >::Iterador itRegAct = joinsT1T2.regActualizar.CrearIt();
	// Si no hay registro p actualizar devuelvo un it a la lista de reg del join
	if(!(itRegAct.HaySiguiente() ) ){
		return joinsT1T2.registroJoin.Registros();
	} else {  // en caso contrario voy revisando cada uno si fueron agregados o borrados
		while(itRegAct.HaySiguiente()){
			Registro regCrit = Registro(joinsT1T2.campo, itRegAct.Siguiente().x.Significado(joinsT1T2.campo));
			// Si el registro fue borrado 
			if( itRegAct.Siguiente().y ){ 
				joinsT1T2.registroJoin.BorrarRegistro(regCrit);
			} 
			else { // Si el registro fue agregado Reviso si esta en las dos tablas, si esta lo agrego a la lista de join
				aed2::Lista<ItLista>::Iterador itLista1 = Buscar(regCrit, t1);
				aed2::Lista<ItLista>::Iterador itLista2 = Buscar(regCrit, t2);
				if(itLista1.HaySiguiente() && itLista2.HaySiguiente()){
					Registro regAgr = itLista1.Siguiente().Siguiente().agregarCampos(itLista2.Siguiente().Siguiente());
					joinsT1T2.registroJoin.AgregarRegistro(regAgr);
				}
			}
			itRegAct.EliminarSiguiente();
		}
	}
}





// Devuelve el nombre de la tabla que tuvo mayor cant de Accesos
const NombreTabla& BaseDatos::EncontrarMaximo( NombreTabla& t, const aed2::Conj<NombreTabla>&  conjTab) {
	struct InfoTabla infoT = tablasBD.Significado(t);
	aed2::Nat accesosT = infoT.tablaData.CantidadDeAccesos();
	Conj<NombreTabla>::const_Iterador itConjCT = conjTab.CrearIt();
	
	aed2::Nat maxAcceso = accesosT;
	NombreTabla& stringMaxAcceso = t;

	while(itConjCT.HaySiguiente()){
		InfoTabla tInfo = tablasBD.Significado(itConjCT.Siguiente());
		aed2::Nat accesoT = tInfo.tablaData.CantidadDeAccesos();
		if(accesoT > maxAcceso){
			maxAcceso = accesoT;
			stringMaxAcceso = itConjCT.Siguiente();
		}
		itConjCT.Avanzar();
	}
	cantAccesoMax = maxAcceso;
	stringMaxAcceso = stringMaxAcceso;
	return stringMaxAcceso;
}

// devuelve los registros de una tabla
aed2::Lista<Registro>::Iterador BaseDatos::Registros(const NombreTabla& t){
	return tablasBD.Significado(t).tablaData.Registros();
}

aed2::Conj<aed2::NombreCampo> unionConjuntos(aed2::Conj<aed2::NombreCampo> c1, aed2::Conj<aed2::NombreCampo> c2){
	aed2::Conj<aed2::NombreCampo>::Iterador it1 = c1.CrearIt(); 
	while(it1.HaySiguiente()){
		c2.Agregar(it1.Siguiente());
		it1.Avanzar();
	}
	return c2;
}

// Genera el Join entre dos tablas
void BaseDatos::GenerarVistaJoin(const NombreTabla& t1, const NombreTabla& t2, const NombreCampo& ca){
<<<<<<< HEAD
	struct InfoTabla infoT1 = tablasBD.Significado(t1);
	aed2::Lista<Registro>::Iterador itRegT1 = infoT1.tablaData.Registros();
	aed2::Lista<Registro>::Iterador itRegT2 = tablasBD.Significado(t2).tablaData.Registros();
	
	// Se crea InfoJoin 
	aed2::Conj<aed2::NombreCampo> camposT1 = tablasBD.Significado(t1).tablaData.CamposTabla();
	aed2::Conj<aed2::NombreCampo> camposT2 = tablasBD.Significado(t2).tablaData.CamposTabla();
	
	
	aed2::Conj<aed2::NombreCampo> camposUnidos = unionConjuntos(camposT1, camposT2);
	aed2::Conj<aed2::NombreCampo> claves;
	aed2::NombreTabla nombreTablaJoin = "lala";
	aed2::Conj<Dato> datosCamposUnidos;
	Registro registroCamposUnidos(camposUnidos, datosCamposUnidos); 
	Tabla tablaJoin( nombreTablaJoin, claves, registroCamposUnidos);
	struct InfoJoin infoJoinT = InfoJoin(tablaJoin, ca);
	infoT1.joins.Definir(t2, infoJoinT);
	
	
	//Verifico que ninguna tabla sea vacia
	if(!itRegT1.HaySiguiente()) return;
	if(!itRegT2.HaySiguiente()) return;

	while(itRegT2.HaySiguiente()){
		aed2::Conj<aed2::NombreCampo> conjCamp;
		conjCamp.AgregarRapido(ca);
		aed2::Conj<Dato> conjDato;
		conjDato.AgregarRapido(itRegT2.Siguiente().Significado(ca));
		Registro regCrit = Registro(conjCamp, conjDato);
		Registro regAux = itRegT2.Siguiente();
		aed2::Lista<ItLista>::Iterador itConinciden = Buscar(regAux , t1);
		if(itConinciden.HaySiguiente()){
			tablaJoin.AgregarRegistro(itRegT2.Siguiente().agregarCampos(itConinciden.Siguiente().Siguiente() ) );
		}
		itRegT2.Avanzar();
	}
=======
	//~ struct InfoTabla infoT1 = tablasBD.Significado(t1);
	//~ aed2::Lista<Registro>::const_Iterador itRegT1 = infoT1.tablaData.Registros();
	//~ aed2::Lista<Registro>::const_Iterador itRegT2 = tablasBD.Significado(t2).tablaData.Registros();
	//~ Tabla tablaJoin = Tabla()
	//~ while(itRegT1.HaySiguiente()){
		//~ 
	//~ 
	//~ }
//~ 
>>>>>>> 99aabb1537d6ad2098898c43e8c708367fd9b7d5
}



// devuelve la cantidad de acsesos de una tabla
aed2::Nat BaseDatos::CantidadDeAccesos(const NombreTabla& t) const{
	return tablasBD.Significado(t).tablaData.CantidadDeAccesos();
}

BaseDatos::InfoJoin::InfoJoin(const Tabla& tabla, const aed2::NombreCampo& campo): registroJoin(tabla), campo(campo){}
