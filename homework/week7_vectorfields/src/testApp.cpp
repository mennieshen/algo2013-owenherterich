#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20);
    ofBackground( 0 );
    
    ofxXmlSettings settings;
    if(settings.loadFile("positions.xml")){
        settings.pushTag("positions");
        for(int y = 0; y < myField.flowList.size(); y++) {
            for (int x = 0; x < myField.flowList[y].size(); x++) {

                settings.pushTag("position", myField.flowList.size() * y + x);
    
                ofVec2f p;
                p.x = settings.getValue("X", 0.0);
                p.y = settings.getValue("Y", 0.0);
                cout << "Flow List: " << y << " " << x << " Pos: " << p.x << " " << p.y << endl;
    
                myField.flowList[y][x] = p;
                settings.popTag();
            }
        }
    
        settings.popTag(); //pop position
    }
    else{
        ofLogError("Position file did not load!");
    }
    

}

void testApp::exit() {
    ofxXmlSettings positions;
    positions.addTag("positions");
    positions.pushTag("positions");
    //points is a vector<ofPoint> that we want to save to a file
    for(int y = 0; y < myField.flowList.size(); y++) {
        for (int x = 0; x < myField.flowList[y].size(); x++) {
            
    //each position tag represents one point
        positions.addTag("position");
        positions.pushTag("position",myField.flowList.size() * y + x);
    //so set the three values in the file
        positions.addValue("X", myField.flowList[y][x].x);
        positions.addValue("Y", myField.flowList[y][x].y);
        positions.popTag();//pop position
        }
    }
    positions.popTag(); //pop position
    positions.saveFile("positions.xml");
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f mouse;
    mouse.set(mouseX, mouseY);
    if (setMouse) {
        myField.setMouse(mouse);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == '1') {
        setMouse = false;
        myField.setRandom();
    }
    
    if (key == '2') {
        setMouse = false;
        myField.setPerlin();
    }
    
    if (key == '3') {
        setMouse = false;
        myField.setCircle();
    }
    
    if (key == '4') {
        setMouse = true;
    }
    
    if (key == '5') {
        setMouse = false;
        myField.setTrig();
    }
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
