
#include <functions.hpp>
#include <iostream>
#include <raylib.h>
#include <scene.hpp>

int main(void) {
  CUBE c1 = CUBE((Vector3){0, 0, 0}, (Vector3){2, 2, 2}, BLUE);
  Scene main = Scene(c1);

  InitWindow(800, 600, "Game");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    main.render();
    EndDrawing();
  }
}
