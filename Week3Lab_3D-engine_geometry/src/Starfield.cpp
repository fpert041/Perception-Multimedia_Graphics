//
//  Starfield.cpp
//  Week3Lab_3D-engine_geometry
//
//  Created by Francesco Perticarari on 02/02/2017.
//
//

#include "Starfield.hpp"


Starfield::Starfield(){
    
    // Initialise variables
    numVerteces = 1000;
    
    // Fill container for stars with sets of random 3D coordinates
    verteces.clear();
    for (int i = 0; i < numVerteces; ++i) {
        point = { (ofRandom(0.,1.) * ofGetWidth()/2) - ofGetWidth()/4, (ofRandom(0.,1.) * ofGetHeight()/2) - ofGetHeight()/4, (ofRandom(0.,1.) * ofGetWidth()/2) - ofGetWidth()/4 };
        
        verteces.push_back(point);
        
    }
}

void Starfield::draw(){
    
    // This loop takes a bunch of 3D vertices and draws them using a 2D perspective projection
    for(int i =0; i<numVerteces; ++i){
        
        // Get a vertex
        std::array<double, 3> &point3d = verteces[i];
        
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
        
        // ofDrawRectangle(x2d, y2d, scale, scale); // alternative to line (does not require "setLineWidth")
    }
    
    
    
}
