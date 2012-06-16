#include "ofxQuadSourceVideo.h"

ofxQuadSourceVideo::ofxQuadSourceVideo(ofVideoPlayer* video, float x, float y) {
  this->video = video;
  this->x = x;
  this->y = y;
}

void ofxQuadSourceVideo::update() {
  this->video->idleMovie();
}

void ofxQuadSourceVideo::draw() {
  this->video->draw(x, y);
}