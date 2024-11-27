#include "ofApp.h"
#include <memory>

//--------------------------------------------------------------
void ofApp::setup()
{
  ofBackground(0);
  ofEnableDepthTest();
  ofEnableLighting();

  emitter = std::make_unique<Emitter>(glm::vec3(400, 300, 0), 5);
}

//--------------------------------------------------------------
void ofApp::update()
{
    emitter->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    emitter->draw();
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
