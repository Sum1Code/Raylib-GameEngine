
#include <functions.hpp>
#include <iostream>
#include <raylib.h>

int main(void) {
  InitWindow(800, 600, "Game");
  while (!WindowShouldClose()) {
    AppMain();
  }
}
