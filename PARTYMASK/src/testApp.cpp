#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	cam.initGrabber(640, 480);
	
	tracker.setup();
	tracker.setRescale(.5);
    leftEyeImage.loadImage("leftEye.png");
	leftEyeImage.setImageType(OF_IMAGE_GRAYSCALE);
    
    bass.loadSound("BASS1.mp3");
    drums.loadSound("DRUMS1.mp3");
    horns.loadSound("HORNS1.mp3");
    keys.loadSound("KEYS1.mp3");
    percussion.loadSound("PERCUSSION1.mp3");
    
    bass.setLoop(true);
    drums.setLoop(true);
    horns.setLoop(true);
    keys.setLoop(true);
    percussion.setLoop(true);
    
    bass.setVolume(300);
    drums.setVolume(300);
    horns.setVolume(300);
    keys.setVolume(300);
    percussion.setVolume(300);
    
    bass.play();
    drums.play();
    horns.play();
    keys.play();
    percussion.play();
    
    
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    
    //leftEyeImage(tracker.getImageFeature(ofxFaceTracker::LEFT_EYE));

    //leftEyeImage.draw(leftEye);
    
    //leftEye.draw(0,0);
    //(tracker.getImageFeature(ofxFaceTracker::LEFT_EYE));
	ofPolyline leftEye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
	ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
	ofPolyline faceOutline = tracker.getImageFeature(ofxFaceTracker::FACE_OUTLINE);
	
	ofSetLineWidth(2);
	ofSetColor(ofColor::red);
	leftEye.draw();
	ofSetColor(ofColor::green);
	rightEye.draw();
	ofSetColor(ofColor::blue);
	faceOutline.draw();
	
	ofSetLineWidth(1);
	ofSetColor(255);
	tracker.draw();
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}

/*void ofSoundPlayer::play(){

}*/