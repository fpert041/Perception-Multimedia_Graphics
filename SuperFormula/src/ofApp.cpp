#include "ofApp.h"

float magnify; // This is how big we want the rose to be.
float rotation ; // rotation : this is basically how far round the circle we are going to go
float radius ; // radius : this is basically how far from the origin we are.
int elements;// This is the number of points and lines we will calculate at once. 1000 is alot actually.

float x;



//--------------------------------------------------------------
void ofApp::setup(){
    //    point(sin(spacing*amp*i)*(cos(spacing*i*phase)*magnify),sin(spacing*phase*i)*(sin(spacing*i*amp)*magnify));
    
    
    
     magnify = 300; // This is how big we want the rose to be.
     rotation = 0; // rotation : this is basically how far round the circle we are going to go
     radius = 3000; // radius : this is basically how far from the origin we are.
     elements = 100;// This is the number of points and lines we will calculate at once. 1000 is alot actually.
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
        ofBackground(0);
    
    x+=0.001;
    float spacing = TWO_PI/elements; // this is how far apart each 'node' will be - study it.
    ofTranslate(ofGetWidth()/4,ofGetHeight()/2);// we translate the whole sketch to the centre of the screen, so 0,0 is in the middle.
    
    float rotation = 0;
    for(int i=0; i<elements; i++){
        ofColor c = ofColor(100,i*2,50);
        ofSetColor(c);
        
        rotation+=0.005*PI;
        ofRotate(spacing*i*rotation);
        ofDrawEllipse(i*2,i*2, i*10, i*10);
        ofTranslate(sin(spacing*i*radius)*magnify,0);
        
    }
    
    float Param1 =4+x;
    float Param2 = 1+x;

    ofNoFill();
    ofSetLineWidth(2);
    for (int i = 2; i < elements;i++) {
        ofColor c = ofColor(i*2,200,255);
        ofSetColor(c);
        ofDrawEllipse(sin(spacing*i*Param1)*cos(spacing*i*Param2)*magnify,sin(spacing*Param1*i)*(sin(spacing*i*Param2)*magnify),10,10);
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
