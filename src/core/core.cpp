// scene.cpp
#include "core.h"
#include <memory>
using namespace libengine::core::scene;
using namespace libengine::core::objects;

Vector3 operator+(Vector3 const &a, float Add) {
  return Vector3{a.x + Add, a.y + Add, a.z + Add};
}

// SECTION OBJECTS

// SESSION CAM
