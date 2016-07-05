
#include "Dato.h"



Dato::Dato(const aed2::Nat& x)
  : tipo_( NAT ), nat_( x )
{}

Dato::Dato(const aed2::String& x)
  : tipo_( STR ), str_( x )
{}

bool Dato::esNat() const
{
  return tipo_ == NAT;
}

bool Dato::esString() const
{
  return tipo_ == STR;
}

TipoCampo Dato::tipo() const
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
    ( tipo_ == NAT and nat_ == otro.nat_ ) or
    ( tipo_ == STR and str_ == otro.str_ )
  );
}

bool Dato::operator < (const Dato& otro) const
{
  return tipo_ == otro.tipo_ and (
    ( tipo_ == NAT and nat_ < otro.nat_ ) or
    ( tipo_ == STR and str_ < otro.str_ )
  );
}

bool Dato::operator > (const Dato& otro) const
{
  return tipo_ > otro.tipo_ and (
    ( tipo_ == NAT and nat_ > otro.nat_ ) or
    ( tipo_ == STR and str_ > otro.str_ )
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

