#include "ofApp.h"

// This example uses pure openGL (mostly) to create a procedural sphere

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    
    
    
    //We are using ofCamera, which sets up a projection matrix like the ones we have built by hand.
    //Here we can set the clipping planes
    //And also the camera position
    //If we wanted we could adjust the FOV and a bunch of other stuff
    
    
    cam.setNearClip(1);
    cam.setFarClip(-100);
    cam.setPosition(0,0,10);

    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    
    ofSetLineWidth(1);

    // cam gives us proper openGL world coordinates, like proper openGL
    cam.begin();

    // We're rotating using OF, because OFs projection matrix is a bit screwy if we use the native openGL method.
    
    ofPushMatrix();
    
        ofRotateY(ofGetElapsedTimeMillis()/40);
        ofRotateX(45);
        ofSetColor(220, 0, 0);
        s1.draw();
    
        ofPushMatrix();
            ofRotateX(90);
            ofSetColor(220, 175, 0);
            ofTranslate(0., 0., -3.7);
            s2.draw();
        ofPopMatrix();
    
        ofPopMatrix();

    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    s1.resetSquash();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float wx = (float)x/ofGetWidth() * 16. - 8.;
    s2.updateSquash(wx);
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
