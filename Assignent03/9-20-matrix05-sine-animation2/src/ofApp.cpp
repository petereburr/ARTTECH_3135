#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(24);

	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;
	x1 = ofGetWidth() / 2;
	y1 = ofGetHeight() / 2;

	vx = 0.1;
	vy = 0.1;

	nx = ofRandom(100);
	ny = ofRandom(100);

	ofSetBackgroundColor(255, 0, 0);
	//ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	//strobe logic
	if (ofGetElapsedTimef() - lastTimeSwapped > 0) {
		colorOneOn = !colorOneOn;
		lastTimeSwapped = ofGetElapsedTimef();
	}

	//randomness
	nx += vx;
	ny += vy;

	x = x + 10 * ofSignedNoise(nx);
	y = y + 10 * ofSignedNoise(ny);
	x1 = x1 + 10 * ofSignedNoise(nx)*-1;
	y1 = y1 + 10 * ofSignedNoise(ny);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//face
		ofSetColor(255, 200, 0);
		ofSetCircleResolution(64);
		ofFill();
		ofDrawCircle(x, y, 350);
		ofDrawCircle(x1, y1, 350);
	//hat
		ofNoFill();
		ofSetColor(0);
		ofDrawLine(10, 60, 780, 60);
	//monocle
		ofFill();
		if (colorOneOn) {
			ofSetColor(255);
		}
		else {
			ofSetColor(0);
		}
		ofDrawRectangle(100, 100, 300, 300);
		
		//top mask
		ofSetColor(255, 0, 0);
		ofDrawRectangle(0, 0, 800, 55);
		
	//monocle rim	
		ofNoFill();
		ofSetLineWidth(1);
		if (colorOneOn) {
			ofSetColor(0);
		}
		else {
			ofSetColor(255);
		}
		ofDrawRectangle(100, 100, 300, 300);


	//left eye
	ofPushMatrix();
		ofNoFill();
		ofTranslate(-200, -200);
		ofSetCircleResolution(4);
		ofSetColor(0);
		ofDrawCircle(x, y, 50);
		ofSetColor(0, 0, 255);
		ofDrawCircle(x, y, 50);
	ofPopMatrix();

	//right eye
	ofPushMatrix();
		ofTranslate(200, -200);
		ofSetColor(0, 0, 255);
		ofFill();
		ofDrawCircle(x1, y1, 50);
	ofPopMatrix();

	//mouth
	ofPushMatrix();
	ofTranslate(0, 100);
	ofRotateDeg(ofSignedNoise(nx));
	ofSetColor(255,0,0);
	ofSetLineWidth(x);
	ofDrawLine(200, 500, 600, 500);
	ofPopMatrix();

	//nose
	ofSetColor(0);
	ofSetCircleResolution(64);
	ofFill();
	ofDrawCircle(400, 400, 100);

}

