#include "core.h"
#include "coreobjects.h"
#include "functions.h"
#include <iostream>
#include <raylib.h>

using namespace libengine::core::objects;
using namespace libengine::core::scene;
int main(void) {
  int fps = 60;
  auto mainscene = Scene();
  mainscene.add_object(ObjectType::CUBE);
  InitWindow(1920, 1080, "Game");
  SetTargetFPS(fps);
  while (!WindowShouldClose()) {
    handle_inputs(fps, mainscene);
    mainscene.render();
  }
  return 0;
}
