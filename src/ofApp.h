#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "containersView.h"
#include "RackBox.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void containerSizeChanged(int & containerSize);
		void sorting();

		void selectionSort(std::vector<RackBox> &elements);
		void insertionSort(std::vector<RackBox> &elements);

		bool bHide;
		ofxIntSlider csize;
		ofxButton csort;
		ofxPanel gui;

		ofLight light; // creates a light and enables lighting
		ofEasyCam cam; // add mouse controls for camera movement
		ContainersView cview;
};
