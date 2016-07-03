#ifndef DATO_H_
#define DATO_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "aed2/TiposBasicos.h"


typedef aed2::String NombreTabla;
typedef aed2::String NombreCampo;

enum TipoCampo { NAT, STR };


/**
 * Esta clase representa un dato, que puede tomar valores de String o de Nat.
 */
class Dato
{
  public:

	Dato(const aed2::Nat& x);
	Dato(const aed2::String& x);

	bool esNat() const;
	bool esString() const;
	TipoCampo tipo() const;

	const aed2::Nat& dameNat() const;
	const aed2::String& dameString() const;

	bool operator == (const Dato& otro) const;	
	bool operator <  (const Dato& otro) const;
	bool operator >  (const Dato& otro) const;
	bool operator != (const Dato& otro) const;

	static Dato max(const aed2::Conj<Dato> cd); 
	static Dato min(const aed2::Conj<Dato> cd); 

  private:

	TipoCampo tipo_;

	aed2::Nat nat_;
	aed2::String str_;
};


#endif // DATO_H_
