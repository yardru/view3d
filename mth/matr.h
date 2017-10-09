#ifndef _MTH_MATR_H_
#define _MTH_MATR_H_

#include "def.h"

namespace v3d
{

class MATR {
public:
   MATR (void);
   MATR (const MATR & matr);
   MATR (REAL a00, REAL a01, REAL a02, REAL a03,
         REAL a10, REAL a11, REAL a12, REAL a13,
         REAL a20, REAL a21, REAL a22, REAL a23,
         REAL a30, REAL a31, REAL a32, REAL a33);
   MATR & Set (REAL a00, REAL a01, REAL a02, REAL a03,
               REAL a10, REAL a11, REAL a12, REAL a13,
               REAL a20, REAL a21, REAL a22, REAL a23,
               REAL a30, REAL a31, REAL a32, REAL a33);

   REAL * operator[] (UINT i);
   const REAL * operator[] (UINT i) const;

   REAL Cofactor (UINT i, UINT j) const;
   REAL Det (void) const;
   MATR & Negate (void);
   MATR & Transpose (void);
   MATR & Invert (void);
   MATR & Add (const MATR & rhs);
   MATR & Subtract (const MATR & rhs);
   MATR & Multiply (REAL rhs);
   MATR & Multiply (const MATR & rhs);
private:

   REAL components[4][4];
};

MATR & Negation (const MATR & matr, MATR & res);
MATR & Transposition (const MATR & matr, MATR & res);
MATR & Inversion (const MATR & matr, MATR & res);
MATR & Sum (const MATR & lhs, const MATR & rhs, MATR & res);
MATR & Difference (const MATR & lhs, const MATR & rhs, MATR & res);
MATR & Product (const MATR & lhs, REAL rhs, MATR & res);
MATR & Product (const MATR & lhs, const MATR & rhs, MATR & res);
VEC  & Product (const MATR & lhs, const VEC & rhs, VEC & res);

bool operator==(const MATR & lhs, const VEC & rhs); // ???

} // namespace v3d

#endif // _MTH_MATR_H_
