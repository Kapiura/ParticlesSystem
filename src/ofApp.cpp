#include "ofApp.h"

void ofApp::exit() {
  delete emitter;
  delete menu;
  removeLastForceButton.removeListener(
      this, &ofApp::removeLastForceButtonKlikenMachen);
  addWindButton.removeListener(this, &ofApp::addWindButtonKlikenMachen);
}

void ofApp::addWindButtonKlikenMachen() {
  if (!windEnabled) {
    emitter->addForce(
        new WindForce(glm::vec3(1.0f, 0.0f, 0.0f), menu->windStr));
    windEnabled = true;
  }
}

void ofApp::removeLastForceButtonKlikenMachen() {
  if (emitter->deleteLastForce())
    windEnabled = false;
}

//--------------------------------------------------------------
void ofApp::setup() {
  emitter = new Emitter(glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, 0));
  menu = new Menu();
  glm::vec3 initialPos = menu->lightPos;
  light.setPosition(initialPos.x, initialPos.y, initialPos.z);
  light.enable();
  addWindButton.addListener(this, &ofApp::addWindButtonKlikenMachen);
  removeLastForceButton.addListener(this,
                                    &ofApp::removeLastForceButtonKlikenMachen);
  menu->gui.add(addWindButton.setup("Add Wind"));
  menu->gui.add(removeLastForceButton.setup("Remove last Force"));
  cam.setTarget(center);
  cam.enableMouseInput();
  cam.setDistance(500);
  sphereCenter = glm::vec3(ofGetWidth() / 2 + 5.0f, ofGetHeight() / 2, 0);
  sphereRadius = 20.0f;
}

//--------------------------------------------------------------
void ofApp::update() {
  float deltaTime = ofGetLastFrameTime();
  emitter->update(deltaTime, menu->lifeTime, sphereCenter, sphereRadius);
  glm::vec3 lightPos = menu->lightPos;
  light.setPosition(lightPos.x, lightPos.y, lightPos.z);
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(ofColor::gray);
  cam.begin();
  ofEnableDepthTest();
  ofEnableLighting();
  light.enable();
  emitter->draw(menu->radius, menu->color);
  drawSphere();
  light.disable();
  cam.end();
  ofDisableDepthTest();
  ofDisableLighting();
  menu->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------

//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

void ofApp::mousePressed(int x, int y, int button) {
  if (button == 2) {
    isRotating = true;
    cam.disableMouseInput();
  }
}

void ofApp::mouseReleased(int x, int y, int button) {
  if (button == 2) {
    isRotating = false;
    cam.enableMouseInput();
  }
}

void ofApp::mouseDragged(int x, int y, int button) {
  if (isRotating && button == 2) {
    float dx = ofGetPreviousMouseX() - x;
    float dy = ofGetPreviousMouseY() - y;

    cam.orbit(cam.getOrientationEuler().y + dx,
              cam.getOrientationEuler().x + dy, cam.getDistance(), center);
  }
}


void ofApp::drawSphere() const {
    ofSetColor(ofColor::blue);
    ofDrawSphere(sphereCenter, sphereRadius);
}
