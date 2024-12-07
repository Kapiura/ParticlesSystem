#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup ()
{
	emitter = new Emitter (glm::vec3 (0,  0, 0));
	emitterBoom = new Emitter (glm::vec3 (100,  200, 0));
	emitterBoom2 = new Emitter (glm::vec3 (ofGetWidth()-100,  200, 0));

    glm::vec3 initialPos = ofVec3f(ofGetWidth() , ofGetHeight() * 0.5, 500);
    light.setPosition(initialPos.x, initialPos.y, initialPos.z);
    light.setDiffuseColor(ofColor(255, 255, 255));
    light.setSpecularColor(ofColor(255, 255, 255));
    light.enable();
	backgroundImage.load("background.jpg");
	sphereCenter = glm::vec3 (ofGetWidth () / 2 + 5.0f, ofGetHeight () / 2, 0);
	sphereRadius = 20.0f;
}

//--------------------------------------------------------------
void ofApp::exit ()
{
	delete emitter;
	delete emitterBoom;
	delete emitterBoom2;
}


//--------------------------------------------------------------
void ofApp::removeLastForceButtonKlikenMachen ()
{
	if (emitter->deleteLastForce ())
		windEnabled = false;
}

//--------------------------------------------------------------
void ofApp::update ()
{
	float deltaTime = ofGetLastFrameTime ();
	emitter->update (deltaTime, 2.0f);
	emitterBoom->updateBoom(deltaTime);
	emitterBoom2->updateBoom(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw () {
    backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());

    ofEnableDepthTest();
    ofEnableLighting();
    light.enable();

    drawStar(100, 100, 0, 25, 50, 5);
    drawStar(225, 153, 0, 25, 50, 5);
    drawStar(350, 123, 0, 25, 50, 5);
    drawStar(475, 98, 0, 25, 50, 5);
    drawStar(600, 87, 0, 25, 50, 5);
    drawStar(725, 122, 0, 25, 50, 5);
    drawStar(850, 145, 0, 25, 50, 5);
    drawStar(975, 113, 0, 25, 50, 5);
    drawStar(1100, 150, 0, 25, 50, 5);
    drawStar(1225, 90, 0, 25, 50, 5);

    drawCone(ofGetWidth() / 2, ofGetHeight() - 300, 175, 100, 0);
    drawCone(ofGetWidth() / 2, ofGetHeight() - 250, 200, 100, 0);
    drawCone(ofGetWidth() / 2, ofGetHeight() - 200, 225, 100, 0);

	drawCylinder();

    emitterBoom->draw(2.0f, ofColor::yellow);
    emitterBoom2->draw(2.0f, ofColor::yellow);
    emitter->draw(2.0f, ofColor::white);

    light.disable();
    ofDisableDepthTest();
    ofDisableLighting();
}


//--------------------------------------------------------------
void ofApp::mousePressed (int x, int y, int button)
{
	if (button == 2)
	{
		isRotating = true;
		// camera->disableMouseInput ();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased (int x, int y, int button)
{
	if (button == 2)
	{
		isRotating = false;
		// camera->enableMouseInput();
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged (int x, int y, int button)
{
	if (isRotating && button == 2)
	{
		float dx = ofGetPreviousMouseX () - x;
		float dy = ofGetPreviousMouseY () - y;

		// camera->orbit(dx, dy, center);
	}
}

//--------------------------------------------------------------
void ofApp::drawSphere () const
{
	ofSetColor (ofColor::blue);
	ofDrawSphere (sphereCenter, sphereRadius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

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

void ofApp::drawStar(float x, float y, float z, float radius1, float radius2, int nPoints) const{
    ofPath star;
    float angleStep = TWO_PI / nPoints;
    float halfStep = angleStep / 2.0;

    for (int i = 0; i < nPoints; i++) {
        float outerX = cos(i * angleStep) * radius1;
        float outerY = sin(i * angleStep) * radius1;
        float innerX = cos(i * angleStep + halfStep) * radius2;
        float innerY = sin(i * angleStep + halfStep) * radius2;

        if (i == 0) {
            star.moveTo({outerX, outerY, 0});
        } else {
            star.lineTo({outerX, outerY, 0});
        }

        star.lineTo({innerX, innerY, 0});
    }

    star.close();
    star.setFillColor(ofColor::yellow);

    ofPushMatrix();
    ofTranslate(x, y, z);
    star.draw();
    ofPopMatrix();
}

void ofApp::drawCone(float x, float y, float radius, float height, float rotation) const {
    ofPushMatrix();

    ofTranslate(x, y);

    ofRotateDeg(rotation);

    ofMaterial material;
    material.setDiffuseColor(ofColor(0, 255, 0));
    material.begin();

    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    glm::vec3 tip(0, -height / 2, 0);

    int numSides = 30;
    float angleStep = TWO_PI / numSides;
    for (int i = 0; i < numSides; i++) {
        float angle = i * angleStep;
        glm::vec3 baseVertex(cos(angle) * radius, height / 2, sin(angle) * radius);

        glm::vec3 nextBaseVertex(cos((i + 1) * angleStep) * radius, height / 2, sin((i + 1) * angleStep) * radius);

        mesh.addVertex(tip);
        mesh.addVertex(baseVertex);
        mesh.addVertex(nextBaseVertex);
    }

    mesh.draw();

    material.end();

    ofPopMatrix();
}




void ofApp::drawCylinder() const
{
    ofPushMatrix();

    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

    ofMaterial material;
    material.setDiffuseColor(ofColor(139, 69, 19));
    material.begin();

    ofDrawCylinder(0, 300, 50, 200);

    material.end();

    ofPopMatrix();
}