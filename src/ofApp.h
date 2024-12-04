#pragma once

#include "Emitter.hpp"
#include "Menu.hpp"
#include "Particle.hpp"
#include "WindForce.hpp"
#include "ofMain.h"
#include "ofxGui.h"
#include <vector>

class ofApp : public ofBaseApp {

public:
  void setup();
  void update();
  void draw();
  void exit();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void addWindButtonKlikenMachen();
  void removeLastForceButtonKlikenMachen();
  void drawSphere() const ;


private:
  std::vector<Particle> particles;
  Emitter *emitter;
  Menu *menu;
  ofLight light;
  ofxButton addWindButton;
  ofxButton removeLastForceButton;
  bool windEnabled = false;
  ofEasyCam cam;
  glm::vec3 center = glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, 0);
  bool isRotating = false;
  glm::vec3 sphereCenter;
float sphereRadius;

};
