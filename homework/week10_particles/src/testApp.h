#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Mover.h"

class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void addParticle();
    void drawFbos();
    
    vector<Particle> particleList;
    vector<Mover> moverList;
    
    bool attract;
    
    ofFbo myFbo;
    
    int stepA, stepB;
    
    float lastTime, timeScale;
    bool stopTime, nextFrame;
    
    int mode, imgNum;
    		
};
