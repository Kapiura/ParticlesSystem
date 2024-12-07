#pragma once
#include "ofMain.h"

#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera
{
    public:
        Camera(glm::vec3 center);

        void begin() { cam.begin();};
        void end() { cam.end();};
        void enableMouseInput() { cam.enableMouseInput(); };
        void disableMouseInput() { cam.disableMouseInput(); };
        void orbit(float& dx, float& dy, glm::vec3& center);

    private:
	    ofEasyCam cam;
};

#endif