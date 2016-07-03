#ifndef REGISTRO_H_
#define REGISTRO_H_

#include "Tipos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Dupla.h"
#include "Auxiliares.h"
#include "aed2/TiposBasicos.h"


namespace aed2
{ 
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
        bool operator != (const Dato& otro) const;

      private:

        TipoCampo tipo_;

        aed2::Nat nat_;
        aed2::String str_;
    };

    /**
     * Esta clase representa un registro, es decir, un mapeo de nombres de columna a valores.
     */
    typedef aed2::Dicc<NombreCampo, Dato> Registro;

}
#endif // REGISTRO_H_
