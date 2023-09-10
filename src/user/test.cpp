#include "core.h"
#include "coreobjects.h"
#include <iostream>
#include <raylib.h>

using namespace libengine::core::objects;
using namespace libengine::core::scene;
int main(void) {
  auto mainscene = Scene(60);
  mainscene.add_object(ObjectType::CUBE);
  mainscene.add_object(ObjectType::CUBE, {{4, 0, 0}, {2, 2, 2}, RED, BLUE});
  InitWindow(1920, 1080, "Game");
  mainscene.start();
  return 0;
}
