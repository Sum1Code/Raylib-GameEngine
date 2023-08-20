#include "scene.hpp"
#include <raylib.h>
#include <vector>

Scene::Scene(Object object) {
  cam = (Camera3D){.position = {0.0f, 10.0f, 10.0f},
                   .target = {0.0f, 0.0f, 0.0f},
                   .up = {0.0f, 1.0f, 0.0f},
                   .fovy = 45.0f,
                   .projection = CAMERA_PERSPECTIVE};

  objects.push_back(object);
}

void Scene::render() {
  BeginMode3D(cam);
  EndMode3D();
}
