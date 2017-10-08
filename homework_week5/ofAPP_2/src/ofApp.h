#pragma once

#include "ofMain.h"
#include "FunCircles.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#define NCIRC 500
#define _USE_LIVE_VIDEO

enum Scenes{
    IDLE,
    SKY_SCENE,
    SUN_SCENE
};

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
    void circleResolutionChanged(int & circleResolution);
    
    ofxFloatSlider radius;
    ofxPanel gui;
    ofxIntSlider circleResolution;

    ofShader shader;
    
    
    float smoothX;
    float smoothY;
    float smoothSpeed;
    float smoothSpeed2;
    
    FunCircles myFunCircles[NCIRC];
    
    unsigned long last;
    int counter;
    ofColor col;
    
    ofImage image;
    ofMesh mesh;
    ofMesh meshCopy;
    ofEasyCam easyCam;
    
    vector<ofVec3f> offsets;
    
    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    ofVideoGrabber cam;
    ofxCvColorImage			colorImg;
    
    ofxCvGrayscaleImage 	grayImage;
    ofxCvGrayscaleImage 	grayBg;
    ofxCvGrayscaleImage 	grayDiff;
    int 				threshold;
    bool				bLearnBakground;
    
    ofxCvContourFinder 	contourFinder;
    Scenes currentScene;
    
    
    
    
};
