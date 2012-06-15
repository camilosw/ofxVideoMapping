#ifndef OFXQUADSOURCEIMAGE_H
#define OFXQUADSOURCEIMAGE_H

#include "ofMain.h"
#include "ofxQuadSource.h"

class ofxQuadSourceImage : public ofxQuadSource
{
  public:
    /** Default constructor */
    ofxQuadSourceImage(ofImage* image);
    void draw();
  protected:
  private:
    ofImage* image;
};

#endif // OFXQUADSOURCEIMAGE_H
