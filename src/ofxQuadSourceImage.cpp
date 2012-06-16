#include "ofxQuadSourceImage.h"

ofxQuadSourceImage::ofxQuadSourceImage(ofImage* image, float x, float y) {
  this->image = image;
  this->x = x;
  this->y = y;
}

void ofxQuadSourceImage::draw() {
  this->image->draw(x, y);
}