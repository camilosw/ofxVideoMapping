#include "testApp.h"
#include "ofxQuadSourceImage.h"
#include "ofxQuadSourceVideo.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(255,255,255); 
  
  // Image
  bikers.loadImage("bikers.jpg");
  
  quadManager.addQuad(ofPoint(100, 50), ofPoint(300, 100), ofPoint(350, 300), ofPoint(150, 350),
                      ofPoint(100, 500), ofPoint(300, 500), ofPoint(300, 700), ofPoint(100, 700));
  ofxQuad* quad = quadManager.getQuad(0);

  ofxQuadSourceImage* imageSource =  new ofxQuadSourceImage(&bikers);
  quad->setSource(imageSource);
  
  // Video  
  fingerMovie.loadMovie("fingers.mov");
  fingerMovie.play();
  
  quad = quadManager.addQuad();
  quad->setInputPoints(ofPoint(620, 100),
                       ofPoint(fingerMovie.getWidth() + 510, 100),
                       ofPoint(fingerMovie.getWidth() + 510, fingerMovie.getHeight()),
                       ofPoint(620, fingerMovie.getHeight()));
  quad->setOutputPoints(ofPoint(400, 500),
                        ofPoint(600, 520),
                        ofPoint(620, 650),
                        ofPoint(500, 640));
  
  ofxQuadSourceVideo* videoSource = new ofxQuadSourceVideo(&fingerMovie);
  quad->setSource(videoSource );
                        
  ofColor color = ofColor(255, 0, 0);
  quad->setLineColor(color);
  
}

//--------------------------------------------------------------
void testApp::update(){
  fingerMovie.idleMovie();
  
  quadManager.update();
}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackground(0);
	ofSetHexColor(0xffffff);
	
  // Draw input
  bikers.draw(0, 0);
  fingerMovie.draw(510, 0);

  // Draw output
  quadManager.draw();

  quadManager.getQuad(0)->drawInputConfig();
  quadManager.getQuad(0)->drawOutputConfig();

  quadManager.getQuad(1)->drawInputConfig();
  quadManager.getQuad(1)->drawOutputConfig();

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