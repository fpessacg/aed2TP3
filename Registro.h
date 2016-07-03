#ifndef REGISTRO_H_
#define REGISTRO_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Dato.h"
#include "aed2/TiposBasicos.h"



/**
 * Esta clase representa un registro, es decir, un mapeo de nombres de columna a valores.
 */
typedef aed2::Dicc<NombreCampo, Dato> Registro;



#endif // REGISTRO_H_
