#include "containersView.h"

void ContainersView::setElements(int n, int from, int to)
{
    /* initialize random seed: */
    srand (time(NULL));
    for (int i = 0; i < n; i++)
    {
        push_back(RackBox(rand() % (to-from) + from));
    }
    
}

void ContainersView::swap(int i, int j)
{
    RackBox temp = at(i);
    at(i) = at(j);
    at(j) = temp;
    
    if (recording)
    {
        records.push_back({MOVTYPE::SWAP, i, j});
        recordhead++;
    }
}

void ContainersView::mark(int i)
{
    at(i).setColor(ofColor(255, 0, 0, 128));
    if (recording)
    {
        records.push_back({MOVTYPE::MARK, i, i});
        recordhead++;
    }
}

void ContainersView::unmark(int i)
{
    at(i).setColor(ofColor(0.5, 0.0));
    if (recording)
    {
        records.push_back({MOVTYPE::UNMARK, i, i});
        recordhead++;
    }
}

void ContainersView::setup()
{
    recordhead = 0;
    playing = 0;
    recording = true;
}

void ContainersView::next()
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
        case UNMARK:
            unmark(vnow.i);
            break;
        default:
            break;
        }
        recordhead++;
    }
}

void ContainersView::prev()
{
    if (recordhead > 0)
    {
        vmov vnow = records[recordhead-1];
        switch (vnow.movtype)
        {
        case SWAP:
            swap(vnow.i, vnow.j);
            break;
        case MARK:
            mark(vnow.i);
            break;
        case UNMARK:
            unmark(vnow.i);
            break;
        default:
            break;
        }
        recordhead--;
    }
}
void ContainersView::rrw()
{
    while(recordhead > 0)
    {
        prev();
    }
    
}
void ContainersView::update()
{
    if ((playing > 0) && (ofGetFrameNum() % 30 == 0))
    {
        next();
    }
    if ((playing < 0))
    {
        prev();
    }
    
}

void ContainersView::draw()
{
    RackBox max = *std::max_element(begin(), end(), [](RackBox a, RackBox b)
                                  { return a.getHeight() < b.getHeight(); });
    int boxsize = 50;
    for (size_t i = 0; i < size(); i++)  
    {
        ofPushMatrix();
        ofTranslate(glm::vec3(boxsize * (i - (float)size() / 2), boxsize * max.getHeight() / float(-2.0), 0.0));
        at(i).draw();
        ofPopMatrix();
    }
}