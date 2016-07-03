#include "Tabla.h"


using namespace aed2;

// Agrego un registor a la tabla
void Tabla::AgregarRegistro(const Registro& r){
	registros.AgregarAtras(r);
	cantAccesos++; 
	//~ Lista<Registro>::Iterador itReg = registros.CrearItUlt();
	//~ // Creo un it a DiccLog p var si es vacio 
	//~ Dicc<Nat,Conj<ItLista> >::Iterador ItDiccLog = indices.y.indiceNat.CrearIt();
	//~ if(!ItDiccLog.HaySiguiente()){
		//~ 
	//~ }
	
	// Me fijo si tengo algun indice
	Conj<NombreCampo>::Iterador  itIndice = Indices();
	while(itIndice.HaySiguiente()){
		NombreCampo campoIndice = itIndice.Siguiente();
		// Veo si ese indice es nat 
		if(campoIndice == indices.y.campo){
			
			
		}

		// Veo si ese indice es String 
		if(campoIndice == indices.x.campo){
			
			
		}
		itIndice.Avanzar();
	}
}

// Borro un registro de la tabla
void Tabla::BorrarRegistro(Registro& crit){
	//~ Conj<Lista<Registro>::Iterador>::Iterador itConjItLis = Coincidencias(crit, Registros() );
	//Coincidencias( crit, registros.CrearIt() );
	
}

// Creo un Indice en el campo c de la tabla
void Tabla::Indexar(const NombreCampo& c){
	Lista<Registro>::Iterador itReg = Registros();
	int max = 0; int min = 0;
	// Si el campo es Nat creo un dicLog
	//if(TipoCampo(c)){
	if(true){
		// lo creo directamente en indices.y.indiceString?????????????????????????????????????
		//~ Dicc<Nat,Conj<ItLista> >  dic = Dicc();
		Dicc<Nat,Conj<ItLista> >  dic;
		while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			Nat valor = ((itReg.Siguiente()).Significado(c)).dameNat();
			//Si el valor ya esta en el dicc agrego el iterador al conjunto
			if(dic.Definido(valor)){
				Conj<ItLista> conjReg = dic.Significado(valor);
				conjReg.AgregarRapido(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				//~ Conj<ItLista> conjNuevo = Conj(Conj<ItLista> itReg);
				Conj<ItLista> conjNuevo;
				dic.Definir(valor, conjNuevo);
			}
			if(max < valor) max=valor;
			if(min > valor) min=valor;
			itReg.Avanzar();
		}
		indices.y.campo = c;
		indices.y.maxNat = max;
		indices.y.minNat = min;
	}
	else{ // Dicc de String
		// lo creo directamente en indices.y.indiceString?????????????????????????????????????
		//~ Dicc<Nat,Conj<ItLista> >  dic = Dicc();
		Dicc<Nat,Conj<ItLista> >  dic;
				while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			Nat valor = ((itReg.Siguiente()).Significado(c)).dameNat();
			//Si el valor ya esta en el dicc agrego el iterador al conjunto
			if(dic.Definido(valor)){
				Conj<ItLista> conjReg = dic.Significado(valor);
				conjReg.AgregarRapido(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				//~ Conj<ItLista> conjNuevo = Conj(Conj<ItLista> itReg);
				Conj<ItLista> conjNuevo;
				dic.Definir(valor, conjNuevo);
			}
			if(max < valor) max=valor;
			if(min > valor) min=valor;
			itReg.Avanzar();
		}
		indices.y.campo = c;
		indices.y.maxNat = max;
		indices.y.minNat = min;
	}
}

//Devuelvo el nombre de la tabla
NombreTabla Tabla::Nombre()const{
	return nombre;
}

//Devuelvo un conjunto de las claves de la tabla
Conj<NombreCampo>::Iterador Tabla::Claves(){
	return claves.CrearIt();
}

// Devuelvo el conjunto de indices de la tabla
Conj<NombreCampo>::Iterador Tabla::Indices() const{
}

// Devuelvo un iterador al conjunto de campos de la tabla
Conj<NombreCampo>::Iterador Tabla::CamposTabla()const{

}

// Devuelvo el tipo del campo c de la tabla
//~ TipoCampo Tabla::TipoCampo(const NombreCampo& c){
//~ }


// Devuelvo un iterador a la lista de registros de la tabla
Lista<Registro>::Iterador Tabla::Registros(){
	return registros.CrearIt();
}

//Devuelvo la cantidad de accesos de la tabla 
Nat Tabla::CantidadDeAccesos()const{
	return cantAccesos;
}

// Devuelvo el minimo dato de todos los registros para la tabla
Dato Tabla::Minimo(const NombreCampo& c)const{
}

// Devuelvo el Maximo dato de todos los registros para la tabla
Dato Tabla::Maximo(const NombreCampo& c)const{
	//~ return 
}

// Devuelvo un bool que es true si se puede crear un indice en ese campo
bool Tabla::PuedeIndexar(const NombreCampo& c)const{
}

// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
bool HayCoincidencia(const Registro& r, const Conj<NombreCampo>& cc, const Conj<Registro>& cr){
}

// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
Conj<Lista<Registro>::Iterador>::Iterador Coincidencias(const Registro& r, Lista<Registro>::Iterador itLisReg){
	
}

// Devuelve la comlumna de c en cr
Conj<Dato> DameColumna(const NombreCampo& r, const Conj<Registro>& cr){
}

// Devuelve true si los campos del registros son los mismos que de la tabla
bool MismosTipos(const Registro& r, const Tabla& t){
}
