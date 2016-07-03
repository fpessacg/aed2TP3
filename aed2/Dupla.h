#ifndef __DUPLA_H__
#define __DUPLA_H__

#include <iostream>
#include <cassert>

namespace aed2
{

template<class T, class U>

struct Dupla {
	Dupla();
	Dupla(const T& a,const U& b);
	bool operator==(const Dupla<T,U>&);
	bool operator!=(const Dupla<T,U>&);
		
	T x;
	U y;
};


template<class T, class U>
Dupla<T,U>::Dupla(){}

template<class T, class U>
Dupla<T,U>::Dupla(const T& a,const U& b) {
	x = a;
	y = b;
}


template<class T, class U>
std::ostream& operator<<(std::ostream& out, const Dupla<T,U>& l) {
	out<<"("<< l.x<<"/" << l.y<< ")";
	return out;
}

template<class T, class U>
bool Dupla<T,U>::operator==(const Dupla<T,U>& l) {
	return (x==l.x) && (y==l.y);
}

template<class T, class U>
bool Dupla<T,U>::operator!=(const Dupla<T,U>& l) {
	return ! (*this==l);
}

}

#endif
