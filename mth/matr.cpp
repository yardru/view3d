#include "vec.h"
#include "matr.h"


using namespace v3d;


MATR::MATR (void)
{
}


MATR::MATR (const MATR & matr) :
   MATR(matr[0][0], matr[0][1], matr[0][2], matr[0][3],
        matr[1][0], matr[1][1], matr[1][2], matr[1][3],
        matr[2][0], matr[2][1], matr[2][2], matr[2][3],
        matr[3][0], matr[3][1], matr[3][2], matr[3][3])
{
}


MATR::MATR (REAL a00, REAL a01, REAL a02, REAL a03,
            REAL a10, REAL a11, REAL a12, REAL a13,
            REAL a20, REAL a21, REAL a22, REAL a23,
            REAL a30, REAL a31, REAL a32, REAL a33) :
   components{ { a00, a01, a02, a03 },
               { a10, a11, a12, a13 },
               { a20, a21, a22, a23 },
               { a30, a31, a32, a33 } }
{
}


MATR & MATR::Set (REAL a00, REAL a01, REAL a02, REAL a03,
                  REAL a10, REAL a11, REAL a12, REAL a13,
                  REAL a20, REAL a21, REAL a22, REAL a23,
                  REAL a30, REAL a31, REAL a32, REAL a33)
{
   components[0][0] = a00;
   components[0][1] = a01;
   components[0][2] = a02;
   components[0][3] = a03;

   components[1][0] = a10;
   components[1][1] = a11;
   components[1][2] = a12;
   components[1][3] = a13;

   components[2][0] = a20;
   components[2][1] = a21;
   components[2][2] = a22;
   components[2][3] = a23;

   components[3][0] = a30;
   components[3][1] = a31;
   components[3][2] = a32;
   components[3][3] = a33;

   return *this;
}


REAL * MATR::operator[] (UINT i)
{
   return const_cast<REAL *>((*static_cast<const MATR *>(this))[i]);
}


const REAL * MATR::operator[] (UINT i) const
{
   return components[i];
}


REAL MATR::Cofactor (UINT i, UINT j) const
{
   UINT i1 = 0 + (i <= 0);
   UINT i2 = 1 + (i <= 1);
   UINT i3 = 2 + (i <= 2);
   UINT j1 = 0 + (j <= 0);
   UINT j2 = 1 + (j <= 1);
   UINT j3 = 2 + (j <= 2);
   REAL sign = ((i + j) % 2 == 0 ? 1 : -1);

   return sign * (
      components[i1][j1] * (components[i2][j2] * components[i3][j3] - components[i3][j2] * components[i2][j3]) -
      components[i2][j1] * (components[i1][j2] * components[i3][j3] - components[i3][j2] * components[i1][j3]) +
      components[i3][j1] * (components[i1][j2] * components[i2][j3] - components[i2][j2] * components[i1][j3]));
}

REAL MATR::Det (void) const
{
   return
      components[0][0] * Cofactor(0, 0) +
      components[1][0] * Cofactor(1, 0) +
      components[2][0] * Cofactor(2, 0) +
      components[3][0] * Cofactor(3, 0);
}


MATR & MATR::Negate (void)
{
   return Negation(*this, *this);
}


MATR & MATR::Transpose (void)
{
   REAL tmp;
   for (UINT i = 0; i < 3; i++)
      for (UINT j = i + 1; j < 4; j++) {
         tmp = components[i][j];
         components[i][j] = components[j][i];
         components[j][i] = tmp;
      }

   return *this;
}


MATR & MATR::Invert (void)
{
   MATR tmp(*this);
   return Inversion(tmp, *this);
}


MATR & MATR::Add (const MATR & rhs)
{
   return Sum(*this, rhs, *this);
}


MATR & MATR::Subtract (const MATR & rhs)
{
   return Difference(*this, rhs, *this);
}


MATR & MATR::Multiply (REAL rhs)
{
   return Product(*this, rhs, *this);
}


MATR & MATR::Multiply (const MATR & rhs)
{
   MATR tmp(*this);
   return Product(tmp, rhs, *this);
}


MATR & v3d::Negation (const MATR & matr, MATR & res)
{
   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++)
         res[i][j] = -matr[i][j];

   return res;
}


MATR & v3d::Transposition (const MATR & matr, MATR & res)
{
   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++)
         res[i][j] = matr[j][i];

   return res;
}


MATR & v3d::Inversion (const MATR & matr, MATR & res)
{
   REAL det = matr.Det();

   if (det == 0)
      return res; // ???

   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++)
         res[i][j] = matr.Cofactor(i, j) / det;

   return res;
}


MATR & v3d::Sum (const MATR & lhs, const MATR & rhs, MATR & res)
{
   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++)
         res[i][j] = lhs[i][j] + rhs[i][j];

   return res;
}


MATR & v3d::Difference (const MATR & lhs, const MATR & rhs, MATR & res)
{
   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++)
         res[i][j] = lhs[i][j] - rhs[i][j];

   return res;
}


MATR & v3d::Product (const MATR & lhs, REAL rhs, MATR & res)
{
   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++)
         res[i][j] = lhs[i][j] * rhs;

   return res;
}


MATR & v3d::Product (const MATR & lhs, const MATR & rhs, MATR & res)
{
   for (UINT i = 0; i < 4; i++)
      for (UINT j = 0; j < 4; j++) {
         res[i][j] = 0;
         for (UINT k = 0; k < 4; k++)
            res[i][j] += lhs[i][k] * rhs[k][j];
      }

   return res;
}


VEC & v3d::Product (const MATR & lhs, const VEC & rhs, VEC & res)
{
   for (UINT i = 0; i < 3; i++) {
      res[i] = 0;
      for (UINT k = 0; k < 3; k++)
         res[i] += lhs[i][k] * rhs[k];
   }

   return res;
}
