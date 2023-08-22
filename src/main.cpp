#include <functions.hpp>
#include <iostream>
#include <raylib.h>
#include <scene.hpp>

int main(void) {
  auto cube1 = new libengine::CubeObject((Vector3){0, 0, 0}, (Vector3){2, 2, 2},
                                         BLUE, GREEN);
  auto scene = libengine::Scene();
  int camspeed = 60;
  scene.add_object(cube1);
  InitWindow(1920, 1080, "Game");
  while (!WindowShouldClose()) {
    SetTargetFPS(60);
    std::cout << camspeed << "\n";
    handle_inputs(camspeed, scene);
    scene.render();
  }
}
