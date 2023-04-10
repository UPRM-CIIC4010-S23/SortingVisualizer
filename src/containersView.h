#pragma once

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include "ofMain.h"
#include "RackBox.h"

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

class ContainersView : public std::vector<RackBox>
{
private:
    using vector<RackBox>::vector; // use the constructors from vector
    std::vector<vmov> records;

    int playing;
    bool recording;
    size_t recordhead;
public:
    ContainersView() {}
    ~ContainersView() {}
    void setElements(int n, int from, int to);
    void setBoxSize(int boxsize){ boxsize = boxsize; }

    RackBox & operator[](int i) { return at(i); } // range-checked
    const RackBox & operator[](int i) const { return at(i); } // range-checked

    void next();
    void prev();
    void play() { playing = 1; recording = false;}
    void pause() { playing = 0; recording = true;}
    void ff();
    void rw() { playing = -1; recording = false;}
    void rrw();
    void swap(int i, int j);
    void mark(int i);
    void unmark(int i);

    void setup();
    void update();
    void draw();
};
