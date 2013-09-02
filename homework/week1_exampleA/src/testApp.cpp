#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myThing.w = 25;
    myThing.pos.x = ofGetWindowWidth() / 2;
    myThing.pos.y = ofGetWindowHeight() / 2;
    //myThing.speed = (.2 / ofGetFrameRate());
    myThing.speed = .003f;
    
    pixelSpeed = 0;
    inchesSecond = 0;
    milesHour = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    myThing.update();
    
    pixelSpeed = myThing.speed * ofGetFrameRate(); 
    inchesSecond = (pixelSpeed * 11.3125) / ofGetWindowWidth();
    milesHour = (inchesSecond * 3600) / 63360;
    
    c.r = ofRandom(255);
    c.g = ofRandom(255);
    c.b = ofRandom(255);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(c);
    myThing.draw();
    
    ofSetColor(255);
    ofDrawBitmapString("Position:", ofPoint(10,20));
    ofDrawBitmapString(ofToString(myThing.pos.x), ofPoint(85,20));
    ofDrawBitmapString("Speed (px/s):", ofPoint(10, 40));
    ofDrawBitmapString(ofToString(pixelSpeed), ofPoint(120, 40));
    ofDrawBitmapString("Speed (in/s):", ofPoint(10, 60));
    ofDrawBitmapString(ofToString(inchesSecond), ofPoint(120, 60));
    ofDrawBitmapString("Speed (mph):", ofPoint(10, 80));
    ofDrawBitmapString(ofToString(milesHour), ofPoint(110, 80));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}