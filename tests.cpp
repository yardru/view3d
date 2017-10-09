#include <gtest\gtest.h>

#include "mth\mth.h"


TEST (MthTest, Vec)
{
   v3d::VEC v1, v2(1, 0, 0), v3(v2), v4;
   ASSERT_EQ(v2.x, v3.x);
   ASSERT_EQ(v2.y, v3.y);
   ASSERT_EQ(v2.z, v3.z);

   v1.Set(0, 1, 0);
   v3d::Sum(v1, v2, v3);
   v3.Normalize();
   ASSERT_NEAR(v3.Lenght(), 1, 1e-10);
   ASSERT_NEAR(v3d::DotProduct(v1, v3), sqrt(0.5), 1e-10);

   v3d::CrossProduct(v1, v2, v4);
   ASSERT_NEAR(v3d::DotProduct(v4, v3), 0, 1e-10);
   ASSERT_NEAR(v3.Lenght(), v4.Lenght(), 1e-10);

   v3d::Negation(v1, v2);
   v3d::Difference(v1, v2, v3);
   v3d::Product(v1, 2, v4);
   ASSERT_NEAR(v4.x, v3.x, 1e-10);
   ASSERT_NEAR(v4.y, v3.y, 1e-10);
   ASSERT_NEAR(v4.z, v3.z, 1e-10);
}


TEST (MthTest, Matr)
{
   v3d::MATR E = v3d::MATR(
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
   );
   ASSERT_NEAR(E.Det(), 1, 1e-10);

   v3d::MATR m1 = v3d::MATR(
      1, 0, 0, 0,
      0, 2, 0, 0,
      0, 0, 3, 0,
      0, 0, 0, 4
   );
   ASSERT_NEAR(m1.Det(), 24, 1e-10);

   v3d::MATR m2, m3(m1);
   v3d::Inversion(m1, m2);
   m3.Multiply(m2);
   ASSERT_NEAR(m2.Det(), 1.0 / 24, 1e-10);
   ASSERT_NEAR(m3.Det(), 1, 1e-10);

   m1.Set(
      5, 7, 5, 2,
      2, 4, 4, 1,
      1, 3, 9, 7,
      3, 8, 1, 8
   );
   v3d::Inversion(m1, m2);
   v3d::Product(m1, m2, m3);
   ASSERT_NEAR(m3.Det(), 1.0, 1e-10);
   v3d::Transposition(m1, m3);
   v3d::MATR m4(m2);
   m4.Transpose();
   v3d::Product(m3, m4, m1);
   ASSERT_NEAR(m1.Det(), 1.0, 1e-10);

   m1.Set(
      0, -1, 0, 0,
      1, 0, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
   );
   v3d::VEC v1(1, 0, 0), v2;
   v3d::Product(m1, v1, v2);
   ASSERT_NEAR(v3d::DotProduct(v1, v2), 0, 1e-10);
}

