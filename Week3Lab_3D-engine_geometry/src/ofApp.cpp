#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    // Initialise variables
    x3d = 0;
    y3d = 0;
    z3d = 0;
    HALF_WIDTH = ofGetWidth()/2;
    HALF_HEIGHT = ofGetHeight()/2;
    
    // Fill container for stars with sets of random 3D coordinates
    for (int i = 0; i < numPoints; ++i) {
         point = { (ofRandom(0.,1.) * ofGetWidth()/2) - ofGetWidth()/4, (ofRandom(0.,1.) * ofGetHeight()/2) - ofGetHeight()/4, (ofRandom(0.,1.) * ofGetWidth()/2) - ofGetWidth()/4 };
        
        points.push_back(point);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0, 0, 0);
    
    // This loop takes a bunch of 3D vertices and draws them using a 2D perspective projection
    for(int i =0; i<numPoints; ++i){
        
        // Get a vertex
        std::array<double, 3> &point3d = points[i];
        
        // Get the z coordinate - this is the depth
        z3d = point3d[2];
        
        // substract a value - this will move it along the z axis.
        z3d -= .4;
        
        // if the z coordinate for this vertex is less than the Fielf of View (FOV),
        // Add half the width to move it back. This makes an endless starfield.
        // feel free to disable this if you want...
        if(z3d < -fov)
            z3d += HALF_WIDTH;
        
        // replace the original z position with this new z position.
        point3d[2] = z3d;
        
        // Now get all the vertices
        x3d = point3d[0];
        y3d = point3d[1];
        z3d = point3d[2];
        
        // Decide on the size of the point by taking the FOV and dividing it by the FOV + the z pos
        float scale = fov / (fov + z3d);
        
        // Now create the 2D perspective.
        // create a 2D x and y position by multiplying the x and y coordinates by the scale
        // Add half the width and height to translate the coordinates to the origin.
        double x2d = (x3d * scale) + HALF_WIDTH;
        double y2d = (y3d * scale) + HALF_HEIGHT;
        
        // Draw a square of size 'scale', in position x2d, y2d.
        // This code is more complex than you might be used to because it's pure JS.
        ofSetLineWidth(scale);
        ofSetColor(255, 255, 255);
        ofDrawLine(x2d, y2d, x2d+scale, y2d);
        
        // ofDrawRectangle(x2d, y2d, 0, scale, scale); // alternative to line (does not require "setLineWidth")
    }

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
