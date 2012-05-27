#ifndef QUADCONTROLLER_H
#define QUADCONTROLLER_H

#include "ofxQuad.h"
#include <vector>

class ofxQuadManager
{
  public:
    /** Default constructor */
    ofxQuadManager();
    
    ofxQuad* addQuad();
    ofxQuad* addQuad(ofPoint inputPoint1, ofPoint inputPoint2, ofPoint inputPoint3, ofPoint inputPoint4, 
                     ofPoint outputPoint1, ofPoint outputPoint2, ofPoint outputPoint3, ofPoint outputPoint4);
    void removeQuad(int index);
    ofxQuad* getQuad(int index);
    ofxQuad* getCurrentQuad();
    ofxQuad* setCurrentQuad(int index);
    
    void moveQuadTop(int index, int positions = 1);
    void moveQuadBottom(int index, int positions = 1);
    void moveCurrentQuadTop(int position = 1);
    void moveCurrentQuadBotom(int position = 1);
    int size() { return quads.size(); }
    
  protected:
  private:
    vector<ofxQuad*> quads;
    int currentQuad;
    int drawingQuad;
};

#endif // QUADCONTROLLER_H
