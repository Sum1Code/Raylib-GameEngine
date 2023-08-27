#include "functions.h"
#include "scene.h"
#include <iostream>

int main(void) {
  auto cube1 = new libengine::CubeObject((Vector3){0, 0, 0}, (Vector3){2, 2, 2},
                                         BLUE, GREEN);
  auto cube2 = new libengine::CubeObject((Vector3){4, 0, 4}, (Vector3){2, 2, 2},
                                         BLUE, GREEN);

  auto scene = libengine::Scene();
  int fps = 60;
  scene.add_object(cube1);
  scene.add_object(cube2);
  InitWindow(1920, 1080, "Game");
  while (!WindowShouldClose()) {
    SetTargetFPS(fps);
    std::cout << fps << "\n";
    handle_inputs(fps, scene);
    scene.render();
  }
}
