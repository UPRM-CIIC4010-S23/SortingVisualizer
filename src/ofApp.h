#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
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

		void onButtonEvent(ofxDatGuiButtonEvent e);
		void containerSizeChanged(ofxDatGuiSliderEvent e);

		void sorting();

		void selectionSort(ContainersView &elements);
		void insertionSort(ContainersView &elements);
		void merge(ContainersView left, ContainersView right, ContainersView &elements);
		void mergeSort(ContainersView &elements);
		int partition(ContainersView &elements, int low, int high);
		void quickSortHelper(ContainersView &elements, int low, int high);
		void quickSort(ContainersView &elements);

		bool bHide;
		ofxDatGuiSlider* csize;
		ofxDatGui* gui;

		ofLight light; // creates a light and enables lighting
		ofEasyCam cam; // add mouse controls for camera movement
		ContainersView cview;
};
