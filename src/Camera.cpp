#include "Camera.hpp"

Camera::Camera (glm::vec3 center)
{
	cam.setTarget (center);
	cam.enableMouseInput ();
	cam.setDistance (1000);

}

void Camera::orbit (float& dx, float& dy, glm::vec3& center)
{
	cam.orbitRad (cam.getOrientationEulerRad().y + dx,
        cam.getOrientationEulerRad().x + dy,
        cam.getDistance (), center);
}