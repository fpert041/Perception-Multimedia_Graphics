//
//  Primitives.hpp
//  Week3Lab_3D-engine_geometry
//
//  Created by Francesco Perticarari on 02/02/2017.
//
//

#ifndef Primitives_hpp
#define Primitives_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Actor.hpp"


class Primitives : public Actor{
public:
    enum {TETRA=0};
public:
    Primitives(int);
    
    void draw();
    
};

#endif /* Primitives_hpp */
