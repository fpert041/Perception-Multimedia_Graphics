//
//  Sphere.hpp
//  proceduralSphere
//
//  Created by Francesco Perticarari on 08/02/2017.
//
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include "ofMain.h"

class Sphere {
public:
    Sphere();
    Sphere(float);
    Sphere(float, float);
    Sphere(float, float, float);
    
    void draw();
    void draw(float, float, float); //draw a translated sphere
    
    void updateSquash(float);
    void resetSquash();
    
    
    int dim;
    float spacing;
    float size;
    float divide;
    float squashiness;
    
    ofCamera cam;
    
    std::vector<ofVec3f> points;
    
private:
    void setup(float, float, float);
};

#endif /* Sphere_hpp */
