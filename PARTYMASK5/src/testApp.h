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
    ofImage rightEyeImage;
    ofImage leftEyebrowImage;
    ofImage rightEyebrowImage;
    ofImage jawImage;
    ofImage mouthImage;
    ofImage noseBaseImage;
    //ofImage faceOutlineImage;
    
    
    float drumEnergy;
    float bassEnergy;
    float hornsEnergy;
    float keysEnergy;
    float percussionEnergy;
    
    
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
