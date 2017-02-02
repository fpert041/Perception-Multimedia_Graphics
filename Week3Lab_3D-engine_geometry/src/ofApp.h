#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
private:
    std::array<double, 3> point;  // point as a set of 3D coordinates
    std::vector<std::array<double, 3>> points; // container for stars stored as a 3D vector
    
    int fov = 200; // field of view
    
    int HALF_WIDTH;
    int HALF_HEIGHT;
    
    int numPoints = 1000;
    double x3d;
    double y3d;
    double z3d;

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

