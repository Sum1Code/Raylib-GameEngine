// scene.cpp
#include "core.h"
#include <iostream>
#include <raylib.h>
#include <vector>
using namespace libengine::core;
using namespace libengine::core::objects;

Vector3 operator+(Vector3 const &a, float Add) {
  return Vector3{a.x + Add, a.y + Add, a.z + Add};
}

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
  DrawGrid(100, 1.0f);
  for (const auto &object : objects) {
    object->draw(cam);
  }
  DrawRay(cam.ray, MAROON);
  EndMode3D();
  EndDrawing();
}

void Scene::add_object(Object *object) { objects.push_back(object); }
void CubeObject::draw(SceneCam &cam) const {
  DrawCubeV(position, size, color);

  if (cam.raycol.hit) {

    DrawCubeWiresV(position, size + 0.2f, GREEN);
    DrawCubeWiresV(position, size, outline);
  } else {

    DrawCubeWiresV(position, size, outline);
  }
}

void SceneCam::handleColision(
    const std::vector<libengine::core::objects::Object *> &objects) {

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    if (!raycol.hit) {
      ray = GetMouseRay(GetMousePosition(), cam);

      // Check collision between ray and box
      raycol = GetRayCollisionBox(ray, objects[0]->Bbox);
    } else
      raycol.hit = false;
  }
}
