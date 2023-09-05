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
  mainscene.add_object(ObjectType::CUBE, {{4, 0, 0}, {2, 2, 2}, RED, BLUE});
  InitWindow(1920, 1080, "Game");
  while (!WindowShouldClose()) {

    SetTargetFPS(fps);
    handle_inputs(fps, mainscene);
    mainscene.render();
  }
  return 0;
}
