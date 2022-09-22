#include "ofApp.h"
#include "Particle.h"
#include "ParticleSystem.h"

//--------------------------------------------------------------
void ofApp::setup(){
	

	ofDisableArbTex();

	quad.addVertex(glm::vec3(-1, -1, 0));
	quad.addVertex(glm::vec3(-1, 1, 0));
	quad.addVertex(glm::vec3(1, 1, 0));
	quad.addVertex(glm::vec3(1, -1, 0));


	quad.addColor(ofFloatColor(1, 0, 0, 1));
	quad.addColor(ofFloatColor(0, 1, 0, 1));
	quad.addColor(ofFloatColor(0, 0, 1, 1));
	quad.addColor(ofFloatColor(1, 1, 1, 1));



	quad.addTexCoord(glm::vec2(0, 0));
	quad.addTexCoord(glm::vec2(0, 1));
	quad.addTexCoord(glm::vec2(1, 1));
	quad.addTexCoord(glm::vec2(1, 0));

	ofIndexType indices[6]{ 0 , 1 , 2 , 2, 3 ,0 };
	quad.addIndices(indices, 6);

	ofDisableArbTex();
	fireImg.load("smoke_04.png");
	fireShader.load("FireShader.vert", "FireShader.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
	//gets time between frames
	partSystem.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw(){
	fireShader.begin();
	//loops through each particle for us to access the peices such as:
	//position
	for (const BasicParticle& p : partSystem) {
		fireShader.setUniformTexture("FireTex", fireImg, p.pos.y);

		//fireShader.setUniform1f("FireTex",p.pos.y);
		quad.draw();
	}
	//loop over all of the particle, draw the quads
	fireShader.setUniformTexture("FireTex", fireImg, 0);
	//quad.draw();
	//triangle.draw();

	fireShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
