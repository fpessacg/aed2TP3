#include "Tabla.h"

typedef aed2::Lista < Registro >::Iterador ItLista;

//Cosas q faltan:
// ----------------------------------------------------------------------------------------------
	// constructor de tabla con parametros
	// BorrarRegistro falta ver un error y hacer las funciones q actualicen los max y min de los dicc

	// agregar la funcion puedeInsertar no se porq no esta
	// chequear que estan todas las funciones que exportan los modulos

// Constructor Tabla
Tabla::Tabla(const aed2::NombreTabla& nombre, const aed2::Conj <aed2::NombreCampo>& claves, const Registro & columnas):
nombre(nombre), claves(claves), cantAccesos(0), campos(columnas.campos()){
	aed2::Conj<aed2::NombreCampo>::Iterador itCampos = columnas.campos().CrearIt();
	while(itCampos.HaySiguiente()){
		tipoDeLosCampos.Definir(itCampos.Siguiente(), columnas.Significado(itCampos.Siguiente()).tipo() );
		itCampos.Avanzar();
	}
}


// Agrego un registor a la tabla
void Tabla::AgregarRegistro(const Registro& r){
	registros.AgregarAtras(r);
	ItLista itRegAgr = registros.CrearItUlt();
	cantAccesos++; 
	// Me fijo si tengo algun indice
	aed2::Conj<aed2::NombreCampo>::Iterador  itIndice = Indices().CrearIt();
	while(itIndice.HaySiguiente()){
		aed2::NombreCampo campoIndice = itIndice.Siguiente();
		Dato datoIndice = r.Significado(campoIndice);
		
		// Veo si ese indice es nat 
		if(campoIndice == indices.y.campo){
			// Veo si esta definida la clave en el dicc
			if(indices.y.indiceNat.Definido(datoIndice.dameNat())){
				indices.y.indiceNat.Significado(datoIndice.dameNat()).AgregarAdelante(itRegAgr);
			}
			else{ //si no esta definida tengo que agregarla
				aed2::Lista<ItLista>  listaAgr;
				listaAgr.AgregarAdelante(itRegAgr);
				indices.y.indiceNat.Definir(datoIndice.dameNat(), listaAgr);
			}
			// Actualizo los max y minimos
			if( datoIndice > *(indices.y.maxNat)) indices.y.maxNat = &datoIndice;
			if( datoIndice < *(indices.y.minNat)) indices.y.minNat = &datoIndice;
		}
		// Veo si ese indice es String 
		if(campoIndice == indices.x.campo){
			// Veo si esta definida la clave en el dicc
			if(indices.x.indiceString.Definido(datoIndice.dameString())){
				indices.x.indiceString.Significado(datoIndice.dameString()).AgregarAdelante(itRegAgr);
			}
			else{ //si no esta definida tengo que agregarla
				aed2::Lista<ItLista>  listaAgr;
				listaAgr.AgregarAdelante(itRegAgr);
				indices.x.indiceString.Definir(datoIndice.dameString(), listaAgr);
			}
			// Actualizo los max y minimos
			if( datoIndice > *(indices.x.maxString)) indices.x.maxString = &datoIndice;
			if( datoIndice < *(indices.x.minString)) indices.x.minString = &datoIndice;
		}
		itIndice.Avanzar();
	}
}

