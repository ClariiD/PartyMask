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
    
    /*bass.setPaused(true);
    drums.setPaused(true);
    horns.setPaused(true);
    keys.setPaused(true);
    percussion.setPaused(true);*/
    
    /*bass.play();
    drums.play();
    horns.play();
    keys.play();
    percussion.play();*/
    
    
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
    
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
    
    
    //leftEyeImage(tracker.getImageFeature(ofxFaceTracker::LEFT_EYE));
    //leftEyeImage.draw(leftEye);
    //(tracker.getImageFeature(ofxFaceTracker::LEFT_EYE));
    //ofPolyline faceOutline = tracker.getImageFeature(ofxFaceTracker::FACE_OUTLINE);
	
    ofPolyline leftEye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
	ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
	ofPolyline leftEyebrow = tracker.getImageFeature(ofxFaceTracker::LEFT_EYEBROW);
    ofPolyline rightEyebrow = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYEBROW);
    ofPolyline jaw = tracker.getImageFeature(ofxFaceTracker::JAW);
    ofPolyline noseBase = tracker.getImageFeature(ofxFaceTracker::NOSE_BASE);
    
  
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //ofPoint leftEyeMid = leftEye.getCentroid2D();
    
    for (leftEyePt){
    
        ofPoint leftEyePt = getAvgFromPolyline(leftEye);
        leftEyeImage.draw(leftEyePt.x, leftEyePt.y);
        bass.play();
    
    };
    
    
    /*ofPoint leftEyePt = getAvgFromPolyline(leftEye);
    leftEyeImage.draw(leftEyePt.x, leftEyePt.y);
    //bass.setPaused(false);
    bass.play();*/

    
    
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
    
    //ofPoint faceOutlinePt = getAvgFromPolyline(faceOutline);
    //faceOutlineImage.draw(faceOutlinePt.x, faceOutlinePt.y);

 
       
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    
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
    
    //faceOutline.draw();
	
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