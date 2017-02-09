//
//  Sphere.cpp
//  proceduralSphere
//
//  Created by Francesco Perticarari on 08/02/2017.
//
//

#include "Sphere.hpp"

// This example uses pure openGL (mostly) to create a procedural sphere


Sphere::Sphere(){
    size = 4;
    divide = 1;
    this->squashiness = 1;
    setup(size, divide, squashiness);
}

Sphere::Sphere(float size){
    this->size = size;
    divide = 1;
    this->squashiness = 1;
    setup(size, divide, squashiness);
    
}

Sphere::Sphere(float size, float divide){
    this->size = size;
    this->divide = divide;
    this->squashiness = 1;
    setup(size, divide, squashiness);
}

Sphere::Sphere(float size, float divide, float s){
    this->size = size;
    this->divide = divide;
    this->squashiness = s;
    setup(size, divide, s);
}


//--------------------------------------------------------------
void Sphere::setup(float size, float divide, float squashiness){
    
    ofEnableDepthTest();
    points.clear();
    
    dim=20; // ( number of points for the polygons along each ring ) AND ( number of rings + 1 )
    // e.g. - with dim = 10 the sphere will have 9 rings, each having 10 equally spaced verteces
    spacing = ((PI * 2) / dim);
    
    // This code generates all the vertices we need to make a sphere
    for (int i = 0; i < dim + 1; i++) {
        
        // ******* Calculate the current ring position ********
        
        // To calculate the current ring position, we divide our spacing variable in half
        // This is because otherwise, the cosine / sine waves will
        // generate twice as many numbers as we need (e.g. positive then negative)
        // We only need the first half of the wave
        
        // z is the position of the current ring
        float z = size * cos(spacing / 2. / divide * (float)i);
        
        // This calculates the size of the current ring
        float s = size * sin(spacing / 2. / divide * (float)i);
        
        // For each ring..
        
        for (int j = 0; j < dim ; j++) {
            
            // ...create the next point in the circle at the current size s, at the current depth z
            
            ofVec3f point;
            
            point.set(cos(spacing * (float)j) * s,sin(spacing * (float)j) * s, z * squashiness);
            
            points.push_back(point);
            
        }
    }
    
    //cout << "done ";
    
}

void Sphere::updateSquash(float v){
    this->squashiness = v;
    setup(size, divide, squashiness);
}

void Sphere::resetSquash(){
    setup(size, divide, 1);
}

//--------------------------------------------------------------
void Sphere::draw(){
    

    
    glBegin(GL_LINE_LOOP);
    
    for (int i = dim+1 ; i < points.size()+dim; ++i) {
        
        glVertex3f(points[i].x, points[i].y, points[i].z);      // start from "point" (or connect previous vertex to it)
        
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);        // link to previous point
        
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);      // link to point onto previous ring
        
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);        // link back to previous point
        
        glVertex3f(points[i-dim-1].x, points[i-dim-1].y, points[i-dim-1].z);    // link to previous point on previous ring
        
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);      // link to point on previous link
        
    } // when loop is finished: close line
    
    glEnd();
    
}

//--------------------------------------------------------------
void Sphere::draw(float x, float y, float z){
    
    ofTranslate(x,y,z);
    
    glBegin(GL_LINE_LOOP);
    
    
    for (int i = dim+1 ; i < points.size()+dim; i++) {
        
        
        glVertex3f(points[i].x, points[i].y, points[i].z);
        
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);
        
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);
        
        glVertex3f(points[i-dim-1].x, points[i-dim-1].y, points[i-dim-1].z);
        
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        
    }
    
    glEnd();
    
}



