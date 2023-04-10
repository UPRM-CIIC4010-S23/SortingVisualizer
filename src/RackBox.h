#pragma once

#include "ofMain.h"

class RackBox
{
private:
    size_t height;
    size_t racksize;
    ofColor color;
    ofImage skin;
public:
    RackBox(size_t height, size_t racksize = 50, ofColor color = ofColor(0.5, 0.0), ofImage skin = ofImage("of.png"))
    {
        this->height = height;
        this->racksize = racksize;
        this->color = color;
        this->skin = skin;
    }
    ~RackBox() {}

    size_t getHeight() { return height; }
    void setColor(ofColor color) { color = color;}

    void draw();
};

inline void RackBox::draw()
{
    for (size_t j = 0; j < height; j++)
    {
        ofTranslate(glm::vec3(0.0, racksize, 0.0));
        skin.bind();
        ofFill();
        ofSetColor(255);
        ofDrawBox(racksize);
        skin.unbind();

        ofNoFill();
        ofSetColor(color);
        ofDrawBox(racksize + 0.1);
    }
}