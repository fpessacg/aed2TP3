#include "Tabla.h"


using namespace aed2;



// Agrego un registor a la tabla
void AgregarRegistro(const Registro& r, Tabla& t){
}

// Borro un registro de la tabla
void BorrarRegistro(Registro& crit, Tabla& t){
}

// Creo un Indice en el campo c de la tabla
void Indexar(const NombreCampo& c, Tabla& t){
}

//Devuelvo el nombre de la tabla
NombreTabla& Nombre(const Tabla& t){
}

//Devuelvo un conjunto de las claves de la tabla
Conj<NombreCampo>::Iterador Claves(const Tabla& t){
}

// Devuelvo el conjunto de indices de la tabla
Conj<NombreCampo>::Iterador Indices(const Tabla& t){
}

// Devuelvo un iterador al conjunto de campos de la tabla
Conj<NombreCampo>::Iterador CamposTabla(const Tabla& t){
}

// Devuelvo el tipo del campo c de la tabla
//~ TipoCampo TipoCampo(const NombreCampo& c, const Tabla& t){
//~ }

// Devuelvo un iterador a la lista de registros de la tabla
Lista<Registro>::Iterador Registros(const Tabla& t){
}

//Devuelvo la cantidad de accesos de la tabla 
Nat CantidadDeAccesos(const Tabla t){
}

// Devuelvo el minimo dato de todos los registros para la tabla
Dato Minimo(const NombreCampo& c, const Tabla& t){
}

// Devuelvo el Maximo dato de todos los registros para la tabla
Dato Maximo(const NombreCampo& c, const Tabla& t){
}

// Devuelvo un bool que es true si se puede crear un indice en ese campo
bool PuedeIndexar(const NombreCampo& c, const Tabla& t){
}

// Da true si cr es no vacio, hay alguna coincidencia entre r y alguno de los cr
bool HayCoincidencia(const Registro& r, const Conj<NombreCampo>& cc, const Conj<Registro>& cr){
}

// Devuelve un iterador al conj de iteradores de Lista de Registros que coinciden 
Conj<Lista<Registro>::Iterador>::Iterador Coincidencias(const Registro& r, const Conj<Registro>& cr){
}

// Devuelve la comlumna de c en cr
Conj<Dato> DameColumna(const NombreCampo& r, const Conj<Registro>& cr){
}

// Devuelve true si los campos del registros son los mismos que de la tabla
bool MismosTipos(const Registro& r, const Tabla& t){
}
