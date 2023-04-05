#pragma once

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include "ofMain.h"

typedef enum
{
    SWAP,
    MARK,
    UNMARK
} MOVTYPE;

struct vmov
{
    MOVTYPE movtype;
    int i;
    int j;
};

class ContainersView
{
private:
    std::vector<size_t> elements;
    std::vector<ofColor> marks;
    std::vector<vmov> records;
    float boxsize;
	ofImage boxlogo; // the OF logo

    bool playing;
    bool recording;
    size_t recordhead;
public:
    ContainersView() {}
    ~ContainersView() {}
    void setElements(int n, int from, int to);
    void setBoxSize(int boxsize){ boxsize = boxsize; }
    void setBoxLogo(ofImage boxlogo) { boxlogo = boxlogo; }

    void play() { playing = true; recording = false;}
    void ff();
    void rw() { recordhead = 0; }
    void swap(int i, int j);
    void mark(int i);
    void unmark(int i);

    void setup();
    void update();
    void draw();
};
