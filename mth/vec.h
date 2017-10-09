#ifndef _MTH_VEC_H_
#define _MTH_VEC_H_

#include "def.h"


namespace v3d
{

class VEC {
public:
   VEC (void);
   VEC (const VEC & vec);
   VEC (REAL x, REAL y, REAL z);
   VEC & Set (REAL x, REAL y, REAL z);

   REAL & operator[] (UINT i);
   const REAL & operator[] (UINT i) const;

   REAL Lenght (void) const;
   VEC & Negate (void);
   VEC & Normalize (void);
   VEC & Add (const VEC & rhs);
   VEC & Subtract (const VEC & rhs);
   VEC & Multiply (REAL rhs);
   VEC & MultiplyVector (const VEC & rhs);

   REAL x;
   REAL y;
   REAL z;
};

VEC & Negation (const VEC & vec, VEC & res);
VEC & Normalization (const VEC & vec, VEC & res);
VEC & Sum (const VEC & lhs, const VEC & rhs, VEC & res);
VEC & Difference (const VEC & lhs, const VEC & rhs, VEC & res);
VEC & Product (const VEC & lhs, REAL rhs, VEC & res);
REAL  DotProduct (const VEC & lhs, const VEC & rhs);
VEC & CrossProduct (const VEC & lhs, const VEC & rhs, VEC & res);

bool operator==(const MATR & lhs, const VEC & rhs); // ???

} // namespace v3d


#endif // _MTH_VEC_H_
