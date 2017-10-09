#include "vec.h"
#include "funcs.h"


using namespace v3d;


VEC::VEC (void)
{
}


VEC::VEC (const VEC & vec) : VEC(vec.x, vec.y, vec.z)
{
}


VEC::VEC (REAL x, REAL y, REAL z) : x(x), y(y), z(z)
{
}


VEC & VEC::Set(REAL x, REAL y, REAL z)
{
   this->x = x;
   this->y = y;
   this->z = z;

   return *this;
}


REAL & VEC::operator[] (UINT i)
{
   return const_cast<REAL &>((*static_cast<const VEC *>(this))[i]);
}


const REAL & VEC::operator[] (UINT i) const
{
   switch (i)
   {
   case 0:
      return x;
   case 1:
      return y;
   case 2:
      return z;
   default:
      return 0; // ???
   }
}


REAL VEC::Lenght (void) const
{
   return sqrt(sqr(x) + sqr(y) + sqr(z));
}


VEC & VEC::Negate (void)
{
   return Negation(*this, *this);
}


VEC & VEC::Normalize (void)
{
   return Normalization(*this, *this);
}


VEC & VEC::Add (const VEC & rhs)
{
   return Sum(*this, rhs, *this);
}


VEC & VEC::Subtract (const VEC & rhs)
{
   return Difference(*this, rhs, *this);
}


VEC & VEC::Multiply (REAL rhs)
{
   return Product(*this, rhs, *this);
}


VEC & VEC::MultiplyVector (const VEC & rhs)
{
   return CrossProduct(*this, rhs, *this);
}


VEC & v3d::Negation (const VEC & vec, VEC & res)
{
   return res.Set(-vec.x, -vec.y, -vec.z);
}


VEC & v3d::Normalization (const VEC & vec, VEC & res)
{
   REAL l = vec.Lenght();
   if (l == 0)
      l = 1;
   return res.Set(vec.x / l, vec.y / l, vec.z / l);
}


VEC & v3d::Sum (const VEC & lhs, const VEC & rhs, VEC & res)
{
   return res.Set(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}


VEC & v3d::Difference (const VEC & lhs, const VEC & rhs, VEC & res)
{
   return res.Set(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}


VEC & v3d::Product (const VEC & lhs, REAL rhs, VEC & res)
{
   return res.Set(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}


REAL v3d::DotProduct (const VEC & lhs, const VEC & rhs)
{
   return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}


VEC & v3d::CrossProduct (const VEC & lhs, const VEC & rhs, VEC & res)
{
   return res.Set(lhs.y * rhs.z - lhs.z * rhs.y,
                  lhs.z * rhs.x - lhs.x * rhs.z,
                  lhs.x * rhs.y - lhs.y * rhs.x);
}
