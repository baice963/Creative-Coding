#pragma once

#include "ofMain.h"
//#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage backImg;
    ofImage planet;
    ofImage planet1;
    ofImage planet2;
    ofImage planet3;
    ofImage planet4;
    
//    ofxAssimpModelLoader naboo;
    
    //DATA TYPES:
    //int : integer (-1,0,1,2)
    //float : decimals (-2.003,.003)
    //string: text ("hello world)
    //bool: true/false
    
    float x;
    float y;
    
    float smoothX;
    float smoothY;
    
    float cX;
    float cY;
    
    float angle2;
    float angle3;
    float angle4;
    
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();
    
   
    
};
