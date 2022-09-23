#pragma once

#include "ofMain.h"
#include "BasicParticleGenerator.h"
#include "ParticleSystem.h"


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
		
private:
	BasicParticleGenerator particalGen {};
	//10 is the number of particles
	//40 is the rate at which they spawn (20 per second)
	ParticleSystem<BasicParticle> partSystem{particalGen , 102 , 40.0f};

	ofMesh quad{};
	ofShader fireShader{};
	ofImage fireImg;
};
