#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	cam.initGrabber(1080, 720);
	
	tracker.setup();
	tracker.setRescale(.5);
    leftEyeImage.loadImage("leftEye.png");
    rightEyeImage.loadImage("rightEye.png");
    leftEyebrowImage.loadImage("leftEyebrow.png");
    rightEyebrowImage.loadImage("rightEyebrow.png");
    jawImage.loadImage("mouth.png");
    noseBaseImage.loadImage("nostril2.png");
    
    //faceOutlineImage.loadImage("jaw.png");
    //leftEyeImage.setImageType(OF_IMAGE_COLOR);
    
    bass.loadSound("BASS1.mp3");
    drums.loadSound("DRUMS1.mp3");
    horns.loadSound("HORNS1.mp3");
    keys.loadSound("KEYS1.mp3");
    percussion.loadSound("PERCUSSION1.mp3");
    
    bass.setLoop(true);
    drums.setLoop(true);
    drums.setVolume(0);
    
    drums.play();
    
    horns.setLoop(true);
    keys.setLoop(true);
    percussion.setLoop(true);
    
    bass.setVolume(300);
    drums.setVolume(300);
    horns.setVolume(300);
    keys.setVolume(300);
    percussion.setVolume(300);
    
    bass.getIsPlaying();
    drums.getIsPlaying();
    horns.getIsPlaying();
    keys.getIsPlaying();
    percussion.getIsPlaying();
    
    drumEnergy = 0;
}

void testApp::update() {
	
    cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
    
    drumEnergy = 0.90 * drumEnergy + 0.1 * 0.0;
    drums.setVolume(drumEnergy);
}


ofPoint getAvgFromPolyline(ofPolyline & line){
    
    ofPoint avg;
    int count = 0;
    for (int i = 0; i < line.size(); i++){
        avg += line[i];
        count++;
    }
    if (count > 0){
        avg /= (float) count;
    }

    return avg;
}


void testApp::draw() {
    
    ofEnableAlphaBlending();
	ofSetColor(255);
	cam.draw(0, 0);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);

	
    ofPolyline leftEye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
	ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
	ofPolyline leftEyebrow = tracker.getImageFeature(ofxFaceTracker::LEFT_EYEBROW);
    ofPolyline rightEyebrow = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYEBROW);
    ofPolyline jaw = tracker.getImageFeature(ofxFaceTracker::JAW);
    ofPolyline noseBase = tracker.getImageFeature(ofxFaceTracker::NOSE_BASE);
    
    
    float mouthHeight = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT);
    float leftEyeOpenness = tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS);
    float rightEyeOpenness = tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS);
    float leftEyebrowHeight = tracker.getGesture(ofxFaceTracker::LEFT_EYEBROW_HEIGHT);
    float rightEyebrowHeight = tracker.getGesture(ofxFaceTracker::RIGHT_EYEBROW_HEIGHT);
    
//    cout<<mouthHeight<<endl;
//    cout<<leftEyeOpenness<<endl;
//    cout<<rightEyeOpenness<<endl;
//    cout<<leftEyebrowHeight<<endl;
//    cout<<rightEyebrowHeight<<endl;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
    if(leftEyebrowHeight > 3){
        //drumEnergy = 1;
    }else{
        //drumEnergy = 0;
    }
    
    
    ofPoint leftEyePt = getAvgFromPolyline(leftEye);
    leftEyeImage.draw(leftEyePt.x, leftEyePt.y);

    ofPoint leftEyebrowPt = getAvgFromPolyline(leftEyebrow);
    leftEyebrowImage.draw(leftEyebrowPt.x, leftEyebrowPt.y);
    
    ofPoint rightEyePt = getAvgFromPolyline(rightEye);
    rightEyeImage.draw(rightEyePt.x, rightEyePt.y);
    
    ofPoint rightEyebrowPt = getAvgFromPolyline(rightEyebrow);
    rightEyebrowImage.draw(rightEyebrowPt.x, rightEyebrowPt.y);
    
    ofPoint noseBasePt = getAvgFromPolyline(noseBase);
    noseBaseImage.draw(noseBasePt.x, noseBasePt.y);
    
    ofPoint jawPt = getAvgFromPolyline(jaw);
    jawImage.draw(jawPt.x,jawPt.y);
    
	ofSetLineWidth(2);
	ofSetColor(ofColor::red);
	leftEye.draw();
	ofSetColor(ofColor::green);
	rightEye.draw();
	ofSetColor(ofColor::blue);
    jaw.draw();
    rightEyebrow.draw();
    leftEyebrow.draw();
    noseBase.draw();
	
	ofSetLineWidth(1);
	ofSetColor(255);
	tracker.draw();
}


void testApp::keyPressed(int key) {
	
    if (key == 'a'){
        drumEnergy = 1;
    }
    
    if(key == 'r') {
		tracker.reset();
	}
}