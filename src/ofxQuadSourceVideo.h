#ifndef OFXQUADSOURCEVIDEO_H
#define OFXQUADSOURCEVIDEO_H

#include "ofMain.h"
#include "ofxQuadSource.h"

class ofxQuadSourceVideo : public ofxQuadSource
{
  public:
    /** Default constructor */
    ofxQuadSourceVideo(ofVideoPlayer* video);
    void update();
    void draw();    
  protected:
  private:
    ofVideoPlayer* video;
};

#endif // OFXQUADSOURCEIMAGE_H
