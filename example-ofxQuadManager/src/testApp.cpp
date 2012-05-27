#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(255,255,255); 
  
  bikers.loadImage("bikers.jpg");
  
  quadManager.addQuad(ofPoint(100, 50), ofPoint(300, 100), ofPoint(350, 300), ofPoint(150, 350),
                      ofPoint(100, 500), ofPoint(300, 500), ofPoint(300, 700), ofPoint(100, 700));
}

//--------------------------------------------------------------
void testApp::update(){
  fingerMovie.idleMovie();
}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackground(0);
	ofSetHexColor(0xffffff);
	
  bikers.draw(0, 0);
  quadManager.getQuad(0)->beginDraw();
  bikers.draw(0, 0);
  quadManager.getQuad(0)->endDraw();
  
  quadManager.getQuad(0)->drawInputConfig();
  quadManager.getQuad(0)->drawOutputConfig();

	
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