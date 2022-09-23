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
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	fireShader.begin();
	//loops through each particle for us to access the pieces
	for (const BasicParticle& p : partSystem) {
		fireShader.setUniform1f("opacity", p.opacity);
		fireShader.setUniformTexture("FireTex", fireImg, 0);
		mat4 translationA = translate(vec3(p.pos));
		mat4 scaleA = scale(vec3(.6, .75, 1));
		mat4 transform = translationA * scaleA;
		fireShader.setUniformMatrix4f("transform", transform);

		quad.draw();
	}

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
