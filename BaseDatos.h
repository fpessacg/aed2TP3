#ifndef DRIVER_H_
#define DRIVER_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dupla.h"
#include "aed2/Dicc.h"
#include "Auxiliares.h"
#include "Tabla.h"
#include "DiccLog.h"
#include "DiccString.h"
#include "aed2/TiposBasicos.h"

namespace aed2
{
	class Driver
	{
		public:	
		
		
		private:	
			
		struct InfoJoin
		{

		  NombreCampo campo;
		  Lista<Dupla<Registro, bool> > regActualizar;	   
		  Tabla registroJoin;
		};
		
		struct InfoTabla
		{
		  Dicc<NombreTabla, InfoJoin>  joins;
		  Tabla tablaData;
		};
		
		Dicc<NombreTabla, InfoTabla> tablasBD;
		Nat cantAccesoMax;
		NombreTabla nombreAccesoMax;
		Lista<NombreTabla> tablaLista;

	};

}
#endif // DRIVER_H_
