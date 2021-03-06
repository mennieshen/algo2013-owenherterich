#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    newDest.x = ofRandom(ofGetWindowWidth());
    newDest.y = ofRandom(ofGetWindowHeight());
    buffer = 0.4;
    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < NUM_RECTS; i++) {
        if (i == 0) {
        myRectangle[i].xenoToPoint(newDest.x, newDest.y);
        }
        else {
        myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x, myRectangle[i-1].pos.y);
        }
    }
    
    if (myRectangle[0].pos.x > newDest.x-buffer && myRectangle[0].pos.x < newDest.x+buffer && myRectangle[0].pos.y > newDest.y-buffer && myRectangle[0].pos.y < newDest.y+buffer) {
        newDest.x = ofRandom(ofGetWindowWidth());
        newDest.y = ofRandom(ofGetWindowHeight());
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(10);
    
    for (int i = 0; i < NUM_RECTS; i++) {
        myRectangle[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < NUM_RECTS; i++) {
        myRectangle[i].pos.x = ofRandom(ofGetWindowWidth());
        myRectangle[i].pos.y = ofRandom(ofGetWindowHeight());
    }
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
