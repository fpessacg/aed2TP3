#include "BaseDatos.h"





// Agrego una nueva tabla a la BD
void AgregarTabla(Tabla& t, BaseDatos& bd){
}

// Agrego un Registro a una Tabla
void InstertarEntrada(const Registro& r, Tabla& t, BaseDatos& b){
}

//borrar un registro de una tabla
void Borrar(const Registro& r, Tabla& t, BaseDatos& bd){
}

// Devuelvo un iterador a los nombres de las tablas de la BD
aed2::Lista<aed2::NombreTabla>::Iterador Tablas(const BaseDatos& bd){
}

// Devuelvo la tabla que me piden
Tabla& DameTabla(const aed2::NombreTabla&, const BaseDatos& bd){
}

// Devuelve la tabla con mayor cantidad de accesos en BD
aed2::NombreTabla& TablaMaxima(const BaseDatos& bd){
}

// Devuelve el campo para los cuales dos tablas estan vinculadas
aed2::NombreCampo& CampoJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd){
}

// Devuelve true si hay joint entra las dos tablas 
bool HayJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd){
}

// Elimina el Joint entre tablas
void BorrarJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd){
}

// Genera el Join entre dos tablas 
void GenerarVistaJoin(const Tabla& t1, const Tabla& t2, const aed2::NombreCampo& ca, const BaseDatos& bd){
}

// Visualiza el Join entre dos tablas 
aed2::Conj<Registro> VistaJoin(const Tabla& t1, const Tabla& t2, const BaseDatos& bd){
}

// Busca los registro que conincidan con r en la tabla de la base de datos
aed2::Conj<Registro> Buscar(const Registro& r, const Tabla& t, const BaseDatos& bd){
}

// Devuelve el nombre de la tabla que tuvo mayor cant de Accesos
aed2::NombreTabla EncontrarMaximo(const aed2::NombreTabla& t, const aed2::Conj<aed2::NombreTabla>&  conjTab, const BaseDatos& bd){
}

// devuelve la cantidad de acsesos de una tabla
aed2::Nat CantidadDeAccesos(const aed2::NombreTabla& t, const BaseDatos& bd){
}

// devuelve los registros de una tabla
aed2::Conj<Registro> Registros(const Tabla& t, const BaseDatos& bd){

}
