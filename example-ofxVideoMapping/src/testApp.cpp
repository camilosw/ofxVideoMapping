#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(255,255,255); 
  
  fingerMovie.loadMovie("fingers.mov");
  fingerMovie.play();  
  
  quad1.setInputPoint(0, 100, 100);
  quad1.setInputPoint(1, fingerMovie.getWidth(), 100);
  quad1.setInputPoint(2, fingerMovie.getWidth(), fingerMovie.getHeight());
  quad1.setInputPoint(3, 100, fingerMovie.getHeight());
  
  quad1.setOutputPoint(0, 200, 500);
  quad1.setOutputPoint(1, 400, 520);
  quad1.setOutputPoint(2, 420, 650);
  quad1.setOutputPoint(3, 300, 640);

  quad2.setInputPoint(0, 700, 70);
  quad2.setInputPoint(1, 800, 70);
  quad2.setInputPoint(2, 800, 150);
  quad2.setInputPoint(3, 700, 150);
  
  quad2.setOutputPoint(0, 600, 500);
  quad2.setOutputPoint(1, 800, 520);
  quad2.setOutputPoint(2, 820, 650);
  quad2.setOutputPoint(3, 300, 640);
}

//--------------------------------------------------------------
void testApp::update(){
  fingerMovie.idleMovie();
}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackground(0);
	ofSetHexColor(0xffffff);
	
  fingerMovie.draw(0, 0);
  quad1.beginDraw();
  fingerMovie.draw(0, 0);
  quad1.endDraw();
  
  quad1.drawInputConfig();
  quad1.drawOutputConfig();
  
  ofSetHexColor(0x0cb0b6);
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	for (int i = 0; i < 10; i++){
		ofVertex(ofRandom(650,850), ofRandom(20,200));
	}
	ofEndShape();

  quad2.beginDraw();
	ofBeginShape();
	for (int i = 0; i < 10; i++){
		ofVertex(ofRandom(650,850), ofRandom(20,200));
	}
	ofEndShape();
	quad2.endDraw();

  quad2.drawInputConfig();
  quad2.drawOutputConfig();
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