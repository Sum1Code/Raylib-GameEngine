#pragma once

#include "core.h"
#include "coreobjects.h"
#include <memory>
#include <raylib.h>
#include <vector>

namespace libengine::core::objects {
struct Object; // other forward decl
struct ObjectParams;
enum class ObjectType;
} // namespace libengine::core::objects
namespace libengine::core::scene {

struct SceneCam {
  Camera3D cam;
  Ray ray;
  RayCollision raycol;

  SceneCam();
  void
  handleColision(const std::vector<std::unique_ptr<objects::Object>> &objects);
};
class Scene {
public:
  Scene();

  void render();
  void add_object(objects::ObjectType objtype,
                  const objects::ObjectParams object);
  void add_object(objects::ObjectType objtype);

  void cleanUp();

  SceneCam cam;
  std::vector<std::unique_ptr<objects::Object>> objects;
};
} // namespace libengine::core::scene
