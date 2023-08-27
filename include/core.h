// scene.hpp
#pragma once
#include <raylib.h>
#include <vector>

Vector3 operator+(Vector3 const &a, float Add);

namespace libengine::core {
class Scene;
struct SceneCam;
namespace objects {
struct Object {
  Vector3 position;
  Vector3 size;
  Color color;
  Color outline;
  BoundingBox Bbox;
  Object(Vector3 pos, Vector3 size, Color color, Color outline)
      : position(pos), size(size), color(color), outline(outline){};
  virtual ~Object(){};
  virtual void draw(SceneCam &cam) const {};
};

struct CubeObject : public Object {
  CubeObject(Vector3 pos, Vector3 size, Color color, Color outline)
      : Object(pos, size, color, outline) {
    Bbox = {
        (Vector3){pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2},
        (Vector3){pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2}};
  }

  void draw(SceneCam &cam) const override;
};

} // namespace objects

struct SceneCam {
  Camera3D cam;
  Ray ray;
  RayCollision raycol;

  SceneCam();
  void handleColision(const std::vector<objects::Object *> &objects);
};
class Scene {
public:
  Scene();

  void render();
  void add_object(objects::Object *object);
  void cleanUp();

  SceneCam cam;
  std::vector<objects::Object *> objects;
};
} // namespace libengine::core
