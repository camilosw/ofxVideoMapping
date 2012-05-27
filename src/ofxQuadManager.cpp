#include "ofxQuadManager.h"

ofxQuadManager::ofxQuadManager() {
  
}

ofxQuad* ofxQuadManager::addQuad() {
  ofxQuad* quad = new ofxQuad();
  quads.push_back(quad);
  currentQuad = quads.size();
  return quad;
}

ofxQuad* ofxQuadManager::addQuad(ofPoint inputPoint1, ofPoint inputPoint2, ofPoint inputPoint3, ofPoint inputPoint4, 
                                 ofPoint outputPoint1, ofPoint outputPoint2, ofPoint outputPoint3, ofPoint outputPoint4) {
  ofxQuad* quad = new ofxQuad(inputPoint1, inputPoint2, inputPoint3, inputPoint4, 
                              outputPoint1, outputPoint2, outputPoint3, outputPoint4);
  quads.push_back(quad);
  currentQuad = quads.size();
  return quad;
}

void ofxQuadManager::removeQuad(int index) {
}

ofxQuad* ofxQuadManager::getQuad(int index) {
  index = ofClamp(index, 0, quads.size());
  return quads[index];
}

ofxQuad* ofxQuadManager::getCurrentQuad() {
  return quads[currentQuad];
}

ofxQuad* ofxQuadManager::setCurrentQuad(int index) {
  currentQuad = index;
}

void ofxQuadManager::moveQuadTop(int index, int positions) {}
void ofxQuadManager::moveQuadBottom(int index, int positions) {}
void ofxQuadManager::moveCurrentQuadTop(int position) {}
void ofxQuadManager::moveCurrentQuadBotom(int position) {}