
#include "Registro.h"

using namespace tp3;

//Constructor
	Registro::Registro(){}
	Registro::Registro(const aed2::NombreCampo& nombre, const Dato& dato){reg.Definir(nombre,dato);}
	Registro::Registro(const aed2::Conj<aed2::NombreCampo>& conjNombres, const aed2::Conj<Dato>& conjDatos){
		aed2::Conj<aed2::NombreCampo>::const_Iterador itConjNombres = conjNombres.CrearIt();
		aed2::Conj<Dato>::const_Iterador itConjDatos = conjDatos.CrearIt();
		while(itConjNombres.HaySiguiente()){
			reg.Definir(itConjNombres.Siguiente(), itConjDatos.Siguiente() );
			itConjNombres.Avanzar();
			itConjDatos.Avanzar();
		}
	}

// Devuelve el conjunto de campos del registro
aed2::Conj<aed2::NombreCampo> Registro::campos() const{
	aed2::Dicc<aed2::NombreCampo, Dato>::const_Iterador itReg = reg.CrearIt();
	aed2::Conj<aed2::NombreCampo> conj;
	while(itReg.HaySiguiente()){
		conj.AgregarRapido(itReg.SiguienteClave());
		itReg.Avanzar();
	}
	return conj;
}

// Borro los datos del registro para los cuales coinciden los campos con criterio
bool Registro::puedoBorrar(const Registro& criterio) const{
	aed2::Dicc<aed2::NombreCampo, Dato>::const_Iterador itReg  = reg.CrearIt();
	// la cantidad de campos de Criterio es 1
	aed2::Conj<aed2::NombreCampo>::Iterador itCamCrit = criterio.campos().CrearIt();
	while(itReg.HaySiguiente()){
		if(itReg.SiguienteClave() == itCamCrit.Siguiente())return true;
		itReg.Avanzar();
	}
	return false;
}

// Agrego campos del registro que me pasan al registro
Registro& Registro::agregarCampos(const Registro& rCrit){
	aed2::Conj<aed2::NombreCampo>::Iterador itrCrit = rCrit.campos().CrearIt();
	while(itrCrit.HaySiguiente()){
		if(!reg.Definido(itrCrit.Siguiente()) ){
			reg.DefinirRapido( itrCrit.Siguiente(), rCrit.Significado(itrCrit.Siguiente()));
		}
	itrCrit.Avanzar();
	}
	return *this;
}

// copio los campos que estan en el conjunto al registro r2
Registro& Registro::copiarCampos(const aed2::Conj<aed2::NombreCampo>& cc, const Registro& rCrit){
	aed2::Conj<aed2::NombreCampo>::const_Iterador itConj = cc.CrearIt();
	if(itConj.HaySiguiente()){
		while(itConj.HaySiguiente()){
			reg.Definir(itConj.Siguiente(), rCrit.Significado( itConj.Siguiente() ));
			itConj.Avanzar();
		}
	}
	return *this;
}

// Devuelve True si conincide alguno 
bool Registro::coincideAlguno(const aed2::Conj<aed2::NombreCampo>& cc, const Registro& rRef) const{
	aed2::Conj<aed2::NombreCampo>::const_Iterador itConj = cc.CrearIt();
	bool res = false;
	if(itConj.HaySiguiente()){
		while(itConj.HaySiguiente()){
			if(rRef.Significado(itConj.Siguiente() ) == reg.Significado( itConj.Siguiente() )){
				res = true;
			}
			itConj.Avanzar();
		}
	}
	return res;
}

//Devuelve True si conincide Todos 
bool Registro::coincidenTodos(const aed2::Conj<aed2::NombreCampo>& cc, const Registro& rRef) const{
	aed2::Conj<aed2::NombreCampo>::const_Iterador itConj = cc.CrearIt();
	bool res = true;
	if(itConj.HaySiguiente()){
		while(itConj.HaySiguiente()){
			if(!(rRef.Significado(itConj.Siguiente() ) == reg.Significado( itConj.Siguiente() ))){
				res = false;
			}
			itConj.Avanzar();
		}
	}
	return res;
}

//Devuelve True si el campo esta en todos los registros 
bool Registro::enTodos(const aed2::NombreCampo& c, const aed2::Conj< Registro >& cr){
	aed2::Conj< Registro >::const_Iterador itConj = cr.CrearIt();
	bool res = true;
	if(itConj.HaySiguiente()){
		while(itConj.HaySiguiente()){
			if( !(itConj.Siguiente().estaDefinido(c)) ){
				res = false;
			}
			itConj.Avanzar();
		}
	}
	return res;
}

//Devuelve un conjunto del cr, de forma que el valor de el campo c en r vale lo mismo para todos los reg
aed2::Conj<Registro> Registro::combinarTodos(const aed2::NombreCampo& c,const aed2::Conj<Registro> cr){
	aed2::Conj<Registro> ConjRes;
	aed2::Conj<Registro>::const_Iterador itConj = cr.CrearIt();
	if(itConj.HaySiguiente()){
		while(itConj.HaySiguiente()){
			if( reg.Significado(c) == (itConj.Siguiente().Significado(c)) ){
				ConjRes.AgregarRapido(itConj.Siguiente());
			}
			itConj.Avanzar();
		}
	}
	return ConjRes;
}

// Devuelvo el significado del campo 
const Dato& Registro::Significado(const aed2::NombreCampo& c) const{
	return reg.Significado(c);
}

// Devuelvo True si esta definido el campo
bool Registro::estaDefinido(const aed2::NombreCampo& c) const{
	return reg.Definido(c);
}

