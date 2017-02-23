#include "ofApp.h"

ofEasyCam myCam;

vector<ofVec3f> skypoints;
ofImage skytexture;
ofMaterial skymat;

ofBoxPrimitive skybox;
long skyBoxSize = pow(10, 3.5);

// http://openframeworks.cc/documentation/gl/ofVbo/
/*  Vertex Buffer Object (VBO) provides a way for you to create vertices, normals, colors, and texture coordinates on the graphics card for non-immediate mode rendering. This means that you can store it all on the graphics card and then access, update, or draw it, whenever you need
 
 Just like with ofMesh, you need to keep track of the vertices and their indices in order to make shapes and you can draw a VBO in any one of the OpenGL drawing modes, GL_LINE_STRIP, GL_POINTS, GL_QUADS, GL_TRIANGLES and GL_TRIANGLE_STRIP.
 */
ofPlanePrimitive plane;
ofVboMesh deformedPlane; // ofVboMesh extends ofMesh: a mesh represents a set of vertices in 3D spaces, and normals at those points, colors at those points, and texture coordinates at those points. Each of these different properties is stored in a vector


//--------------------------------------------------------------
void ofApp::setup(){
    
    myCam.rotate(45, 1, 0, 0); // initial orientation of the camera => param: angle / axis xyz
    
    ofEnableDepthTest(); // turns on depth testing so rendering happens according to z-depth rather than draw order.
    ofBackground(0);
    
    
    // ---------------------------------
    // setup SKY BOX
    
    skytexture.load("night_sky_texture.png");
    skytexture.getTexture().setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    skybox.set(skyBoxSize, skyBoxSize, skyBoxSize);
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    skymat.setShininess( 120 );
    // the light highlight of the material //
    skymat.setSpecularColor(ofColor(100, 100, 255, 255));
    
    plane.set(1000, 1000, 100, 100); // => size xy / resolution xy
    plane.rotate(50,1,0,0);
    
    
    // --- generate cube --- SKYBOX -- project momentarily "on hold"
    // This code generates all the vertices we need to make a cube
    for (int i = 0; i < 8 + 1; i++) {
        
        // generate verteces for the cube: hexahedron
            
    }
    // ---------------------------------
    // setup SURFACE
    
    deformedPlane = plane.getMesh();
    deformedPlane.enableColors();
    deformedPlane.enableNormals();
    ofVec3f vertexValue;
    ofVec3f normalVal;
    ofFloatColor col;
    
    int indeces = deformedPlane.getNumIndices();
    
    for (size_t i = 0; i<indeces; ++i){
        
        int vertexIndex = deformedPlane.getIndex(i);
        vertexValue = deformedPlane.getVertex( vertexIndex );
        normalVal.set(ofRandomf(), ofRandomf(),ofRandomf());
        vertexValue.z = ( sin(normalVal.x) + cos(normalVal.y) ) * normalVal.z * 5;
        col.set(normalVal.z/2. + 0.5);
        
        deformedPlane.setVertex( vertexIndex, vertexValue );
        deformedPlane.setNormal( vertexIndex, normalVal );
        deformedPlane.addColor( col );
    }
    
    for (size_t i = 0; i<indeces; i+=4){
        int vertexIndex = deformedPlane.getIndex(i);
        vertexValue = deformedPlane.getVertex( vertexIndex );
        vertexValue.z +=  ofRandomf()*10;
        deformedPlane.setVertex( vertexIndex, vertexValue );
    }
    
    
    
    // ---------------------------------
    
    
    // -- lights --
    // This turns on the lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // This generates a bunch of arrays that we can pass in as lighting parameters
    GLfloat ambientLight[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
    GLfloat specularLight[] = { 0.15f, 0.15f, 0.15f, 1.0f };
    //    GLfloat position[] = { -1.5f, 1.0f, -4.0f, 1.0f };
    
    // These fuctions define the characteristics of our light, GL_LIGHT0 - remember there are 8 lights
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    //    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    // This turns on color tracking. Might be on by default in openFrameworks
    glEnable(GL_COLOR_MATERIAL);
    // This sets the material properties. Important for lighting.
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
    //Again, I think this is the default mode in OF. But if you aren't using OF you need to do this manually
    
    glShadeModel(GL_SMOOTH); // Can also be flat. When flat, the last colour specified for a triangle is the colour of the triangle

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    myCam.begin();
    
        skytexture.getTexture().bind();
        skybox.mapTexCoords(0, 0, skytexture.getWidth(), skytexture.getHeight());
    
        ofPushMatrix();
            skybox.draw();
            skytexture.getTexture().unbind();
    
            deformedPlane.draw();
        ofPopMatrix();
    
    myCam.end();

}

//--------------------------------------------------------------
ofVec3f ofApp::getNormal(std::vector<ofVec3f> tri) {
    
    //Each face in the geometry needs to have a normal vector perpendicular to the face.
    //This is computed by getting the cross product of two points along the surface, a and b.
    
    ofVec3f a, b, normal;
    
    // We need to work out what a and b are
    // using CCW
    
    // a
    a.x = tri[0].x - tri[1].x;
    a.y = tri[0].y - tri[1].y;
    a.z = tri[0].z - tri[1].z;
    
    // b
    b.x = tri[1].x - tri[2].x;
    b.y = tri[1].y - tri[2].y;
    b.z = tri[1].z - tri[2].z;
    
    // This next bit of code does the cross product
    normal.x = (a.y * b.z) - (a.z * b.y);
    normal.y = (a.z * b.x) - (a.x * b.z);
    normal.z = (a.x * b.y) - (a.y * b.x);
    
    // now we have to normalise - this is basically the same as getting a unit vector.
    // we divide each element of the vector by its magnitude.
    // we should do it by hand but to save time I'm just calling a built in function
    
    return normal.normalize();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
