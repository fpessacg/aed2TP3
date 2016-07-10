// compilar usando:
//   g++ -o tests tests.cpp Driver.cpp <lista de archivos *.cpp propios>

#include "BaseDatos.h"
#include "mini_test.h"

#include <string>
#include <iostream>
 //~ 
//~ bool aed2::operator == (const aed2::Columna& c1, const aed2::Columna& c2)
//~ {
  //~ return c1.nombre == c2.nombre and c1.tipo == c2.tipo;
//~ }

void ejemplo_simple(){
  BaseDatos bd;
  ASSERT_EQ(bd.Tablas().EsVacia(), true);

  aed2::Conj<aed2::NombreCampo> columnas_personas;

  aed2::Columna columna_dni;
  columna_dni.nombre = "DNI";
  columna_dni.tipo = aed2::NAT;

  aed2::Columna columna_nombre;
  columna_nombre.nombre = "nombre";
  columna_nombre.tipo = aed2::STR;

  aed2::Columna columna_apellido;
  columna_nombre.nombre = "apellido";
  columna_nombre.tipo = aed2::STR;

  //~ columnas_personas.Agregar( columna_dni );
  //~ columnas_personas.Agregar( columna_nombre );
  //~ columnas_personas.Agregar( columna_apellido );
//~ 
  //~ aed2::Conj<aed2::NombreCampo> columnas_clave_personas;
  //~ Registros registroTabla();
  //~ columnas_clave_personas.Agregar("DNI");
//~ 
  //~ bd.AgregarTabla(Tabla("personas", columnas_clave_personas, registroTabla));
  //~ ASSERT_EQ(bd.tablas().Longitud(), 1);
//~ 
  //~ aed2::Registro persona;
  //~ persona.Definir("DNI", aed2::Dato(1));
  //~ persona.Definir("nombre", aed2::Dato("Juan"));
  //~ persona.Definir("apellido", aed2::Dato("Perez"));
//~ 
  //~ bd.insertarRegistro("personas", persona);
}

int main(int argc, char **argv)
{
  RUN_TEST( ejemplo_simple );

  /********************************************************************
   * TODO: escribir casos de test exhaustivos para todas              *
   * las funcionalidades de cada módulo.                              *
   * La interacción con el TAD principal se debe hacer exclusivamente *
   * a través de la interfaz del driver.                              *
   ********************************************************************/

	return 0;
}

