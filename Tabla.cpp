#include "Tabla.h"

//~ using namespace tp3;

typedef aed2::Lista < tp3::Registro >::Iterador ItLista;

//Cosas q faltan:
// ----------------------------------------------------------------------------------------------
	// constructor de tabla con parametros
	// BorrarRegistro falta ver un error y hacer las funciones q actualicen los max y min de los dicc

	// agregar la funcion puedeInsertar no se porq no esta
	// chequear que estan todas las funciones que exportan los modulos

// Constructor Tabla
Tabla::Tabla(const aed2::NombreTabla& nombre, const aed2::Conj <aed2::NombreCampo>& claves, const aed2::Conj<aed2::Columna>& columnas):
nombre(nombre), claves(claves), cantAccesos(0), columnas(columnas){
	aed2::Conj<aed2::Columna>::const_Iterador itColumnas = columnas.CrearIt();
	while(itColumnas.HaySiguiente()){
		campos.AgregarRapido(itColumnas.Siguiente().nombre);
		itColumnas.Avanzar();
	}
	
}

Tabla::~Tabla(){
	if(indices.x.campo != ""){
		delete indices.x.minString;
		delete indices.x.maxString;
	}
	if(indices.y.campo != ""){
		delete indices.y.minNat;
		delete indices.y.maxNat;
	}
}

