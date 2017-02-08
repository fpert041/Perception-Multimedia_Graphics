#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

float z=0,zx=0,zy=0;//So these are variables that hold the absolute value of z, and the x and y coordinates that we use to represent z
float cx=0,cy=0;//These are variables we use to represent the complex number c - which is a pixel location.
float maxIterations=50;//We calculate the fractal by running a test over and over again for each pixel. The size of this number is the maximum number of tests
int res=2; // resolution (in pixels definition, so the higher the number the lower the resolution)

ofColor c;
bool bob = true;

float x,y;
int col;

float zoom = 1;

float xOffset, yOffset = 0;

//--------------------------------------------------------------
void ofApp::draw(){
    // OK so this is a very very simple program that calculates the Mandelbrot set - which is probably the worlds most famous fractal.
    // I'll explain every bit of it as simply as I can.
    // The equation is famously quoted as z=z^2+c, but this is actually
    // not that useful unless you understand the process.
    // Basically, the set is calculated by running a test based on pixel locations, over and over again.
    // For each pixel we run the test by taking the previous test output and sticking it back in the input.
    // We have a maximum number of tests we run for each pixel. If the output goes over a certain value (2),
    // Then the pixel is outside the set. If not, it's inside the set.
    // There are a number of ways of calculating z^2, but here we're going to use
    // a method that might look strange at first.
    // In this case the "complex number" is a pixel location,
    // where the values can be positive or negative.
    // So we use
    // z^2=(zx^2-zy^2,2*zx*zy)
    
    
    
    //More detail below...
        ofTranslate(ofGetWidth()*0.5,ofGetHeight()*0.5);//As always with proper stuff, we translate so that 0,0 is in the middle
        //We are going to test every single pixel on the screen, so we need nested for loops.
        for (int i=-(ofGetWidth()/2);i<ofGetWidth()/2;i+=res) {//for every pixel in the x dimension (columns)...
            for (int j=-(ofGetHeight()/2);j<ofGetHeight()/2;j+=res) {//...run through all the y pixels
                cx= (float)i*4 / (ofGetWidth()*zoom) + xOffset;//adjust the values of x so that it is between -2 and 2, as this is where the mandelbrot is!!
                cy= (float)j*4 / (ofGetHeight()*zoom) + yOffset;//same for y. These two lines have given us the complex number c, which is just (cx,cy)
                for (int test=0;test<maxIterations;test++) {//now we run the test as many times as we want. the more we run it the longer it takes
                    if (z<2.0) {//so only run the test if the square of the absolute value of z is less than 2.0 - that's what gives the Mandelbrot its shape.
                        // So this bit is the actual test. We're going to start by calculating z^2 - the first time we do this it will be 0. Then we add c, then we test again etc...
                        // the way we calculate z^2 is as follows :
                        // z^2=(zx^2-zy^2,2*zx*zy)
                        // so in other words we begin by getting zx=(zx*zx)-(zy*zy) and zy=(2*zx*zy).
                        // We're storing them in some temp values (x,y) - this slows things down but it's just to be clear what's going on.
                        x=(zx*zx)-(zy*zy);// this is z(x)
                        y=2.*(zx*zy);//this is z(y)
                        zx=x+cx;//then we add cx to x to get the next value of zx
                        zy=y+cy;//and then add cy to y to get the next value of zy
                        z=sqrt((zx*zx)+(zy*zy));//Now we get the square of the absolute value of z so that we can see if it's over 2 the next time we run the test. If it is, we don't do anything
                        // std::cout << test << " " << z << std::endl;

                        col = (255/(float)maxIterations * test);
                        // col = 255;
                        // std::cout << col << std::endl;
                        c = ofColor(col, 255-col, col/2);//the colour we use depends on how many tests we had to do before the value of z got bigger than 2.
                        ofSetColor(c);
                    }//The cool thing is that theoretically, all the pixel positions inside the set will never have an absolute value greater than 2.0.
                }
                z=0;//before we run the next test we need to clear the variables we're using.
                zx=0;
                zy=0;
                    // std::cout << "test" << std::endl;
                ofDrawRectangle(i,j,res,res);
            }
        }
        //and that's how you calculate the Mandelbrot set
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // std::cout << key << std::endl;
    
    /* UP, DOWN, LEFT, RIGHT - on a mac 2011 - it may need to be changed on other machines */
    if (key == 357){
        yOffset -= 0.1/zoom;
    } else if (key == 359) {
        yOffset += 0.1/zoom;
    } else if (key == 358) {
        xOffset += 0.1/zoom;
    } else if (key == 356) {
        xOffset -= 0.1/zoom;
    }
    
    /* - / = (buttons also indicaed with plus, minus) - on a mac 2011
     I DID NOT USE SHIFT, CMD or OPTION - it may still need to be changed on other machines */
    
    if (key == 61){
        zoom += 1;
    } else if (key == 45) {
        zoom -= 1;
    }

    /* < / > (buttons also indicaed with , and . ) - on a mac 2011
     I DID NOT USE SHIFT, CMD or OPTION - it may still need to be changed on other machines */
    
    if (key == 44){
        zoom *= 0.5;
    } else if (key == 46) {
        zoom *= 2;
    }
    
    
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
    // zoomX =
    // zoomY =
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
