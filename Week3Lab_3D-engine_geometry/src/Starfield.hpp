//
//  Starfield.hpp
//  Week3Lab_3D-engine_geometry
//
//  Created by Francesco Perticarari on 02/02/2017.
//
//

#ifndef Starfield_hpp
#define Starfield_hpp

#include <stdio.h>
#include "ofMain.h"

class Starfield {
public:
    Starfield();
    void draw();
    
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
};

#endif /* Starfield_hpp */
