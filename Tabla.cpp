#include "Tabla.h"


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
	aed2::Conj<aed2::NombreCampo>::Iterador  itIndice = Indices();
	while(itIndice.HaySiguiente()){
		aed2::NombreCampo campoIndice = itIndice.Siguiente();
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
void Tabla::Indexar(const aed2::NombreCampo& c){
	aed2::Lista<Registro>::const_Iterador itReg = Registros();
	Dato max = 0; Dato min = 0;
	// Si el campo es Nat creo un dicLog
	if(TipoDelCampo(c)){
		while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			Dato valor = ((itReg.Siguiente()).Significado(c));
			//Si el valor ya esta en el dicc agrego el iterador al conjunto
			if(indices.y.indiceNat.Definido(valor.dameNat())){
				aed2::Conj<const_ItLista> conjReg = indices.y.indiceNat.Significado(valor.dameNat());
				conjReg.AgregarRapido(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Conj<const_ItLista> conjNuevo;
				indices.y.indiceNat.Definir(valor.dameNat(), conjNuevo);
			}
			if(max < valor) max=valor;
			if(min > valor) min=valor;
			itReg.Avanzar();
		}
		indices.y.campo = c;
		indices.y.maxNat = new Dato(max);
		indices.y.minNat = new Dato(min);
	}
	else{ // Dicc de String
		while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			Dato valor = ((itReg.Siguiente()).Significado(c));
			//Si el valor ya esta en el dicc agrego el iterador al conjunto
			if(indices.x.indiceString.Definido(valor.dameString() )){
				aed2::Conj<aed2::Lista<Registro>::const_Iterador> conjReg = indices.x.indiceString.Significado(valor.dameString());
				conjReg.AgregarRapido(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Conj<aed2::Lista<Registro>::const_Iterador> conjNuevo;
				indices.x.indiceString.Definir(valor.dameString(), conjNuevo);
			}
			if(max < valor) max=valor;
			if(min > valor) min=valor;
			itReg.Avanzar();
		}
		indices.y.campo = c;
		indices.y.maxNat = new Dato(max);
		indices.y.minNat = new Dato(min);
	}
}

//Devuelvo el nombre de la tabla
const NombreTabla& Tabla::Nombre()const{
	return nombre;
}

//Devuelvo un conjunto de las claves de la tabla
aed2::Conj<NombreCampo>::const_Iterador Tabla::Claves() const{
	return claves.CrearIt();
}

// Devuelvo el conjunto de indices de la tabla
aed2::Conj<NombreCampo>::Iterador Tabla::Indices() const{
}

// Devuelvo un iterador al conjunto de campos de la tabla
aed2::Conj<NombreCampo>::Iterador Tabla::CamposTabla()const{

}

// Devuelvo el tipo del campo c de la tabla
const TipoCampo& Tabla::TipoDelCampo(const NombreCampo& c) const{

}

// Devuelvo un iterador a la lista de registros de la tabla
aed2::Lista<Registro>::const_Iterador Tabla::Registros() const{
	return registros.CrearIt();
}

//Devuelvo la cantidad de accesos de la tabla 
aed2::Nat Tabla::CantidadDeAccesos()const{
	return cantAccesos;
}

// Devuelvo el minimo dato de todos los registros para la tabla
const Dato& Tabla::Minimo(const NombreCampo& c)const{
	// Si el campo es String
	if(indices.x.campo == c){
		//~ return 
	}
}

// Devuelvo el Maximo dato de todos los registros para la tabla
const Dato& Tabla::Maximo(const NombreCampo& c)const{
	//~ return 
}

// Devuelvo un bool que es true si se puede crear un indice en ese campo
bool Tabla::PuedeIndexar(const NombreCampo& c)const{
}

// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
bool HayCoincidencia(const Registro& r, const aed2::Conj<NombreCampo>& cc, const aed2::Conj<Registro>& cr){
	
}

// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
aed2::Conj<aed2::Lista<Registro>::Iterador>::Iterador Coincidencias(const Registro& r, aed2::Lista<Registro>::Iterador itLisReg){
	
}

// Devuelve la comlumna de c en cr
aed2::Conj<Dato> DameColumna(const NombreCampo& r, const aed2::Conj<Registro>& cr){
}

// Devuelve true si los campos del registros son los mismos que de la tabla
bool MismosTipos(const Registro& r, const Tabla& t){
}
