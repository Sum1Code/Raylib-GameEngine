#include "core.h"
#include "functions.h"
#include <iostream>

using namespace libengine::core::objects;
using namespace libengine::core;
int main(void) {
  auto cube1 =
      new CubeObject((Vector3){0, 0, 0}, (Vector3){2, 2, 2}, BLUE, GREEN);
  auto cube2 =
      new CubeObject((Vector3){4, 0, 4}, (Vector3){2, 2, 2}, BLUE, GREEN);

  auto scene = Scene();
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
