// scene.cpp
#include "scene.h"

libengine::Scene::Scene() {
  cam = (Camera3D){.position = {10.0f, 10.0f, 10.0f},
                   .target = {0.0f, 0.0f, 0.0f},
                   .up = {0.0f, 1.0f, 0.0f},
                   .fovy = 45.0f,
                   .projection = CAMERA_PERSPECTIVE};
}

void libengine::Scene::render() {
  UpdateCamera(&cam, CAMERA_FREE);
  BeginDrawing();
  ClearBackground(RAYWHITE);
  BeginMode3D(cam);
  DrawGrid(100, 1.0f);
  for (const auto &object : objects) {
    object->draw();
  }
  EndMode3D();
  EndDrawing();
}

void libengine::Scene::add_object(Object *object) { objects.push_back(object); }
void libengine::CubeObject::draw() const {
  DrawCubeV(position, size, color);
  DrawCubeWiresV(position, size, outline);
}
