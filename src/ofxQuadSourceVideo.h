#ifndef OFXQUADSOURCEVIDEO_H
#define OFXQUADSOURCEVIDEO_H

#include "ofMain.h"
#include "ofxQuadSource.h"

class ofxQuadSourceVideo : public ofxQuadSource
{
  public:
    /** Default constructor */
    ofxQuadSourceVideo(ofVideoPlayer* video, float x = 0, float y = 0);
    void update();
    void draw();    
  protected:
  private:
    ofVideoPlayer* video;
};

#endif // OFXQUADSOURCEIMAGE_H
