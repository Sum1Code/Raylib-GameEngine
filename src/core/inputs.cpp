#include "core.h"
using namespace libengine::core::scene;

void Scene::handle_inputs() {

  const float minFOV = 1.0f;
  const float maxFOV = 45.0f;
  const float fovIncrement = 1.0f;
  // Adjust camera speed with constraints
  if (IsKeyDown(KEY_LEFT_SHIFT)) {
    fps = 200;
  } else {
    fps = 60;
  }

  if (IsKeyPressed(KEY_LEFT_ALT)) {
    if (IsCursorHidden())
      EnableCursor();
    else
      DisableCursor();
  }

  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    cam.cam.fovy += (wheel * fovIncrement);
    // Constrain FOV within limits
    if (cam.cam.fovy < minFOV)
      cam.cam.fovy = minFOV;
    else if (cam.cam.fovy > maxFOV)
      cam.cam.fovy = maxFOV;
  }
}
