#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setTheme(new ofxDatGuiThemeMidnight());

	gui->addButton("Generic Sort");
	gui->addButton("Selection Sort");
	gui->addButton("Insertion Sort");
	gui->addButton("Quick Sort");
	csize = gui->addSlider("Container size", 2, 25, 10);
	// we add this listener before setting up so the initial container size is correct
	gui->onButtonEvent(this, &ofApp::onButtonEvent);
	csize->onSliderEvent(this, &ofApp::containerSizeChanged);
	cview.setElements(csize->getValue(), 1, 15);

	// ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();
    cview.setup();
	// draw the ofBox outlines with some weight
	ofSetLineWidth(10);
}

# pragma region gui

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	if (e.target->getLabel() == "Generic Sort")
	{
		sorting();
	}
	if (e.target->getLabel() == "Selection Sort")
	{
		selectionSort(cview);
	}
	if (e.target->getLabel() == "Insertion Sort")
	{
		selectionSort(cview);
	}
	if (e.target->getLabel() == "Quick Sort")
	{
		quickSort(cview);
	}
}

//--------------------------------------------------------------
void ofApp::containerSizeChanged(ofxDatGuiSliderEvent e){
	cview.clear();
	cview.setElements(e.value, 1, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'r'){
		cview.rw();
	}
	else if(key == 't'){
		cview.rrw();
	}
	else if(key == 'p'){
		cview.play();
	}
	else if(key == ' '){
		cview.pause();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
# pragma endregion gui

# pragma region tick
//--------------------------------------------------------------
void ofApp::update(){
	cview.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	ofEnableDepthTest();
    cam.begin();
	cview.draw();
    cam.end();
	ofDisableDepthTest();
}
# pragma endregion tick

void ofApp::sorting()
{
	quickSort(cview);
}

void ofApp::selectionSort(ContainersView &elements)
{
	for (int i = 0; i < elements.size(); i++)
	{
		int minPos = i;
		for (int j = i+1; j < elements.size(); j++)
		{
			if(elements[j].getHeight() < elements[minPos].getHeight())
			{
				minPos = j;
			}	
		}
		// Swap
		elements.swap(i, minPos);
	}
	
}

void ofApp::insertionSort(ContainersView &elements)
{
	for (int i = 1; i < elements.size(); i++)
	{
		RackBox key = elements[i];
		int j = i-1;
		while( (j >= 0) && (elements[j].getHeight() > key.getHeight()))
		{
			// swap
			elements.swap(j+1, j);
			j--;
		}
		elements[j+1] = key;
	}
	
}

void ofApp::merge(ContainersView left, ContainersView right, ContainersView &elements)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int resultIndex = 0;

	while((leftIndex < left.size()) && (rightIndex < right.size()))
	{
		if (left[leftIndex].getHeight() < right[rightIndex].getHeight())
		{
			elements[resultIndex] = left[leftIndex];
			leftIndex++;
			resultIndex++;
		}
		else
		{
			elements[resultIndex] = right[rightIndex];
			rightIndex++;
			resultIndex++;
		}
	}
	while (leftIndex < left.size())
	{
		elements[resultIndex] = left[leftIndex];
		leftIndex++;
		resultIndex++;
	}
	while (rightIndex < right.size())
	{
		elements[resultIndex] = right[rightIndex];
		rightIndex++;
		resultIndex++;
	}
}

void ofApp::mergeSort(ContainersView &elements)
{
	if (elements.size() <= 1)
	{
		return;
	}
	int midPos = elements.size()/2;
	ContainersView leftHalf;
	for (size_t i = 0; i < midPos; i++)
	{
		leftHalf.push_back(elements[i]);
	}
	ContainersView rightHalf;
	for (size_t i = midPos; i < elements.size(); i++)
	{
		rightHalf.push_back(elements[i]);
	}
	mergeSort(leftHalf);
	mergeSort(rightHalf);
	merge(leftHalf, rightHalf, elements);
}

int ofApp::partition(ContainersView &elements, int low, int high)
{
	RackBox pivot = elements[high];
	int i = low-1;
	for (size_t j = low; j < high; j++)
	{
		if (elements[j].getHeight() < pivot.getHeight())
		{
			i++;
			elements.swap(i, j);
		}	
	}
	elements.swap(i+1, high);
	return i+1;
}

void ofApp::quickSortHelper(ContainersView &elements, int low, int high)
{
	if (low < high)
	{
		int pi = partition(elements, low, high);
		quickSortHelper(elements, low, pi-1);
		quickSortHelper(elements, pi+1, high);
	}
	return;
}

void ofApp::quickSort(ContainersView &elements)
{
	quickSortHelper(elements, 0, elements.size()-1);
}