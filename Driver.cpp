#include "Driver.h"

bool aed2::operator == (const aed2::Columna& c1, const aed2::Columna& c2)
{
  return c1.nombre == c2.nombre and c1.tipo == c2.tipo;
}

using namespace aed2;

////////////////////////////////////////////////////////////////////////////////
// Funciones Auxiliares
////////////////////////////////////////////////////////////////////////////////


template <typename T>
aed2::Conj<T> deListaAConj(aed2::Lista<T>& lista){
	typename aed2::Conj<T> conj;
	typename aed2::Lista<T>::Iterador itLista = lista.CrearIt();
	while(itLista.HaySiguiente()){
		conj.Agregar(itLista.Siguiente());
		itLista.Avanzar();
	}
	return conj;
}

aed2::Conj<tp3::Registro> deListaAConjReg(aed2::Lista<tp3::Registro>& lista){
	aed2::Conj<tp3::Registro> conj;
	aed2::Lista<tp3::Registro>::const_Iterador itLista = lista.CrearIt();
		//~ std::cout << itLista.HaySiguiente() << std::endl;
	while(itLista.HaySiguiente()){
		tp3::Registro regAux = itLista.Siguiente();
		conj.AgregarRapido(regAux);
		itLista.Avanzar();
	}
	//~ std::cout << "lala" << std::endl;
	return conj;
}

Driver::Dato pasarDatoADDato(const tp3::Dato& dato){
	if (dato.esNat()) return Driver::Dato(dato.dameNat());
	else return Driver::Dato(dato.dameString());
}


Driver::Registro pasarRegADReg(const tp3::Registro& reg){
	Driver::Registro dReg;
	aed2::Conj<aed2::NombreCampo> camposReg = reg.campos();
	//~ std::cout << "CamposRegistro:  " << camposReg << std::endl;
	aed2::Conj<aed2::NombreCampo>::const_Iterador itCamposReg = camposReg.CrearIt();
	while(itCamposReg.HaySiguiente()){
		aed2::NombreCampo nombreCamp = itCamposReg.Siguiente();
	//~ std::cout << "HaySiguienteCampo registro:  " << itCamposReg.HaySiguiente() << std::endl;
	//~ std::cout << "Nombre Campo:  " << itCamposReg.Siguiente() << std::endl;
		tp3::Dato dato = reg.Significado(itCamposReg.Siguiente());
	//~ std::cout << "Funciono" << std::endl;
		//~ tp3::Dato dato = reg.Significado(nombreCamp);
		//~ dReg.DefinirRapido(nombreCamp, pasarDatoADDato(dato));
		dReg.DefinirRapido(nombreCamp, pasarDatoADDato(dato));
		
		itCamposReg.Avanzar();
	}
	return dReg;
}

tp3::Dato pasarDDatoADato(const Driver::Dato dDato){
	if (dDato.esNat()) return tp3::Dato(dDato.dameNat());
	else return tp3::Dato(dDato.dameString());
}

tp3::Registro pasarDRegAReg(const Driver::Registro& dReg){
	tp3::Registro reg;
	Driver::Registro::const_Iterador itDReg = dReg.CrearIt();
	while(itDReg.HaySiguiente()){
		tp3::Registro nuevoReg = tp3::Registro(itDReg.SiguienteClave(), pasarDDatoADato(itDReg.SiguienteSignificado()));
		//~ std::cout << "pasarDRegAReg" << std::endl;
		reg.agregarCampos(nuevoReg);
		//~ std::cout << "pasarDRegAReg" << std::endl;
		itDReg.Avanzar();
	}
	return reg;
}

aed2::Conj<Driver::Registro>  pasarConjRegAConjDReg(const aed2::Conj<tp3::Registro> conjReg){
	aed2::Conj<tp3::Registro>::const_Iterador itConjReg = conjReg.CrearIt();
	aed2::Conj<Driver::Registro> conjDReg;
	while(itConjReg.HaySiguiente()){
		Driver::Registro dReg = pasarRegADReg(itConjReg.Siguiente()); 
	//~ std::cout << "Hola" << std::endl;
		conjDReg.Agregar( dReg);
		itConjReg.Avanzar();
	}
	return conjDReg;
}

