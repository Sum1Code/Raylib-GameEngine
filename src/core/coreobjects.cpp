#include "coreobjects.h"
#include "core.h"
using namespace libengine::core::objects;
using namespace libengine::core::scene;
void CubeObject::draw(SceneCam &cam) const {
  DrawCubeV(pos, size, color);

  if (cam.raycol.hit) {

    DrawCubeWiresV(pos, size + 0.2f, GREEN);
    DrawCubeWiresV(pos, size, outline);
  } else {

    DrawCubeWiresV(pos, size, outline);
  }
}