// Borro un registro de la tabla
void Tabla::BorrarRegistro(const Registro& crit){
	aed2::Lista<ItLista>::Iterador itConjItLis = Coincidencias(crit, Registros() );
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
		itConjItLis.Siguiente().EliminarSiguiente();
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
				aed2::Lista<ItLista> listaReg = indices.y.indiceNat.Significado(valor.dameNat());
				listaReg.AgregarAdelante(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Lista<ItLista> listaNuevo;
				indices.y.indiceNat.Definir(valor.dameNat(), listaNuevo);
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
				aed2::Lista<aed2::Lista<Registro>::Iterador> listaReg = indices.x.indiceString.Significado(valor.dameString());
				listaReg.AgregarAdelante(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Lista<ItLista> listaNuevo;
				indices.x.indiceString.Definir(valor.dameString(), listaNuevo);
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
const aed2::NombreTabla& Tabla::Nombre()const{
	return nombre;
}

//Devuelvo un conjunto de las claves de la tabla
aed2::Conj<aed2::NombreCampo>::const_Iterador Tabla::Claves() const{
	return claves.CrearIt();
}

// Devuelvo el conjunto de indices de la tabla
aed2::Conj<aed2::NombreCampo> Tabla::Indices() const{
	aed2::Conj<aed2::NombreCampo> Conj;
	if(indices.y.indiceNat.CantClaves() != 0){
		Conj.AgregarRapido(indices.y.campo);
	}
	if(indices.x.indiceString.CantClaves() != 0){
		Conj.AgregarRapido(indices.x.campo);
	}
	return Conj;
}

// Devuelvo un iterador al conjunto de campos de la tabla
aed2::Conj<aed2::NombreCampo> Tabla::CamposTabla()const{
	return campos;
}

// Devuelvo el tipo del campo c de la tabla
aed2::TipoCampo Tabla::TipoDelCampo(const aed2::NombreCampo& c) const{
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
const Dato Tabla::Minimo(const aed2::NombreCampo& c)const{
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
const Dato Tabla::Maximo(const aed2::NombreCampo& c)const{
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
bool Tabla::PuedeIndexar(const aed2::NombreCampo& c)const{
	bool res = false;
	if( campos.Pertenece(c) ){
		aed2::TipoCampo tipoC =TipoDelCampo(c);
		if(tipoC == aed2::STR && indices.x.campo == ""){res = true;}
		if(tipoC == aed2::NAT && indices.y.campo == ""){res = true;}
	}
	return res;
}

// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
bool Tabla::HayCoincidencia(const Registro& r, const aed2::Conj<aed2::NombreCampo>& cc, const aed2::Conj<Registro>& cr){
	if(cc.EsVacio()) return false;
	aed2::Conj<Registro>::const_Iterador itCr = cr.CrearIt();
	while(itCr.HaySiguiente() ){
		if(r.coincideAlguno(cc, itCr.Siguiente() ) ) return true;
		itCr.Avanzar();
	}
	return false;
}

// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
aed2::Lista<ItLista>::Iterador Tabla::Coincidencias(const Registro& r, ItLista itLisReg){
	aed2::Lista<ItLista> listaItLista;
	aed2::Lista<ItLista>::Iterador itListaItLista = listaItLista.CrearIt();
	if(itLisReg.HaySiguiente()){
		// Si tengo indice String busco por este indice
		if( r.campos().Pertenece(indices.x.campo) ){
			Dato d = r.Significado(indices.x.campo);
			itListaItLista = indices.x.indiceString.Significado( d.dameString() ).CrearIt(); 
		}
		else if(r.campos().Pertenece(indices.y.campo) ){
			Dato d = r.Significado(indices.y.campo);
			itListaItLista = indices.y.indiceNat.Significado( d.dameNat() ).CrearIt(); 
		}
		while(itListaItLista.HaySiguiente()){
			if(!(itListaItLista.Siguiente().Siguiente().coincidenTodos(r.campos(), r))){
				itListaItLista.EliminarSiguiente();
			}
			else itListaItLista.Avanzar();
		}
	}
	else return itListaItLista; 
}

// Devuelve la comlumna de c en cr
aed2::Conj<Dato> Tabla::DameColumna(const aed2::NombreCampo& c, const aed2::Lista<Registro>& lr){
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
	aed2::Conj<aed2::NombreCampo>::const_Iterador itCamposTabla = campos.CrearIt();
	aed2::Conj<aed2::NombreCampo>::Iterador itCamposR = r.campos().CrearIt();
	if(!itCamposR.HaySiguiente()) return res;
	while(itCamposR.HaySiguiente()){
		if(campos.Pertenece( itCamposR.Siguiente() ) ){
			res = (TipoDelCampo(itCamposR.Siguiente()) == r.Significado(itCamposR.Siguiente()).tipo() );
		}
		itCamposR.Avanzar();
	}
	return res;
}
