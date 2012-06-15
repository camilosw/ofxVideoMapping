#include "ofxQuadSourceVideo.h"

ofxQuadSourceVideo::ofxQuadSourceVideo(ofVideoPlayer* video) {
  this->video = video;
}

void ofxQuadSourceVideo::update() {
  this->video->idleMovie();
}

void ofxQuadSourceVideo::draw() {
  this->video->draw(0, 0);
}