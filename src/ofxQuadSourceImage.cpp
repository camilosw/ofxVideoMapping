#include "ofxQuadSourceImage.h"

ofxQuadSourceImage::ofxQuadSourceImage(ofImage* image) {
  this->image = image;
}

void ofxQuadSourceImage::draw() {
  this->image->draw(0, 0);
}