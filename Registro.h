#ifndef REGISTRO_H_
#define REGISTRO_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "aed2/TiposBasicos.h"


class Registro
{
	public:
		//Constructor
		Registro(){}
		Registro(const aed2::NombreCampo&, const Dato&){}
		Registro(const aed2::Conj<aed2::NombreCampo>&, const aed2::Conj<Dato>&){}
		//Registro();
		// Devuelve el conjunto de campos del registro
		aed2::Conj<aed2::NombreCampo> campos() const;
		
		// Borro los datos del registro para los cuales coinciden los campos con criterio
		bool puedoBorrar(const Registro& criterio) const;
		
		// Agrego campos del registro que me pasan al registro
		Registro& agregarCampos(const Registro& rCrit);
		
		// copio los campos que estan en el conjunto al registro r2
		Registro& copiarCampos(const aed2::Conj<aed2::NombreCampo>& cc, const Registro& rCrit);
		
		// Devuelve True si conincide alguno 
		bool coincideAlguno(const aed2::Conj<aed2::NombreCampo>& cc, const Registro& rRef) const;
		
		//Devuelve True si conincide Todos 
		bool coincidenTodos(const aed2::Conj<aed2::NombreCampo>& cc, const Registro& rRef) const;
		
		//Devuelve True si el campo esta en todos los registros 
		static bool enTodos(const aed2::NombreCampo& c, const aed2::Conj<Registro>& cr);
		
		//Devuelve un conjunto del cr, de forma que el valor de el campo c en r vale lo mismo para todos los reg
		aed2::Conj<Registro> combinarTodos(const aed2::NombreCampo& c,const aed2::Conj<Registro> cr); 
		
		// Devuelvo el significado del campo 
		const Dato& Significado(const aed2::NombreCampo& c) const;
		
		// Devuelvo True si esta definido el campo
		bool estaDefinido(const aed2::NombreCampo& c) const;

	private:
		aed2::Dicc<aed2::NombreCampo, Dato> reg;
};

/**
 * Esta clase representa un registro, es decir, un mapeo de nombres de columna a valores.
 */
//~ typedef aed2::Dicc<aed2::NombreCampo, Dato> Registro;




#endif // REGISTRO_H_