////////////////////////////////////////////////////////////////////////////////
// Dato
////////////////////////////////////////////////////////////////////////////////

Driver::Dato::Dato(const aed2::Nat& x)
  : tipo_( NAT ), nat_( x )
{}

Driver::Dato::Dato(const aed2::String& x)
  : tipo_( STR ), str_( x )
{}

bool Driver::Dato::esNat() const
{
  return tipo_ == NAT;
}

bool Driver::Dato::esString() const
{
  return tipo_ == STR;
}

TipoCampo Driver::Dato::tipo() const
{
  return tipo_;
}

const aed2::Nat& Driver::Dato::dameNat() const
{
  assert( esNat() );
  return nat_;
}

const aed2::String& Driver::Dato::dameString() const
{
  assert( esString() );
  return str_;
}

bool Driver::Dato::operator == (const Dato& otro) const
{
  return tipo_ == otro.tipo_ and (
    ( tipo_ == NAT and nat_ == otro.nat_ ) or
    ( tipo_ == STR and str_ == otro.str_ )
  );
}

bool Driver::Dato::operator != (const Dato& otro) const
{
  return not (*this == otro);
}

////////////////////////////////////////////////////////////////////////////////
// Base de datos
////////////////////////////////////////////////////////////////////////////////

Driver::Driver(){
	BaseDatos BD= BaseDatos();
}

Driver::~Driver(){}

// Tablas
void Driver::crearTabla(const NombreTabla& nombre, const aed2::Conj<Columna>& columnas, const aed2::Conj<NombreCampo>& claves){
	Tabla nuevaTabla(nombre,claves,columnas);
	BD.AgregarTabla(nuevaTabla);
}

void Driver::insertarRegistro(const NombreTabla& tabla, const Driver::Registro& reg){
	//~ std::cout << "insertarRegistroDriver" << std::endl;
	BD.InsertarEntrada(pasarDRegAReg(reg), tabla);
	//~ std::cout << "insertarRegistroDriverFin" << std::endl;
}

void Driver::borrarRegistro(const NombreTabla& tabla, const NombreCampo& columna, const Dato& valor){
	tp3::Dato val = pasarDDatoADato(valor);
	tp3::Registro regBorrar(columna, val);
	//~ std::cout << "CampoBorrar: " << columna << std::endl;
	BD.Borrar(regBorrar, tabla);
}

aed2::Conj<Columna> Driver::columnasDeTabla(const NombreTabla& tabla) const{
	return BD.DameTabla(tabla).dameColumnas();
}

aed2::Conj<NombreCampo> Driver::columnasClaveDeTabla(const NombreTabla& tabla) const{
	Tabla tablaCompleta = BD.DameTabla(tabla);
	return tablaCompleta.Claves();
}


aed2::Conj<Driver::Registro> Driver::registrosDeTabla(const NombreTabla& tabla)const{
	Tabla tablaCompl = BD.DameTabla(tabla);
	aed2::Lista<tp3::Registro> listaReg = tablaCompl.Registros();
	aed2::Conj<tp3::Registro> conjReg = deListaAConjReg(listaReg);
	//~ std::cout << listaReg.Longitud() << std::endl;
	return pasarConjRegAConjDReg(conjReg);
}

aed2::Nat Driver::cantidadDeAccesosDeTabla(const NombreTabla& tabla) const{
	return BD.CantidadDeAccesos(tabla);
}

Driver::Dato Driver::minimo(const NombreTabla& tabla, const NombreCampo& columna) const{
	return pasarDatoADDato(BD.DameTabla(tabla).Minimo(columna));
}

Driver::Dato Driver::maximo(const NombreTabla& tabla, const NombreCampo& columna) const{
	return pasarDatoADDato(BD.DameTabla(tabla).Maximo(columna));
}

aed2::Conj<Driver::Registro> Driver::buscar(const NombreTabla& tabla, const Registro& criterio) const{
	aed2::Lista<ItLista> listaItLista = BD.Buscar(pasarDRegAReg(criterio), tabla);
	aed2::Lista<ItLista>::Iterador itListaItLista = listaItLista.CrearIt();
	aed2::Conj<Driver::Registro> conjDReg;
	while(itListaItLista.HaySiguiente()){
		tp3::Registro regAgregar = itListaItLista.Siguiente().Siguiente();
		conjDReg.Agregar( pasarRegADReg(regAgregar));
		itListaItLista.Avanzar();
	}
	return conjDReg;
}




