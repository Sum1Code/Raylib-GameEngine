#include "corescene.h"
#include "coreobjects.h"
#include <memory>
#include <raylib.h>
using namespace libengine::core::scene;
using namespace libengine::core::objects;
Scene::Scene() {}
SceneCam::SceneCam() {
  cam = (Camera3D){.position = {10.0f, 10.0f, 10.0f},
                   .target = {0.0f, 0.0f, 0.0f},
                   .up = {0.0f, 1.0f, 0.0f},
                   .fovy = 45.0f,
                   .projection = CAMERA_PERSPECTIVE};
  ray = {0};
  raycol = {0};
}

void Scene::render() {
  if (IsCursorHidden())
    UpdateCamera(&cam.cam, CAMERA_FREE);
  cam.handleColision(objects);
  BeginDrawing();
  ClearBackground(RAYWHITE);
  BeginMode3D(cam.cam);
  DrawGrid(200, 1.0f);
  for (const auto &object : objects) {
    object->draw(cam);
  }
  DrawRay(cam.ray, MAROON);
  EndMode3D();
  EndDrawing();
}

void Scene::add_object(ObjectType objtype, const ObjectParams params) {
  switch (objtype) {
  case (ObjectType::CUBE):
    auto yes = std::make_unique<CubeObject>(
        CubeObject(params)); // new CubeObject(params);
    objects.push_back(std::move(yes));
    break;
  }
}
void Scene::add_object(ObjectType objtype) {
  switch (objtype) {
  case (ObjectType::CUBE):
    auto yes = std::make_unique<CubeObject>(
        CubeObject({{0, 0, 0}, {2, 2, 2}, BLUE, GREEN}));
    objects.push_back(std::move(yes));
    break;
  }
}

void SceneCam::handleColision(
    const std::vector<std::unique_ptr<Object>> &objects) {

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    if (!raycol.hit) {
      ray = GetMouseRay(GetMousePosition(), cam);

      // Check collision between ray and box
      raycol = GetRayCollisionBox(ray, objects[0]->Bbox);
    } else
      raycol.hit = false;
  }
}
