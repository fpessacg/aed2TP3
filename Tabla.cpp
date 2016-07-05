#include "Tabla.h"

typedef aed2::Lista < Registro >::Iterador ItLista;

//Cosas q faltan:
// ----------------------------------------------------------------------------------------------
	// constructor de tabla con parametros
	// agregar
	//BorrarRegistro falta ver un error y hacer las funciones q actualicen los max y min de los dicc
	// Coincidencias tengo un errror con const
	

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
	aed2::Conj<aed2::NombreCampo>::Iterador  itIndice = Indices().CrearIt();
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
void Tabla::BorrarRegistro(const Registro& crit){
	aed2::Conj<ItLista>::Iterador itConjItLis = Coincidencias(crit, Registros() );
	while(itConjItLis.HaySiguiente()){
		// Si tengo indice Nat Borro la clave del diccionario
		if(indices.y.indiceNat.CantClaves() != 0){
			Registro registroBorrar = itConjItLis.Siguiente().Siguiente();
			indices.y.indiceNat.Borrar(registroBorrar.Significado(indices.y.campo).dameNat() );
			
		}
		// Si tengo indice String Borro la clave del diccionario
		if(indices.x.indiceString.CantClaves() != 0){
			Registro registroBorrar = itConjItLis.Siguiente().Siguiente();
			indices.x.indiceString.Borrar(registroBorrar.Significado(indices.x.campo).dameString() );
		}
		//~ itConjItLis.Siguiente().EliminarSiguiente();
	}
	//Actualizo los maximos de los indices
				//FALTA definir la funcion calcularMax calcularMin para los dicc 
	//~ indices.x.indiceString.maxNat = indices.x.indiceString.indiceString.calcularMax();
	//~ indices.x.indiceString.minNat = indices.x.indiceString.indiceString.calcularMin();
	//~ indices.y.indiceNat.maxNat    = indices.y.indiceNat.indiceNat.calcularMax();
	//~ indices.y.indiceNat.minNat    = indices.y.indiceNat.indiceNat.calcularMin();
}

