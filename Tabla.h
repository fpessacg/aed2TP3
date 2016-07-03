#ifndef TABLA_H_
#define TABLA_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Auxiliares.h"
#include "Registro.h"
#include "aed2/TiposBasicos.h"


namespace aed2
{

class Tabla{ 
	public:
	
	
	private:
		typedef Lista<Registro>::Iterador ItLista;
		struct IndicesString {
			Dicc<String, Conj<ItLista> > indiceString;
			NombreCampo campo;
			String maxString;
			String minString;
		};

		struct IndicesNat {
			Dicc<Nat, Conj<ItLista> > indiceNat;
			NombreCampo campo;
			Nat maxString;
			Nat minString;
		};
	
		NombreTabla nombre;
		Nat cantAccesos;
		Dupla< IndicesString, IndicesNat> indices;
		Conj<NombreCampo> campos;
		Lista<Registro> registros;
		Conj<NombreCampo> claves;
	
	
};

    /**
     * inicializa una tabla vacía.
     */
     //~ Tabla();

    /**
     * destruye el contenido de la tabla, liberando la memoria dinámica alocada.
     */
     //~ ~Tabla();
    



}
#endif // TABLA_H_
