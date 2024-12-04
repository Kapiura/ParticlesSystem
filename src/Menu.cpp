#include "Menu.hpp"
#include "ofMain.h"
#include "ofxGui.h"

Menu::Menu() {
  gui.setup();
  gui.add(radius.setup("Radius", 4, 1, 150));
  gui.add(color.setup("Color", ofColor(100, 100, 140, 20), ofColor(0, 0),
                      ofColor(255, 255)));
  gui.add(lightPos.setup(
      "Light Position", ofVec3f(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 100),
      ofVec3f(0, 0, -500), ofVec3f(ofGetWidth(), ofGetHeight(), 500)));
  gui.add(lifeTime.setup("Life time range", 2, 2, 10));
  gui.add(windStr.setup("Wind strength", 10, -150, 150));
}

void Menu::draw() {
  gui.draw();
  addWindButton.draw();
  removeWindButton.draw();
}