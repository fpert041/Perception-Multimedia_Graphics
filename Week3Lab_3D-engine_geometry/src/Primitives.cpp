//
//  Primitives.cpp
//  Week3Lab_3D-engine_geometry
//
//  Created by Francesco Perticarari on 02/02/2017.
//
//

#include "Primitives.hpp"


// x = r*sin(θ)cos(φ), y = r*sin(θ)sin(φ), and z = r*cos(θ)
// where θ is the polar angle (elevation) and φ the azimuthal angle (horizontal direction)
// if r=1, then we just need to determine the angles (theta and phi)

// Euler's relation btw states that: Verteces-Edges+Faces=2

/*
                F   V   E
 
 Tetrahedron	4	4	6  >
 Cube           6	8	12 \
 Octahedron     8	6	12 /
 Dodecahedron	12	20	30 \
 Icosahedron	20	12	30 /
*/

Primitives::Primitives(int t){
    // Initialise variables
    x3d = 0;
    y3d = 0;
    z3d = 0;
    
    float θ = 1/2*PI;
    float φ = 1/3*PI;

    HALF_WIDTH = ofGetWidth()/2;
    HALF_HEIGHT = ofGetHeight()/2;
    
    switch(t){
        case TETRA:
            numVerteces = 4;

            for (int i = 0; i < numVerteces; ++i) {
                point = { sin(θ)*cos(φ), sin(θ)*sin(φ), cos(θ)};
                
                verteces.push_back(point);
            }
            break;
        
        // other cases...
    }
}

void Primitives::draw(){
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