// Creo un Indice en el campo c de la tabla
void Tabla::Indexar(const aed2::NombreCampo& c){
	aed2::Lista<Registro>::Iterador itReg = Registros();
	Dato max = 0; Dato min = 0;
	// Si el campo es Nat creo un dicLog
	if(TipoDelCampo(c)){
		while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			Dato valor = ((itReg.Siguiente()).Significado(c));
			//Si el valor ya esta en el dicc agrego el iterador al conjunto
			if(indices.y.indiceNat.Definido(valor.dameNat())){
				aed2::Conj<ItLista> conjReg = indices.y.indiceNat.Significado(valor.dameNat());
				conjReg.AgregarRapido(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Conj<ItLista> conjNuevo;
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
				aed2::Conj<aed2::Lista<Registro>::Iterador> conjReg = indices.x.indiceString.Significado(valor.dameString());
				conjReg.AgregarRapido(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Conj<ItLista> conjNuevo;
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
aed2::Conj<NombreCampo> Tabla::Indices() const{
	aed2::Conj<NombreCampo> Conj;
	if(indices.y.indiceNat.CantClaves() != 0){
		Conj.AgregarRapido(indices.y.campo);
	}
	if(indices.x.indiceString.CantClaves() != 0){
		Conj.AgregarRapido(indices.x.campo);
	}
	return Conj;
}

// Devuelvo un iterador al conjunto de campos de la tabla
aed2::Conj<NombreCampo>::const_Iterador Tabla::CamposTabla()const{
	return campos.CrearIt();
}

// Devuelvo el tipo del campo c de la tabla
TipoCampo Tabla::TipoDelCampo(const NombreCampo& c) const{
	return registros.Primero().Significado(c).tipo();
}

// Devuelvo un iterador a la lista de registros de la tabla
aed2::Lista<Registro>::const_Iterador Tabla::Registros() const{
	return registros.CrearIt();
}
aed2::Lista<Registro>::Iterador Tabla::Registros(){
	return registros.CrearIt();
}

//Devuelvo la cantidad de accesos de la tabla 
aed2::Nat Tabla::CantidadDeAccesos()const{
	return cantAccesos;
}

// Devuelvo el minimo dato de todos los registros para la tabla
const Dato Tabla::Minimo(const NombreCampo& c)const{
	if(indices.x.campo == c){
		return *(indices.x.minString);
	}
	else if (indices.y.campo == c){
		return *(indices.y.minNat);
	} 
	else{
		return Dato::min( DameColumna(c, registros));
	}
}

// Devuelvo el Maximo dato de todos los registros para la tabla
const Dato Tabla::Maximo(const NombreCampo& c)const{
	if(indices.x.campo == c){
		return *(indices.x.maxString);
	}
	else if (indices.y.campo == c){
		return *(indices.y.maxNat);
	} 
	else{
		return Dato::max( DameColumna(c, registros));
	}
}

// Devuelvo un bool que es true si se puede crear un indice en ese campo
bool Tabla::PuedeIndexar(const NombreCampo& c)const{
	bool res = false;
	if( campos.Pertenece(c) ){
		TipoCampo tipoC =TipoDelCampo(c);
		if(tipoC == STR && indices.x.campo == ""){res = true;}
		if(tipoC == NAT && indices.y.campo == ""){res = true;}
	}
	return res;
}

// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
bool Tabla::HayCoincidencia(const Registro& r, const aed2::Conj<NombreCampo>& cc, const aed2::Conj<Registro>& cr){
	if(cc.EsVacio()) return false;
	aed2::Conj<Registro>::const_Iterador itCr = cr.CrearIt();
	while(itCr.HaySiguiente() ){
		if(r.coincideAlguno(cc, itCr.Siguiente() ) ) return true;
		itCr.Avanzar();
	}
	return false;
}

// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
aed2::Conj<ItLista>::Iterador Tabla::Coincidencias(const Registro& r, ItLista itLisReg){
	aed2::Conj<ItLista> conjItLista;
	aed2::Conj<ItLista>::Iterador itConjItLista = conjItLista.CrearIt();
	if(itLisReg.HaySiguiente()){
		// Si tengo indice String busco por este indice
		if( r.campos().Pertenece(indices.x.campo) ){
			Dato d = r.Significado(indices.x.campo);
			itConjItLista = indices.x.indiceString.Significado( d.dameString() ).CrearIt(); 
		}
		else if(r.campos().Pertenece(indices.y.campo) ){
			Dato d = r.Significado(indices.y.campo);
			itConjItLista = indices.y.indiceNat.Significado( d.dameNat() ).CrearIt(); 
		}
		while(itConjItLista.HaySiguiente()){
			//~ if(!(itConjItLista.Siguiente().Siguiente().CoincidenTodos(r.campos(), r))){
				itConjItLista.EliminarSiguiente();
			//~ }
			//~ else itConjItLista.Avanzar();
		}
	}
	else return itConjItLista; 
}

// Devuelve la comlumna de c en cr
aed2::Conj<Dato> Tabla::DameColumna(const NombreCampo& c, const aed2::Lista<Registro>& lr){
	aed2::Conj<Dato> res;
	const_ItLista itLista = lr.CrearIt();
	// Si es vacio devuelvo un conj vacio
	if(!itLista.HaySiguiente()) return res;
	while(itLista.HaySiguiente()){
		if(itLista.Siguiente().campos().Pertenece(c) ){
			res.AgregarRapido(itLista.Siguiente().Significado(c));
		}
		itLista.Avanzar();
	}
	return res;
}

// Devuelve true si los campos del registros son los mismos que de la tabla
bool Tabla::MismosTipos(const Registro& r){
	bool res = true;
	aed2::Conj<NombreCampo>::const_Iterador itCamposTabla = campos.CrearIt();
	aed2::Conj<NombreCampo>::Iterador itCamposR = r.campos().CrearIt();
	if(!itCamposR.HaySiguiente()) return res;
	while(itCamposR.HaySiguiente()){
		if(campos.Pertenece( itCamposR.Siguiente() ) ){
			res = (TipoDelCampo(itCamposR.Siguiente()) == r.Significado(itCamposR.Siguiente()).tipo() );
		}
		itCamposR.Avanzar();
	}
	return res;
}