// Agrego un registor a la tabla
void Tabla::AgregarRegistro(const tp3::Registro& r){
	//~ std::cout << "AgregarRegistro" << std::endl;
	//~ std::cout << claves << std::endl;
	//~ std::cout << registros.Longitud() << std::endl;
	registros.AgregarAtras(r);
	//~ std::cout << registros.Longitud() << std::endl;

	ItLista itRegAgr = registros.CrearItUlt();
	cantAccesos++; 
	// Me fijo si tengo algun indice
	aed2::Conj<aed2::NombreCampo>::Iterador  itIndice = Indices().CrearIt();
	while(itIndice.HaySiguiente()){
		aed2::NombreCampo campoIndice = itIndice.Siguiente();
		tp3::Dato datoIndice = r.Significado(campoIndice);
		
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
	//~ std::cout << registros.Longitud() << std::endl;
}

// Borro un registro de la tabla
void Tabla::BorrarRegistro(const tp3::Registro& crit){
	int Debug = 0;
	cantAccesos++;
	aed2::Lista<ItLista> listaItLis = Coincidencias(crit, Registros() );
	if (Debug==1) std::cout << "DNI borrar: " << listaItLis.Primero().Siguiente().Significado("DNI").dameNat()  << std::endl;
	if (Debug==1) std::cout << "DNI borrar: " << listaItLis.Primero().Siguiente().Significado("nombre").dameString()  << std::endl;
	
	if (Debug==1) std::cout << "cant Registros Borrar: " << listaItLis.Longitud()  << std::endl;
	aed2::Lista<ItLista>::Iterador itLisItLis = listaItLis.CrearIt();
	while(itLisItLis.HaySiguiente()){
		if (Debug==1) std::cout << "Borro un registro: "  << std::endl;
		
		// Si tengo indice Nat Borro la clave del diccionario
		if(indices.y.indiceNat.CantClaves() != 0){
			tp3::Registro registroBorrar = itLisItLis.Siguiente().Siguiente();
			indices.y.indiceNat.Borrar(registroBorrar.Significado(indices.y.campo).dameNat() );
			
		}
		// Si tengo indice String Borro la clave del diccionario
		if(indices.x.indiceString.CantClaves() != 0){
			tp3::Registro registroBorrar = itLisItLis.Siguiente().Siguiente();
			indices.x.indiceString.Borrar(registroBorrar.Significado(indices.x.campo).dameString() );
		}
		if (Debug==1) std::cout << "cant Registros Borrar: " << listaItLis.Longitud()  << std::endl;
		if (Debug==1) std::cout << "HaySiguiente: " << itLisItLis.Siguiente().HaySiguiente()  << std::endl;
		//~ aed2::Nat val = itLisItLis.Siguiente().Siguiente().Significado("DNI").dameNat();
		if (Debug==1) std::cout << "DNI borrar: " << itLisItLis.Siguiente().Siguiente().Significado("DNI").dameNat()  << std::endl;
		itLisItLis.Siguiente().EliminarSiguiente();
		if (Debug==1) std::cout << "Funciono "  << std::endl;
		itLisItLis.Avanzar();
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
	aed2::Lista<tp3::Registro> reg = Registros();
	aed2::Lista<tp3::Registro>::Iterador itReg = reg.CrearIt();
	tp3::Dato max = 0; tp3::Dato min = 0;
	// Si el campo es Nat creo un dicLog
	if(!TipoDelCampo(c)){
		while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			tp3::Dato valor = ((itReg.Siguiente()).Significado(c));
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
		tp3::Dato datoMax(max);
		//~ indices.y.maxNat = datoMax;
		indices.y.maxNat = new tp3::Dato(max);
		indices.y.minNat = new tp3::Dato(min);
	}
	else{ // Dicc de String
		while(itReg.HaySiguiente()){
			//Calculo el valor que va a ser clave del Dicc
			tp3::Dato valor = ((itReg.Siguiente()).Significado(c));
			//Si el valor ya esta en el dicc agrego el iterador al conjunto
			if(indices.x.indiceString.Definido(valor.dameString() )){
//~ aed2::Lista<ItLista> listaReg = indices.y.indiceNat.Significado(valor.dameNat());
				aed2::Lista<ItLista> listaReg = indices.x.indiceString.Significado(valor.dameString());
				listaReg.AgregarAdelante(itReg);
			}
			// Si no esta lo defino en el dicc con significado un conj con el iterador
			else{
				aed2::Lista<ItLista> listaNuevo;
				indices.x.indiceString.Definir(valor.dameString(), listaNuevo);
				//~ std::cout << "definoNuevo" << std::endl;
			}
			if(max < valor) max=valor;
			if(min > valor) min=valor;
			itReg.Avanzar();
		}
		indices.x.campo = c;
		indices.x.maxString = new tp3::Dato(max);
		indices.x.minString = new tp3::Dato(min);
	}
	//~ std::cout << Indices() << std::endl;
}

//Devuelvo el nombre de la tabla
const aed2::NombreTabla& Tabla::Nombre()const{
	return nombre;
}

//Devuelvo un conjunto de las claves de la tabla
aed2::Conj<aed2::NombreCampo> Tabla::Claves() const{
	return claves;
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
	//~ std::cout << "TAbla::indices conj indices" << Conj << std::endl;
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
const aed2::Lista<tp3::Registro> & Tabla::Registros() const{
	return registros;
}
aed2::Lista<tp3::Registro>& Tabla::Registros(){
	return registros;
}

//Devuelvo la cantidad de accesos de la tabla 
aed2::Nat Tabla::CantidadDeAccesos()const{
	return cantAccesos;
}

// Devuelvo el minimo dato de todos los registros para la tabla
const tp3::Dato Tabla::Minimo(const aed2::NombreCampo& c)const{
	if(indices.x.campo == c){
		return *(indices.x.minString);
	}
	else if (indices.y.campo == c){
		return *(indices.y.minNat);
	} 
	else{
		return tp3::Dato::min( DameColumna(c, registros));
	}
}

// Devuelvo el Maximo dato de todos los registros para la tabla
const tp3::Dato Tabla::Maximo(const aed2::NombreCampo& c)const{
	if(indices.x.campo == c){
		return *(indices.x.maxString);
	}
	else if (indices.y.campo == c){
		return *(indices.y.maxNat);
	} 
	else{
		return tp3::Dato::max( DameColumna(c, registros));
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
bool Tabla::HayCoincidencia(const tp3::Registro& r, const aed2::Conj<aed2::NombreCampo>& cc, const aed2::Conj<tp3::Registro>& cr){
	if(cc.EsVacio()) return false;
	aed2::Conj<tp3::Registro>::const_Iterador itCr = cr.CrearIt();
	while(itCr.HaySiguiente() ){
		if(r.coincideAlguno(cc, itCr.Siguiente() ) ) return true;
		itCr.Avanzar();
	}
	return false;
}

// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
aed2::Lista<ItLista> Tabla::Coincidencias(const tp3::Registro& r, aed2::Lista<tp3::Registro>& lisReg){
	int Debug = 0;
	ItLista itLisReg = lisReg.CrearIt();
	aed2::Lista<ItLista> listaItLista;
	aed2::Lista<ItLista>::Iterador itListaItLista = listaItLista.CrearIt();
	if (Debug==1) std::cout << "cant Registros Borrar: " << listaItLista.Longitud()  << std::endl;
	// Reviso que no sea vacia la tabla
	if(itLisReg.HaySiguiente()){
		// Si tengo indice String busco por este indice
		if( r.campos().Pertenece(indices.x.campo) ){
			if (Debug==1) std::cout << "Busco Coincidencias por indice String "  << std::endl;
			tp3::Dato d = r.Significado(indices.x.campo);
			listaItLista = indices.x.indiceString.Significado( d.dameString() ); 
		}
		// Si tengo indice Nat busco por este indice
		else if(r.campos().Pertenece(indices.y.campo) ){
			if (Debug==1) std::cout << "Busco Coincidencias por indice Nat "  << std::endl;
			tp3::Dato d = r.Significado(indices.y.campo);
			listaItLista = indices.y.indiceNat.Significado( d.dameNat() ); 
		}
		else{ // Si no recorro linealmente
			if (Debug==1) std::cout << "Busco Coincidencias recorriendo todos los registros "  << std::endl;
			while(itLisReg.HaySiguiente()){
				if(itLisReg.Siguiente().coincidenTodos(r.campos(), r)){
					if (Debug==1) std::cout << "Encontre una coincidencia "  << std::endl;
					if (Debug==1) std::cout << "cantRegistros Lista "  << listaItLista.Longitud() <<std::endl;
					listaItLista.AgregarAtras( itLisReg );
					//~ itLisReg.EliminarSiguiente();
					if (Debug==1) std::cout << "cantRegistros Lista "  << listaItLista.Longitud() <<std::endl;
				}
				itLisReg.Avanzar();
			}
		}
	}
	if (Debug==1) std::cout << "cant Registros Borrar: " << listaItLista.Longitud()  << std::endl;
	if (Debug==1) std::cout << "DNI borrar: " << listaItLista.Primero().Siguiente().Significado("DNI").dameNat()  << std::endl;
	if (Debug==1) std::cout << "DNI borrar: " << listaItLista.Primero().Siguiente().Significado("nombre").dameString()  << std::endl;
	return listaItLista; 
}

// Devuelve la comlumna de c en cr
aed2::Conj<tp3::Dato> Tabla::DameColumna(const aed2::NombreCampo& c, const aed2::Lista<tp3::Registro>& lr){
	aed2::Conj<tp3::Dato> res;
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
bool Tabla::MismosTipos(const tp3::Registro& r){
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

// Devuelvo el conjunto de Columnas de la tabla
aed2::Conj<aed2::Columna> Tabla::dameColumnas() const{
	return columnas;
}
