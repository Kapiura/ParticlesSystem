#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofBackground(0);
  ofEnableDepthTest();
  ofEnableLighting();

  emitter = new Emitter(glm::vec3(ofGetWidth()/ 2, ofGetHeight()/2, 0));
    // glm::vec3(0, 1, 0) * ofRandom(50, 100));


  // for (int i = 0; i < 1000; i++)
  //   particles.push_back({
  //   glm::vec3(ofGetWidth()/ 2, ofGetHeight()/2, 0), // vec pos
  //   glm::vec3(0, 1, 0) * ofRandom(50, 100),         // vec velocity
  //   ofColor::white,                                 // color
  //   ofRandom(1, 5),                                 // life time
  //   ofRandom(1,10)});                               // particle radius
}

//--------------------------------------------------------------
void ofApp::update()
{
  float deltaTime = ofGetLastFrameTime();
  emitter->update(deltaTime);

    // for (auto& el: particles)
    //   el.update(deltaTime);

    // particles.erase(std::remove_if(
    //   particles.begin(),
    //   particles.end(),
    //   [](Particle& p) { return p.isDead(); }), particles.end());
}

//--------------------------------------------------------------
void ofApp::draw()
{
  // for (auto& el: particles)
    // el.draw();
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
