//  Copyright (C) 2012, Juan Camilo Mejia, https://github.com/camilosw/ofxVideoMapping
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "ofxQuadManager.h"

ofxQuadManager::ofxQuadManager() {
  
}

ofxQuad* ofxQuadManager::addQuad() {
  ofxQuad* quad = new ofxQuad();
  quads.push_back(quad);
//  currentQuad = quads.size() - 1;
  return quad;
}

ofxQuad* ofxQuadManager::addQuad(ofPoint inputPoint1, ofPoint inputPoint2, ofPoint inputPoint3, ofPoint inputPoint4, 
                                 ofPoint outputPoint1, ofPoint outputPoint2, ofPoint outputPoint3, ofPoint outputPoint4) {
  ofxQuad* quad = new ofxQuad(inputPoint1, inputPoint2, inputPoint3, inputPoint4, 
                              outputPoint1, outputPoint2, outputPoint3, outputPoint4);
  quads.push_back(quad);
//  currentQuad = quads.size() - 1;
  return quad;
}

void ofxQuadManager::removeQuad(int index) {
}

ofxQuad* ofxQuadManager::getQuad(int index) {
  index = ofClamp(index, 0, quads.size());
  return quads[index];
}

//ofxQuad* ofxQuadManager::getCurrentQuad() {
//  return quads[currentQuad];
//}
//
//ofxQuad* ofxQuadManager::setCurrentQuad(int index) {
//  currentQuad = index;
//}

void ofxQuadManager::moveQuadTop(int index, int positions) {}
void ofxQuadManager::moveQuadBottom(int index, int positions) {}
//void ofxQuadManager::moveCurrentQuadTop(int position) {}
//void ofxQuadManager::moveCurrentQuadBotom(int position) {}

void ofxQuadManager::draw() {
  for (int i = 0; i < quads.size(); i++) {
    quads[i]->draw();
  }
}