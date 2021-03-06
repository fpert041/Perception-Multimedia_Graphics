#pragma once

#include "ofMain.h"
#include "Sphere.hpp"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
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
    
    
    Sphere s1;
    Sphere s2 = Sphere(1.8, 2, 0.7);
    
    ofCamera cam;
    
    std::vector<ofVec3f> points;
    
};
