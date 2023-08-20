
#pragma once
#include <raylib.h>
#include <vector>

struct Object {
  Object(){};
  virtual ~Object(){};
};

struct CUBE : public Object {
  Vector3 position;
  Vector3 size;
  Color color;
  CUBE(Vector3 position, Vector3 size, Color color)
      : position(position), size(size), color(color) {}
};

class Scene {
public:
  Scene(Object object);

  void render();

private:
  Camera3D cam;
  std::vector<Object> objects;
};
