#pragma once

#include "ofMain.h"
#include "Starfield.hpp"
#include "Primitives.hpp"

class ofApp : public ofBaseApp{
private:
    Starfield field; // this creates a starfield object
    Primitives tetra = Primitives(TETRA);
    Primitives cube = Primitives(HEXA);

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
};

