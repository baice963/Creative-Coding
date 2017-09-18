#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    last = ofGetElapsedTimeMillis();
    col.setHsb(0,255,255);
    
    shader.load("","shader.frag");
    smoothSpeed = 0.95;
    smoothSpeed2 = 0.99;
    
    for(int i=0; i<NCIRC; i++){
        myFunCircles[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(col);
    if(ofGetElapsedTimeMillis() - last > 50)
    {
        col.setHue(counter % 256);
        counter ++;
        last = ofGetElapsedTimeMillis();
    }
    
    smoothX = smoothSpeed*smoothX + (1-smoothSpeed)*mouseX;
    smoothY = smoothSpeed2*smoothY + (1-smoothSpeed2)*mouseY;
    
    for(int i=0; i<NCIRC; i++){
        myFunCircles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    shader.begin();
    
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform2f("u_mouse", mouseX, mouseY);
    
    shader.setUniform1f("u_smoothX", smoothX);
    shader.setUniform1f("u_smoothY", smoothY);
    
    for(int i=0; i<NCIRC; i++){
        myFunCircles[i].draw();
    }
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    shader.load("","shader.frag");
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
