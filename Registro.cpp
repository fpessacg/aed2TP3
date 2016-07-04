
#include "Registro.h"

// Devuelve el conjunto de campos del registro
aed2::Conj<NombreCampo> Registro::campos() const{
	aed2::Dicc<NombreCampo, Dato>::const_Iterador itReg = reg.CrearIt();
	aed2::Conj<NombreCampo> conj;
	while(itReg.HaySiguiente()){
		conj.AgregarRapido(itReg.SiguienteClave());
		itReg.Avanzar();
	}
	return conj;
}

// Borro los datos del registro para los cuales coinciden los campos con criterio
bool Registro::puedoBorrar(const Registro& criterio) const{
	aed2::Dicc<NombreCampo, Dato>::const_Iterador itReg  = reg.CrearIt();
	// la cantidad de campos de Criterio es 1
	aed2::Conj<NombreCampo>::Iterador itCamCrit = criterio.campos().CrearIt();
	while(itReg.HaySiguiente()){
		if(itReg.SiguienteClave() == itCamCrit.Siguiente())return true;
		itReg.Avanzar();
	}
	return false;
}

// Agrego campos al registro rAgr
aed2::Dicc<NombreCampo, Dato>& Registro::agregarCampos(const Registro& rAgr){
	
}

// copio los campos que estan en el conjunto al registro r2
Registro& Registro::copiarCampos(const aed2::Conj<NombreCampo>& cc, const Registro& rAgr){

}

// Devuelve True si conincide alguno 
bool Registro::coincideAlguno( aed2::Conj<NombreCampo>& cc, Registro& rRef) const{

}

//Devuelve True si conincide Todos 
bool Registro::coincideTodos( aed2::Conj<NombreCampo>& cc, Registro& rRef) const{

}

//Devuelve True si el campo esta en todos los registros 
bool Registro::enTodos( NombreCampo c, const aed2::Conj< Registro >& cr){

}

//Devuelve un conjunto del cr, de forma que el valor de el campo c en r vale lo mismo para todos los reg
aed2::Conj<Registro> Registro::combinarTodos(NombreCampo& c,const aed2::Conj<Registro> cr){

}

// Devuelvo el significado del campo 
Dato Registro::Significado(const NombreCampo c) const{
	return reg.Significado(c);
}

// Devuelvo True si esta definido el campo
bool Registro::estaDefinido(const NombreCampo c){
	return reg.Definido(c);
}

