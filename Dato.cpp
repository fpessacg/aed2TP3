
#include "Dato.h"

using namespace tp3;

Dato::Dato(const aed2::Nat& x)
  : tipo_( aed2::NAT ), nat_( x )
{}

Dato::Dato(const aed2::String& x)
  : tipo_( aed2::STR ), str_( x )
{}

bool Dato::esNat() const
{
  return tipo_ == aed2::NAT;
}

bool Dato::esString() const
{
  return tipo_ == aed2::STR;
}

aed2::TipoCampo Dato::tipo() const
{
  return tipo_;
}

const aed2::Nat& Dato::dameNat() const
{
  assert( esNat() );
  return nat_;
}

const aed2::String& Dato::dameString() const
{
  assert( esString() );
  return str_;
}

bool Dato::operator == (const Dato& otro) const
{
  return tipo_ == otro.tipo_ and (
    ( tipo_ == aed2::NAT and nat_ == otro.nat_ ) or
    ( tipo_ == aed2::STR and str_ == otro.str_ )
  );
}

bool Dato::operator < (const Dato& otro) const
{
  return tipo_ == otro.tipo_ and (
    ( tipo_ == aed2::NAT and nat_ < otro.nat_ ) or
    ( tipo_ == aed2::STR and str_ < otro.str_ )
  );
}

bool Dato::operator > (const Dato& otro) const
{
  return tipo_ > otro.tipo_ and (
    ( tipo_ == aed2::NAT and nat_ > otro.nat_ ) or
    ( tipo_ == aed2::STR and str_ > otro.str_ )
  );
}

bool Dato::operator != (const Dato& otro) const
{
  return not (*this == otro);
}

Dato Dato::max(const aed2::Conj<Dato> cd){
	aed2::Conj<Dato>::const_Iterador itConj = cd.CrearIt();
	Dato dMax = itConj.Siguiente();
	itConj.Avanzar();
	while( itConj.HaySiguiente() ){
		if(dMax < itConj.Siguiente() ){
			dMax = itConj.Siguiente();
		}
		itConj.Avanzar();
	}
	return dMax;
}

Dato Dato::min(const aed2::Conj<Dato> cd){
	aed2::Conj<Dato>::const_Iterador itConj = cd.CrearIt();
	Dato dMin = itConj.Siguiente();
	itConj.Avanzar();
	while( itConj.HaySiguiente() ){
		if(dMin > itConj.Siguiente() ){
			dMin = itConj.Siguiente();
		}
		itConj.Avanzar();
	}
	return dMin;
}

