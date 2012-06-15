#ifndef OFXQUADSOURCE_H
#define OFXQUADSOURCE_H


class ofxQuadSource
{
  public:
    /** Default constructor */
    ofxQuadSource();
    virtual void update() {};
    virtual void draw() = 0;
  protected:
  private:
};

#endif // OFXQUADSOURCE_H
