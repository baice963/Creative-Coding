#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("stars.jpg");
    image.resize(200, 200);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    mesh.enableIndices();

    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x*4, y*4, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }
    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
                // connected to form a line
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    ofSetFrameRate(60);
    
    // Some lines of code omitted for clarity, you should still
    // keep them in your local version
    
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x*4, y*4, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                
                // And add this line to your existing for loop:
                // It will create a ofVec3f with 3 random values, which
                // will allow us to move the x, y and z coordinates of
                // each vertex independently
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 50.0;
//        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];
        
        // A typical design pattern for using Perlin noise uses a couple parameters:
        // ofSignedNoise(time*timeScale+timeOffset)*displacementScale
        //     ofSignedNoise(time) gives us noise values that change smoothly over
        //         time
        //     ofSignedNoise(time*timeScale) allows us to control the smoothness of
        //         our noise (smaller timeScale, smoother values)
        //     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise
        //         function to control multiple things and have them look as if they
        //         are moving independently
        //     ofSignedNoise(time)*displacementScale allows us to change the bounds
        //         of the noise from [-1, 1] to whatever we want
        // Combine all of those parameters together, and you've got some nice
        // control over your noise
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * scaledVol * 90.0f;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * scaledVol * 90.0f;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * scaledVol * 90.0f;
        mesh.setVertex(i, vert);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_LINEAR);
    
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/3, -ofGetHeight()/3);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
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
