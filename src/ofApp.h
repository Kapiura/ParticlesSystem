#pragma once

#include "Emitter.hpp"
#include "Menu.hpp"
#include "Particle.hpp"
#include "Camera.hpp"
#include "WindForce.hpp"
#include "ofMain.h"
#include "ofxGui.h"
#include <vector>

class ofApp : public ofBaseApp
{

  public:
	void setup ();
	void update ();
	void draw ();
	void exit ();

	void keyPressed (int key);
	void keyReleased (int key);
	void mouseMoved (int x, int y);
	void mouseDragged (int x, int y, int button);
	void mousePressed (int x, int y, int button);
	void mouseReleased (int x, int y, int button);
	void mouseEntered (int x, int y);
	void mouseExited (int x, int y);
	void windowResized (int w, int h);
	void dragEvent (ofDragInfo dragInfo);
	void gotMessage (ofMessage msg);
	void addWindButtonKlikenMachen ();
	void removeLastForceButtonKlikenMachen ();
	void drawSphere () const;
	void drawStar(float x, float y, float z, float radius1, float radius2, int nPoints) const;
	void drawCone(float x, float y, float radius, float height, float rotation) const;
	void drawCylinder() const;

  private:
	std::vector<Particle> particles;

	Emitter *emitter;
	Emitter *emitterBoom;
	Emitter *emitterBoom2;
	// Menu *menu;
	Camera* camera;

	ofLight light;
	ofImage backgroundImage;
	// ofxButton addWindButton;
	// ofxButton removeLastForceButton;

	bool isRotating = false;
	bool windEnabled = false;

	float sphereRadius;

	glm::vec3 center = glm::vec3 (ofGetWidth () / 2, ofGetHeight () / 2, 0);
	glm::vec3 sphereCenter;
};