aed2::Conj<NombreTabla> Driver::tablas() const{
	aed2::Lista<aed2::NombreTabla> tablas = BD.Tablas();
	return deListaAConj(tablas);
}

const NombreTabla Driver::tablaMaxima() const{
	return BD.TablaMaxima();
}

// Indices

bool Driver::tieneIndiceNat(const NombreTabla& tabla) const{
	aed2::Conj<aed2::NombreCampo>::Iterador itIndices = BD.DameTabla(tabla).Indices().CrearIt();
	while(itIndices.HaySiguiente()){
		if(BD.DameTabla(tabla).TipoDelCampo(itIndices.Siguiente()) == NAT) return true;
		itIndices.Avanzar();
	}
	return false;
}

bool Driver::tieneIndiceString(const NombreTabla& tabla) const{
	aed2::Conj<aed2::NombreCampo>::Iterador itIndices = BD.DameTabla(tabla).Indices().CrearIt();
	while(itIndices.HaySiguiente()){
		if(BD.DameTabla(tabla).TipoDelCampo(itIndices.Siguiente()) == STR) return true;
		itIndices.Avanzar();
	}
	return false;
}

const NombreCampo& Driver::campoIndiceNat(const NombreTabla& tabla) const{
	aed2::Conj<aed2::NombreCampo>::Iterador itIndices = BD.DameTabla(tabla).Indices().CrearIt();
	while(itIndices.HaySiguiente()){
		if(BD.DameTabla(tabla).TipoDelCampo(itIndices.Siguiente()) == NAT) return itIndices.Siguiente();
		itIndices.Avanzar();
	}
}

const NombreCampo& Driver::campoIndiceString(const NombreTabla& tabla) const{
	aed2::Conj<aed2::NombreCampo>::Iterador itIndices = BD.DameTabla(tabla).Indices().CrearIt();
	while(itIndices.HaySiguiente()){
		if(BD.DameTabla(tabla).TipoDelCampo(itIndices.Siguiente()) == STR) return itIndices.Siguiente();
		itIndices.Avanzar();
	}
}

void Driver::crearIndiceNat(const NombreTabla& tabla, const NombreCampo& campo){
	Tabla tablaCompl = BD.DameTabla(tabla);
	tablaCompl.Indexar(campo);
}

void Driver::crearIndiceString(const NombreTabla& tabla, const NombreCampo& campo){
	Tabla tablaCompl = BD.DameTabla(tabla);
	tablaCompl.Indexar(campo);
}

// Joins

bool Driver::hayJoin(const NombreTabla& tabla1, const NombreTabla& tabla2) const{
	return BD.HayJoin(tabla1, tabla2);
}

const NombreCampo& Driver::campoJoin(const NombreTabla& tabla1, const NombreTabla& tabla2) const{
	return BD.CampoJoin(tabla1, tabla2);
}

void Driver::generarVistaJoin(const NombreTabla& tabla1, const NombreTabla& tabla2, const NombreCampo& campo){
	BD.GenerarVistaJoin(tabla1, tabla2, campo);
}

void Driver::borrarVistaJoin(const NombreTabla& tabla1, const NombreTabla& tabla2){
	BD.BorrarJoin(tabla1,tabla2);
}

Driver::Registro unir(const Driver::Registro& reg1, const Driver::Registro& reg2, const NombreCampo& clave){
// TODO ...
  assert(false);
}

aed2::Conj<Driver::Registro> Driver::vistaJoin(const NombreTabla& tabla1, const NombreTabla& tabla2){
	aed2::Lista<tp3::Registro> listaReg = BD.VistaJoin(tabla1, tabla2);
	aed2::Lista<tp3::Registro>::Iterador itListaReg =  listaReg.CrearIt();
	aed2::Conj<Driver::Registro> conjDReg;
	while(itListaReg.HaySiguiente()){
		conjDReg.Agregar(pasarRegADReg(itListaReg.Siguiente()));
		itListaReg.Avanzar();
	}
	return  conjDReg; 
}
