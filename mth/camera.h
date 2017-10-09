#ifndef _MTH_CAMERA_H_
#define _MTH_CAMERA_H_

#include "def.h"


namespace v3d
{

class CAMERA {
public:
   CAMERA ();
   CAMERA (const CAMERA & camera);
   CAMERA (const VEC & pos, const VEC & look, const VEC & up);
   CAMERA & Set (const VEC & pos, const VEC & look, const VEC & up);
   // TODO
};

} // namespace v3d


#endif // _MTH_CAMERA_H_
