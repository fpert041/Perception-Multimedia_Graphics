//
//  Actor.hpp
//  Week3Lab_3D-engine_geometry
//
//  Created by Francesco Perticarari on 02/02/2017.
//
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>
#include "ofMain.h"

// BASE CLASS FOR DRAWING 3D OBJECTS ON SCREEN

class Actor {
    
protected:
    int fov = 200; // field of view
    
    double x3d = 0;
    double y3d = 0;
    double z3d = 0;
    int HALF_WIDTH = ofGetWidth()/2;
    int HALF_HEIGHT = ofGetHeight()/2;
    
    int numVerteces;

    
public:
    
    virtual void draw();
    
    std::array<double, 3> point;  // point as a set of 3D coordinates
    std::vector<std::array<double, 3>> verteces; // container for verteces stored as 3D coordinates in std::arrays
    
};

#endif /* Actor_hpp */
