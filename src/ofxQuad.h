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

#ifndef QUAD_H
#define QUAD_H

#include "ofMain.h"

class ofxQuad
{
  public:
    /** Default constructor */
    ofxQuad();
    void beginDraw();
    void endDraw();
    void draw(ofFbo fbo);
    void drawInputConfig();
    void drawOutputConfig();
    
    void setInputPoint(int index, float x, float y);
    ofPoint getInputPoint(int index) { return input[(int)ofClamp(index, 0, 3)]; }    
    void setOutputPoint(int index, float x, float y);
    ofPoint getOutputPoint(int index) { return output[(int)ofClamp(index, 0, 3)]; }
  protected:
  private:
    void drawConfig(ofPoint* points);
    ofPoint input[4];
    ofPoint output[4];
    ofFloatColor lineColor;    
};

#endif // QUAD_H
