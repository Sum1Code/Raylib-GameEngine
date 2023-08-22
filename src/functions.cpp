
#include "functions.hpp"
#include "scene.hpp"

void handle_inputs(int &camspeed, libengine::Scene &currscene) {
  auto camera = currscene.cam;
  if (IsKeyDown(KEY_EQUAL)) {
    camspeed += 200;
  }
  if (IsKeyDown(KEY_MINUS)) {
    camspeed -= 200;
  }
  float wheel = GetMouseWheelMove();
  const float increment = 1.0f;
  if (wheel != 0) {
    currscene.cam.fovy += (wheel * increment);
    if (currscene.cam.fovy < increment)
      currscene.cam.fovy = increment;
  }

  float deltaTime = GetFrameTime();

  // Update camera position based on input and deltaTime
  camera.position.x +=
      camspeed * deltaTime * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
  camera.position.y +=
      camspeed * deltaTime * (IsKeyDown(KEY_E) - IsKeyDown(KEY_Q));
  camera.position.z +=
      camspeed * deltaTime * (IsKeyDown(KEY_S) - IsKeyDown(KEY_W));
}
