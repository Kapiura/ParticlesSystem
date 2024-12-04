#pragma once

#include "ofxGui.h"

#ifndef MENU_HPP
#define MENU_HPP

class Menu {
public:
  Menu();

  void draw();

  ofxFloatSlider radius;
  ofxColorSlider color;
  ofxVec3Slider lightPos;
  ofxIntSlider lifeTime;
  ofxIntSlider windStr;
  ofxButton addWindButton;
  ofxButton removeWindButton;
  ofxPanel gui;
};

#endif // MENU_HPP