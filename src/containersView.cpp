#include "containersView.h"

void ContainersView::setElements(int n, int from, int to)
{
    /* initialize random seed: */
    srand (time(NULL));
    for (int i = 0; i < n; i++)
    {
        elements.push_back(rand() % (to-from) + from);
        marks.push_back(ofColor(0.5, 0.0));
    }
    
}

void ContainersView::swap(int i, int j)
{
    int temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp; 
    
    if (recording)
    {
        records.push_back({MOVTYPE::SWAP, i, j});
        records.push_back({MOVTYPE::UNMARK, i, i});
        records.push_back({MOVTYPE::UNMARK, j, j});
    }
}

void ContainersView::mark(int i)
{
    marks[i] = ofColor(0.5, 0.0);
    if (recording)
    {
        records.push_back({MOVTYPE::MARK, i, i});
    }
}

void ContainersView::unmark(int i)
{
    marks[i] = ofColor(255, 0, 0, 128);
    if (recording)
    {
        records.push_back({MOVTYPE::MARK, i, i});
    }
}

void ContainersView::setup()
{
    // loads the OF logo from disk
	boxlogo.load("of.png");
    boxsize = 50;

    recordhead = 0;
    recording = true;
}

void ContainersView::update()
{
    if (playing && (ofGetFrameNum() % 30 == 0))
    {
        if (records.size() > recordhead)
        {
            vmov vnow = records[recordhead];
            switch (vnow.movtype)
            {
            case SWAP:
                swap(vnow.i, vnow.j);
                break;
            case MARK:
                mark(vnow.i);
                break;
            default:
                break;
            }
            recordhead++;
        }
    }
    
}

void ContainersView::draw()
{
    int max = *std::max_element(elements.begin(), elements.end());
    for (size_t i = 0; i < elements.size(); i++)  
    {
        ofPushMatrix();
        ofTranslate(glm::vec3(boxsize*(i-(float)elements.size()/2), boxsize*max/float(-2.0), 0.0));
        for (size_t j = 0; j < elements[i]; j++)
        {
            ofTranslate(glm::vec3(0.0, boxsize, 0.0));
            boxlogo.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(boxsize);
            boxlogo.unbind();

            ofNoFill();
		    ofSetColor(marks[i]);
            ofDrawBox(boxsize+0.1);
        }
        ofPopMatrix();
    }
}