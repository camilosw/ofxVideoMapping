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

#include "ofxQuad.h"
#include "homography.h"

ofxQuad::ofxQuad() {
  ofxQuad(ofPoint(0, 0), ofPoint(ofGetWidth(), 0), ofPoint(ofGetWidth(), ofGetHeight()), ofPoint(0, ofGetHeight()),
          ofPoint(0, 0), ofPoint(ofGetWidth(), 0), ofPoint(ofGetWidth(), ofGetHeight()), ofPoint(0, ofGetHeight()));
}

ofxQuad::ofxQuad(ofPoint inputPoint1, ofPoint inputPoint2, ofPoint inputPoint3, ofPoint inputPoint4, 
                 ofPoint outputPoint1, ofPoint outputPoint2, ofPoint outputPoint3, ofPoint outputPoint4) {
  input[0].set(inputPoint1);
  input[1].set(inputPoint2);
  input[2].set(inputPoint3);
  input[3].set(inputPoint4);

  output[0].set(outputPoint1);
  output[1].set(outputPoint2);
  output[2].set(outputPoint3);
  output[3].set(outputPoint4);
  
  lineColor.setHex(0xffffff);
}

void ofxQuad::setInputPoints(ofPoint point1, ofPoint point2, ofPoint point3, ofPoint point4) {
  setInputPoint(0, point1);
  setInputPoint(1, point2);
  setInputPoint(2, point3);
  setInputPoint(3, point4);
}

void ofxQuad::setInputPoint(int index, float x, float y) {
  index = ofClamp(index, 0, 3);
  input[index].set(x, y);
}

void ofxQuad::setInputPoint(int index, ofPoint point) {
  index = ofClamp(index, 0, 3);
  input[index].set(point);
}

void ofxQuad::setOutputPoints(ofPoint point1, ofPoint point2, ofPoint point3, ofPoint point4) {
  setOutputPoint(0, point1);
  setOutputPoint(1, point2);
  setOutputPoint(2, point3);
  setOutputPoint(3, point4);
}

void ofxQuad::setOutputPoint(int index, float x, float y) {
  index = ofClamp(index, 0, 3);
  output[index].set(x, y);
}

void ofxQuad::setOutputPoint(int index, ofPoint point) {
  index = ofClamp(index, 0, 3);
  output[index].set(point);
}

void ofxQuad::beginDraw() {
  // Start quad mask
  ofPushStyle();
  
  glClear(GL_STENCIL_BUFFER_BIT);
  glEnable(GL_STENCIL_TEST);
  glColorMask(0, 0, 0, 0);
  glStencilFunc(GL_ALWAYS, 1, 1);
  glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

  ofSetHexColor(0xffffff);
  ofBeginShape();
  for (int i = 0; i < 5; i++) {
    ofVertex(output[i%4].x, output[i%4].y);
  }
  ofEndShape();
  
  glColorMask(1, 1, 1, 1);
  glStencilFunc(GL_EQUAL, 1, 1);
  glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

  ofPopStyle();

  // Start quad transform
  findHomography(input, output, transformMatrix);
  ofPushMatrix();
  glMultMatrixf(transformMatrix);
}

void ofxQuad::endDraw() {
  // End quad transform
  ofPopMatrix();
  
  // End quad mask
  glDisable(GL_STENCIL_TEST);
}

void ofxQuad::draw() {
  if (source) {
    beginDraw();
    source->draw();
    endDraw();
  }
}

void ofxQuad::draw(ofFbo fbo) {
  beginDraw();
  fbo.draw(0, 0);
  endDraw();
}

void ofxQuad::drawInputConfig() {
  drawConfig(input);
}

void ofxQuad::drawOutputConfig() {
  drawConfig(output);
}

void ofxQuad::drawConfig(ofPoint* points) {
  ofPushStyle();
  ofNoFill();
  ofSetColor(lineColor);
  ofBeginShape();
  for (int i = 0; i < 5; i++) {
    ofVertex(points[i%4].x, points[i%4].y);
  }  
  ofEndShape();
  
  ofPopStyle();
}

