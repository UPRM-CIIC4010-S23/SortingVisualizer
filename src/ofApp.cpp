#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	// we add this listener before setting up so the initial container size is correct
	csize.addListener(this, &ofApp::containerSizeChanged);
	csort.addListener(this, &ofApp::sorting);

	gui.setup(); // most of the time you don't need a name

	ofTrueTypeFontSettings settings(OF_TTF_MONO, 14);
	gui.loadFont(settings);
	gui.setSize(600, 100);

	gui.add(csize.setup("Container size", 5, 2, 25));
	gui.add(csort.setup("Sorting"));

	bHide = false;

	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	// ofEnableDepthTest();

	// ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();
    cview.setup();
	// draw the ofBox outlines with some weight
	ofSetLineWidth(10);
}

//--------------------------------------------------------------
void ofApp::containerSizeChanged(int &containerSize){
	cview.clear();
	cview.setElements(containerSize, 1, 15);
}

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
	// auto draw?
	// should the gui control hiding?
	if(!bHide){
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

void ofApp::sorting()
{

}