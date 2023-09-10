#include "coreobjects.h"
#include "core.h"
#include <raylib.h>
using namespace libengine::core::objects;
using namespace libengine::core::scene;
void CubeObject::draw(SceneCam &cam) const {
  DrawCubeV(pos, size, color);
  // DrawCubeV({0, 0, 0}, {2, 2, 2}, RED);
  if (IsHitByRay) {

    DrawCubeWiresV(pos, size + 0.2f, GREEN);
    DrawCubeWiresV(pos, size, outline);
  } else {

    DrawCubeWiresV(pos, size, outline);
  }
}
