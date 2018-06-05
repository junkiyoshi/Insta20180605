#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(200, 0, 25);

	ofTrueTypeFontSettings font_settings("fonts/Kazesawa-Bold.ttf", 50);
	font_settings.antialiased = true;
	font_settings.addRanges(ofAlphabet::Japanese);
	this->font.load(font_settings);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<string> words = {
		u8"‚¨", u8"‚à", u8"‚Ä", u8"‚È", u8"‚µ", 
	};

	for (int x = 0; x < ofGetWidth(); x += 72) {

		for (int y = 60; y < ofGetHeight(); y += 72) {

			int words_index = ofNoise(x * 0.0005, y * 0.0005, ofGetFrameNum() * 0.005) * words.size();
			std::string moji  = words[words_index];
			this->font.drawString(moji, x, y);
		}
	}	
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}