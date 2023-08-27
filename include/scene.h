// scene.hpp
#pragma once
#include <raylib.h>
#include <vector>

namespace libengine {

struct Object {
  Vector3 position;
  Vector3 size;
  Color color;
  Color outline;

  Object(Vector3 pos, Vector3 size, Color color, Color outline)
      : position(pos), size(size), color(color), outline(outline){};
  virtual ~Object(){};
  virtual void draw() const {};
};

struct CubeObject : public Object {
  CubeObject(Vector3 pos, Vector3 size, Color color, Color outline)
      : Object(pos, size, color, outline) {}

  void draw() const override;
};

class Scene {
public:
  Scene();

  void render();
  void add_object(Object *object);
  void cleanUp();

  Camera3D cam;

private:
  std::vector<Object *> objects;
};
} // namespace libengine
