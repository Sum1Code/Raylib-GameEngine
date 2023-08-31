
#include "functions.h"
#include "core.h"
void handle_inputs(int &fps, libengine::core::scene::Scene &currscene) {

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
    currscene.cam.cam.fovy += (wheel * fovIncrement);
    // Constrain FOV within limits
    if (currscene.cam.cam.fovy < minFOV)
      currscene.cam.cam.fovy = minFOV;
    else if (currscene.cam.cam.fovy > maxFOV)
      currscene.cam.cam.fovy = maxFOV;
  }

  // Calculate camera movement direction based on user input
}
