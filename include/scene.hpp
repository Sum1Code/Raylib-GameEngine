// scene.hpp
#pragma once
#include <raylib.h>
#include <vector>

struct Object {
  Vector3 position;
  Vector3 size;
  Color color;

  Object(Vector3 pos, Vector3 size, Color color)
      : position(pos), size(size), color(color){};
  virtual ~Object(){};
  virtual void draw() const {};
};

struct CubeObject : public Object {
  CubeObject(Vector3 pos, Vector3 size, Color color)
      : Object(pos, size, color) {}

  void draw() const override;
};

class Scene {
public:
  Scene();

  void render();
  void add_object(Object *object);

private:
  Camera3D cam;
  std::vector<Object *> objects;
};
