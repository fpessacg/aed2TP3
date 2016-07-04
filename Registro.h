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
		Registro();
		//Registro();
		// Devuelve el conjunto de campos del registro
		aed2::Conj<NombreCampo> campos() const;
		
		// Borro los datos del registro para los cuales coinciden los campos con criterio
		bool puedoBorrar(const Registro& criterio) const;
		
		// Agrego campos al registro rAgr
		aed2::Dicc<NombreCampo, Dato>& agregarCampos(const Registro& rAgr);
		
		// copio los campos que estan en el conjunto al registro r2
		Registro& copiarCampos(const aed2::Conj<NombreCampo>& cc, const Registro& rAgr);
		
		// Devuelve True si conincide alguno 
		bool coincideAlguno( aed2::Conj<NombreCampo>& cc, Registro& rRef) const;
		
		//Devuelve True si conincide Todos 
		bool coincideTodos( aed2::Conj<NombreCampo>& cc, Registro& rRef) const;
		
		//Devuelve True si el campo esta en todos los registros 
		static bool enTodos( NombreCampo c, const aed2::Conj<Registro>& cr);
		
		//Devuelve un conjunto del cr, de forma que el valor de el campo c en r vale lo mismo para todos los reg
		aed2::Conj<Registro> combinarTodos(NombreCampo& c,const aed2::Conj<Registro> cr); 
		
		// Devuelvo el significado del campo 
		Dato Significado(const NombreCampo c) const;
		
		// Devuelvo True si esta definido el campo
		bool estaDefinido(const NombreCampo c);

	private:
		aed2::Dicc<NombreCampo, Dato> reg;
};

/**
 * Esta clase representa un registro, es decir, un mapeo de nombres de columna a valores.
 */
//~ typedef aed2::Dicc<NombreCampo, Dato> Registro;




#endif // REGISTRO_H_
