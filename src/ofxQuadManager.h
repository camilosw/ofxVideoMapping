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
//    ofxQuad* getCurrentQuad();
//    ofxQuad* setCurrentQuad(int index);
    
    void moveQuadTop(int index, int positions = 1);
    void moveQuadBottom(int index, int positions = 1);
//    void moveCurrentQuadTop(int position = 1);
//    void moveCurrentQuadBotom(int position = 1);
    int size() { return quads.size(); }
    
    void draw();
    
  protected:
  private:
    vector<ofxQuad*> quads;
//    int currentQuad;
//    int drawingQuad;
};

#endif // QUADCONTROLLER_H
