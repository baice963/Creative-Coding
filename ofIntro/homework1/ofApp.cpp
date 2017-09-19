#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition(screenW, screenH);
    ofSetBackgroundColor(0);
    ofSetCircleResolution(50);
    
    backImg.load("backgroundImg.jpg");
    planet.load("planet.png");
    planet1.load("planet1.png");
    planet2.load("planet2.png");
    planet3.load("planet3.png");
    planet4.load("planet4.png");
    
//    naboo.loadModel("naboo.3ds", false);
    
    
    
    
    x = screenW/3+25;
    y = screenH/3+100;
    
    smoothX = 0;
    smoothY = 0;
    
    cX = 0;
    cY = 0;
    
    angle2 = 0;
    angle3 = 0;
    angle4 = 0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    smoothX = .9 * smoothX + (1-.9) * mouseX;
//    smoothY = .9 * smoothY + (1-.9) * mouseY;
//    
    //increase
    angle2 += .01;
    angle3 += -.05;
    angle4 += .01;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    backImg.draw(0,0,screenW, screenH);
    
//    float angle = atan2(mouseY-y, mouseX-x); //atan: inverse tangent
//    angle = ofRadToDeg(angle); //conversion from radians to degrees
    
//    ofSetRectMode(OF_RECTMODE_CENTER);
    
//    ofPushMatrix();
//    ofTranslate(smoothX, smoothY);
//    ofRotate(angle);
//    ofFill();
//    ofDrawRectangle(0, 0, 40,40);
//    ofPopMatrix();
    
    ofPushMatrix();
//    ofTranslate(x, y, 0);
//    ofRotate(45);
//    planet.setAnchorPoint(x/2, y/2);
    planet.draw(480, 380, 40,40);
    ofPopMatrix();
    
    
//  CIRCLE #1
//    ofNoFill();
//    ofDrawCircle(x, y, 50);
    
    ofPushMatrix();
        cX = 40 * cos(angle2);
        cY = 40 * sin(angle2);
        ofTranslate(x+cX, y+cY, 0);
        ofRotate(45);
        planet1.setAnchorPoint(x+cX/2, y+cY/2);
        planet1.draw(x+cX, y+cY, 10,10);
    ofPopMatrix();
    
    ofPushMatrix();
    cX = 70 * cos(angle3);
    cY = 70 * sin(angle3);
    ofTranslate(x+cX, y+cY, 0);
    ofRotate(45);
    planet1.setAnchorPoint(x+cX/2, y+cY/2);
    planet1.draw(x+cX, y+cY, 10,10);
    ofPopMatrix();

//  CIRCLE#2
//    ofNoFill();
//    ofDrawCircle(x, y, 120);
    ofPushMatrix();
        cX = 100 * cos(angle3-1);
        cY = 100 * sin(angle3-1);
        ofTranslate(x+cX, y+cY, 0);
        ofRotate(45);
        planet2.setAnchorPoint(x+cX/2, y+cY/2);
        planet2.draw(x+cX, y+cY, 20,20);
    ofPopMatrix();
    
    //  CIRCLE#3
    ofPushMatrix();
        cX = 140 * cos(angle4);
        cY = 140 * sin(angle4);
        ofTranslate(x+cX, y+cY, 0);
        ofRotate(45);
        planet3.setAnchorPoint(x+cX/2, y+cY/2);
        planet3.draw(x+cX, y+cY, 50,50);
    ofPopMatrix();

    //  CIRCLE#4
//    ofNoFill();
//    ofDrawCircle(x, y, 200);
    ofPushMatrix();
    cX = 190 * cos(angle3-0.4);
    cY = 200 * sin(angle3-0.4);
    ofTranslate(x+cX, y+cY, 0);
    ofRotate(45);
    planet4.setAnchorPoint(x+cX/2, y+cY/2);
    planet4.draw(x+cX, y+cY, 70,70);
 
//    ofFill();
//    ofDrawCircle(x+cX, y+cY, 10);
    
//    naboo.drawFaces();
    
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
