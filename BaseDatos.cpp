#include "BaseDatos.h"

using namespace aed2;

//~ 
//~ BaseDatos::BaseDatos(){
	//~ Lista vacioL();
	//~ Dicc vacioD();
	//~ this->tablasBD = vacioD;
	//~ this->tablasLista = vacioL;
	//~ this->cantAccesoMax = 0;
	//~ this->nombreAccesoMax = "";
//~ }


// Agrego una nueva tabla a la BD
void BaseDatos::AgregarTabla(Tabla& t){
	//~ this->tablasLista.AgregarRapido(t.Nombre);
//~ 
	//~ InfoTabla nueva;
	//~ nueva.tablaData = t; 
	 //~ this->tablasBD.Definir(t.Nombre(), nueva);
}

// Agrego un Registro a una Tabla
//~ void BaseDatos::InsertarEntrada(const Registro& r, String& t){
void BaseDatos::InsertarEntrada(const Registro& r, NombreTabla& t){
	//~ InfoTabla t1Info = this->tablaBD.Significado(t);
	//~ t1Info.tablaData.AgregarRegistro(r);
	//~ if(t1Info.tablaData.CantidadDeAccesos() > this->cantAccesoMax){
		//~ this->cantAccesoMax = t1Info.tablaData.CantidadDeAccesos();
		//~ this->stringMaxAcceso = t;
	//~ }
//~ 
	//~ Lista<NombreTabla>::Iterador itTablas = this->tablasLista.CrearIt();
	//~ while(itTablas.HaySiguiente()){
		//~ 
	//~ }
}

//borrar un registro de una tabla
void BaseDatos::Borrar(const Registro& r, NombreTabla& t){

}

// Devuelvo un iterador a los nombres de las tablas de la BD
aed2::Lista<NombreTabla>::Iterador BaseDatos::Tablas() const{
	//~ Lista<NombreTabla>::Iterador itRes = this->tablasLista.CrearIt();
	//~ return itRes;
}

// Devuelvo la tabla que me piden
Tabla& BaseDatos::DameTabla(const NombreTabla& t) const{
	//~ Tabla t1 = this->tablaBD.Significado(t);
	//~ return t1.tablaData;
}

// Devuelve la tabla con mayor cantidad de accesos en BD
NombreTabla& BaseDatos::TablaMaxima() const{
	//~ return this->nombreAccesoMax;
}

// Devuelve el campo para los cuales dos tablas estan vinculadas
NombreCampo& BaseDatos::CampoJoin(const NombreTabla& t1, const NombreTabla& t2) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ InfoJoin tuplaInfoJoin = t1Info.joins.Significado(t2);
	//~ return tuplaInfoJoin.campo;
}

// Devuelve true si hay joint entra las dos tablas 
bool BaseDatos::HayJoin(const NombreTabla& t1, const NombreTabla& t2) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ return t1Info.t1Joins.Definido(t2);
}

// Elimina el Joint entre tablas
void BaseDatos::BorrarJoin(const NombreTabla& t1, const NombreTabla& t2) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ t1Info.joins.Borrar(t2);
//~ 
	//~ InfoTabla t2Info = this->tablasBD.Significado(t2);
	//~ t2Info.joins.Borrar(t1);
}

// Genera el Join entre dos tablas
void BaseDatos::GenerarVistaJoin(const NombreTabla& t1, const NombreTabla& t2, const NombreCampo& ca) const{
}

// Visualiza el Join entre dos tablas
aed2::Conj<Registro> BaseDatos::VistaJoin(const NombreTabla& t1, const NombreTabla& t2) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ InfoJoin joinsT1T2 = t1Info.Significado(t2);
	//~ Lista<Registro>::Iterador itRegAct = joinsT1T2.regActualizar.CrearIt();
//~ 
	//~ if(!(itRecAct.HaySiguiente()) ){
		//~ return joinsT1T2.registroJoin.Registros();
	//~ } else {
		//~ while(itRegAct.HaySiguiente()){
			//~ // Registro regCrit = nuevoReg(joinsT1T2.campo, Siguiente(itRegAct).Significado(joinsT1T2.campo))
			//~ if(itRegAct.Siguiente().y){ // Sig(itRegAct).borrar?
				//~ this->Borrar(joinsT1T2.registroJoin, regCrit);
			//~ } else {
				//~ Conj<Registro>::Iterador itConj1 = this->buscar(t1, regCrit);
				//~ Conj<Registro>::Iterador itConj2 = this->buscar(t2, regCrit);
				//~ if(itConj1.HaySiguiente() && itConj2.HaySiguiente())
					//~ joinsT1T2.registroJoin.AgregarRegistro(Siguiente(itConj1).agregarCampos(Siguiente(itConj2)));
			//~ }
			//~ itRegAct.Avanzar();	
		//~ }
	//~ }
}

// Busca los registro que conincidan con r en la tabla de la base de datos
aed2::Conj<Registro> BaseDatos::Buscar(const Registro& r, const NombreTabla& t) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ return Tabla::Coincidencias(r,t1Info.tablaData.Registros());
}

// Devuelve el nombre de la tabla que tuvo mayor cant de Accesos
NombreTabla BaseDatos::EncontrarMaximo(const NombreTabla& t, const aed2::Conj<NombreTabla>&  conjTab) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ Nat accesosT1 = t1Info.tablaData.CantidadDeAccesos();
	//~ Conj<aed2::String>::Iterador itConjCT = CrearIt();
	//~ 
	//~ Nat maxAcceso = accesosT1;
	//~ aed2::String stringMaxAcceso = t;
//~ 
	//~ while(itConjCT.HaySiguiente()){
		//~ InfoTabla tInfo = this->tablasBD.Significado(itConjCT.Siguiente());
		//~ Nat accesoT = tInfo.tablaData.CantidadDeAccesos();
		//~ if(accesoT > accesosT1){
			//~ maxAcceso = accesoT;
			//~ stringMaxAcceso = itConjCT.Siguiente();
		//~ }
		//~ itConjCT.Avanzar();
	//~ }
	//~ this->cantAccesoMax = maxAcceso;
	//~ this->stringMaxAcceso = stringMaxAcceso;
	//~ return stringMaxAcceso;
}

// devuelve la cantidad de acsesos de una tabla
aed2::Nat BaseDatos::CantidadDeAccesos(const NombreTabla& t) const{
	//~ InfoTabla t1Info = this->tablasBD.Significado(t1);
	//~ return t1Info.tablaData.CantidadDeAccesos();
}

// devuelve los registros de una tabla
aed2::Conj<Registro>::Iterador BaseDatos::Registros(const NombreTabla& t)const{
	//~ InfoTabla t1Info = this->tablaBD.Significado(t);
	//~ return t1Info.tablaData.Registros();
}
