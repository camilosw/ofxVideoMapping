#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(255,255,255); 
  
  bikers.loadImage("bikers.jpg");
  
  quad1.setInputPoints(ofPoint(100, 50), ofPoint(300, 100), ofPoint(350, 300), ofPoint(150, 350));
  quad1.setOutputPoints(ofPoint(100, 500), ofPoint(300, 500), ofPoint(300, 700), ofPoint(100, 700));
  
  fingerMovie.loadMovie("fingers.mov");
  fingerMovie.play();  
  
  quad2.setInputPoint(0, 620, 100);
  quad2.setInputPoint(1, fingerMovie.getWidth() + 510, 100);
  quad2.setInputPoint(2, fingerMovie.getWidth() + 510, fingerMovie.getHeight());
  quad2.setInputPoint(3, 620, fingerMovie.getHeight());
  
  quad2.setOutputPoint(0, 400, 500);
  quad2.setOutputPoint(1, 600, 520);
  quad2.setOutputPoint(2, 620, 650);
  quad2.setOutputPoint(3, 500, 640);

  ofColor color = ofColor(255, 0, 0);
  quad2.setLineColor(color);


  quad3.setInputPoint(0, ofPoint(900, 70));
  quad3.setInputPoint(1, ofPoint(1000, 70));
  quad3.setInputPoint(2, ofPoint(1000, 150));
  quad3.setInputPoint(3, ofPoint(900, 150));
  
  quad3.setOutputPoint(0, ofPoint(800, 500));
  quad3.setOutputPoint(1, ofPoint(1000, 520));
  quad3.setOutputPoint(2, ofPoint(1020, 650));
  quad3.setOutputPoint(3, ofPoint(500, 640));
  
  quad3.setHexLineColor(0x00ff00);
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
  quad1.beginDraw();
  bikers.draw(0, 0);
  quad1.endDraw();
  
  quad1.drawInputConfig();
  quad1.drawOutputConfig();
  
  fingerMovie.draw(510, 0);
  quad2.beginDraw();
  fingerMovie.draw(510, 0);
  quad2.endDraw();
  
  quad2.drawInputConfig();
  quad2.drawOutputConfig();
  
  ofSetHexColor(0x0cb0b6);
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	for (int i = 0; i < 10; i++){
		ofVertex(ofRandom(850,1050), ofRandom(20,200));
	}
	ofEndShape();

  quad3.beginDraw();
	ofBeginShape();
	for (int i = 0; i < 10; i++){
		ofVertex(ofRandom(850,1050), ofRandom(20,200));
	}
	ofEndShape();
	quad3.endDraw();

  quad3.drawInputConfig();
  quad3.drawOutputConfig();
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