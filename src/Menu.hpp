#pragma once

#include "ofxGui.h"

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
public:
    Menu();

    void draw();

private:
    ofxFloatSlider radius;
    ofxPanel gui;
    // ofxFloatSlider floatSlider;

    // ofxToggle toggle;
    // ofxButton button;
    // ofxLabel label;

    // ofxIntField intField;
    // ofxFloatField floatField;
    // ofxTextField textField;

    // ofxVec2Slider vec2Slider;
    // ofxVec3Slider vec3Slider;
    // ofxVec4Slider vec4Slider;
};


#endif // MENU_HPP