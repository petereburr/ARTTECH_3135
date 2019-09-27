#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		//position
		float x = 0;
		float y = 0;
		float x1 = 0;
		float y1 = 0;

		//angle
		float nx = 0.1;
		float ny = 0.1;
		//angular velocity
		float vx = 0.1;
		float vy = 0.1;

		// Define a variable for timing (strobe)
		float lastTimeSwapped = 0;
		// Define a variable for keeping track of color (strobe)
		bool colorOneOn = true;
	
};

