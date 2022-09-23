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

	quad.addTexCoord(glm::vec2(0, 0));
	quad.addTexCoord(glm::vec2(0, 1));
	quad.addTexCoord(glm::vec2(1, 1));
	quad.addTexCoord(glm::vec2(1, 0));



	Lquad.addVertex(glm::vec3(-1, -1, 0));
	Lquad.addVertex(glm::vec3(-1, 1, 0));
	Lquad.addVertex(glm::vec3(1, 1, 0));
	Lquad.addVertex(glm::vec3(1, -1, 0));

	Lquad.addTexCoord(glm::vec2(0, 0));
	Lquad.addTexCoord(glm::vec2(0, 1));
	Lquad.addTexCoord(glm::vec2(1, 1));
	Lquad.addTexCoord(glm::vec2(1, 0));

	ofIndexType indices[6]{ 0 , 1 , 2 , 2, 3 ,0 };
	quad.addIndices(indices, 6);
	Lquad.addIndices(indices, 6);


	fireShader.load("FireShader.vert", "FireShader.frag");
	boltShader.load("BoltShader.vert", "BoltShader.frag");

	fireImg.load("smoke_04.png");
	fireImg2.load("smoke_06.png");

	cloudTexture[0] = fireImg;
	cloudTexture[1] = fireImg2;


	//load bolt picture
	boltImg.load("spark_05.png");
	boltImg2.load("spark_01.png");

	boltTexture[0] = boltImg;
	boltTexture[1] = boltImg2;

}

//--------------------------------------------------------------
void ofApp::update(){
	//gets time between frames
	partSystem.update(ofGetLastFrameTime());
	boltParticleSystem.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
	fireShader.begin();
	//loops through each particle for us to access the pieces
	for (const BasicParticle& p : partSystem) {
		fireShader.setUniform1f("opacity", p.opacity);
		fireShader.setUniformTexture("FireTex", cloudTexture[p.getTexture()], 0);
		mat4 translationA = translate(vec3(p.pos));
		mat4 scaleA = scale(vec3(.6, .75, 1));
		mat4 transform = translationA * scaleA;
		fireShader.setUniformMatrix4f("transform", transform);

		quad.draw();
	}
	fireShader.end();
	ofDisableBlendMode();
	

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	boltShader.begin();
	for (const BasicParticle& p : boltParticleSystem) {
		boltShader.setUniform1f("opacity", p.opacity);
		boltShader.setUniformTexture("BoltTex", boltTexture[p.getTexture()], 0);
		mat4 translationA = translate(vec3(p.pos)/1.3);
		mat4 scaleA = scale(vec3(p.pos.x, p.pos.x, 1));
		mat4 transform = translationA * scaleA;
		mat4 ourRotation = rotate(p.pos.x + p.pos.y, vec3(0, 0, 1.0));
		mat4 newMatrix = translationA * ourRotation * inverse(translationA);
		mat4 finalMatrix = newMatrix * transform;
		boltShader.setUniformMatrix4f("transform", finalMatrix);

		Lquad.draw();
	}
	boltShader.end();
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
