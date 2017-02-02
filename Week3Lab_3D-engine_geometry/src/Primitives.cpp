//
//  Primitives.cpp
//  Week3Lab_3D-engine_geometry
//
//  Created by Francesco Perticarari on 02/02/2017.
//
//

#include "Primitives.hpp"


Primitives::Primitives(int t){
    // Initialise variables
    x3d = 0;
    y3d = 0;
    z3d = 0;

    HALF_WIDTH = ofGetWidth()/2;
    HALF_HEIGHT = ofGetHeight()/2;
    
    switch(t){
        case TETRA:
            numVerteces = 4;
            // Fill container for stars with sets of random 3D coordinates
            for (int i = 0; i < numVerteces; ++i) {
                point = { (ofRandom(0.,1.) * ofGetWidth()/2) - ofGetWidth()/4, (ofRandom(0.,1.) * ofGetHeight()/2) - ofGetHeight()/4, (ofRandom(0.,1.) * ofGetWidth()/2) - ofGetWidth()/4 };
                
                verteces.push_back(point);
            }
            break;
        
        // other cases...
    }

}
