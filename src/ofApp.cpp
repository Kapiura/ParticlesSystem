#include "ofApp.h"

ofApp::~ofApp()
{
  delete emitter;
  delete menu;
}

//--------------------------------------------------------------
void ofApp::setup()
{
  ofBackground(ofColor::white);
  ofEnableDepthTest();
  ofEnableLighting();

  emitter = new Emitter(glm::vec3(ofGetWidth()/ 2, ofGetHeight()/2, 0));
      gui.setup();
    gui.add(radius.setup("radius", 140, 10, 300));
  // menu = new Menu();

}

//--------------------------------------------------------------
void ofApp::update()
{
  float deltaTime = ofGetLastFrameTime();
  emitter->update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw()
{
  emitter->draw();
      ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
      gui.draw();
  // menu->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
