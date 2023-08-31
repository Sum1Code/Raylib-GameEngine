#pragma once
#include "corescene.h"
#include <raylib.h>
namespace libengine::core::scene {
struct SceneCam; // Forward declaration

} // namespace libengine::core::scene
namespace libengine::core::objects {

enum class ObjectType { CUBE };
struct ObjectParams {
  Vector3 position;
  Vector3 size;
  Color color;
  Color outline;
};

struct Object {
  Vector3 pos;
  Vector3 size;
  Color color;
  Color outline;
  BoundingBox Bbox;
  bool IsHitByRay;

  Object(ObjectParams params)
      : pos(params.position), size(params.position), color(params.color),
        outline(params.outline), IsHitByRay(false) {}
  virtual ~Object(){};
  virtual void draw(scene::SceneCam &cam) const {};
};

struct CubeObject : public Object {
  CubeObject(const ObjectParams params) : Object(params) {
    Bbox = {
        (Vector3){pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2},
        (Vector3){pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2}};
    IsHitByRay = false;
  }

  void draw(scene::SceneCam &cam) const override;
};

} // namespace libengine::core::objects
