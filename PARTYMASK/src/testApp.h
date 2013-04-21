#pragma once

#include "ofMain.h"
#include "ofxCv.h"

#include "ofxFaceTracker.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
    ofImage leftEyeImage;
    
    
    ofSoundPlayer drums;
    ofSoundPlayer keys;
    ofSoundPlayer bass;
    ofSoundPlayer horns;
    ofSoundPlayer percussion;
    
    bool bDrums;
    bool bKeys;
    bool bBass;
    bool bHorns;
    bool bPercussion;
};
