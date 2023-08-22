
#include <functions.hpp>
#include <iostream>
#include <raylib.h>
#include <scene.hpp>

int main(void) {
  CubeObject *c1 = new CubeObject((Vector3){0.0f, 0.0f, 0.0f},
                                  (Vector3){2.0f, 2.0f, 2.0f}, BLUE);
  Scene main = Scene();
  main.add_object(c1);
  // main.add_object(c2);
  InitWindow(800, 600, "Game");
  while (!WindowShouldClose()) {
    SetTargetFPS(60);
    main.render();
  }
  // TODO: ADD CLEANUP CODE
}
