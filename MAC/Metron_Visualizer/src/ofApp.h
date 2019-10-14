#pragma once

#include "ofMain.h"
#include "MetronController.hpp"
#include "ofxSyphon.h"
#include "ofxDatGui.h"
#include "ofxJSON.h"

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
		void mouseReleased(int x,int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void sendingLimitRight();
        void limitRightChanged(int & limit);
    
        void onButtonEndEvent(ofxDatGuiButtonEvent e);
        void onButtonSendEvent(ofxDatGuiButtonEvent e);
        void onButtonCallibrateEvent(ofxDatGuiButtonEvent e);
        void onSliderEventLeft(ofxDatGuiSliderEvent e);
        void onSliderEventRight(ofxDatGuiSliderEvent e);
        void onMatrixEvent(ofxDatGuiMatrixEvent e);
    
        vector<ofxDatGuiComponent*> components;
        ofxDatGuiSlider* mySliderLeft;
        ofxDatGuiMatrix* metronMatrix;
        ofxDatGuiSlider* mySliderRight;
        ofxDatGuiButton* callibrateBtn;
        int sliderLeftValue;
        int sliderRightValue;
    
    
        ofxJSONElement result;
        int indexMotorSelected;
        int prevMotorSelected;
        
    private:
    //Callibration callibration;
    MetronController metronController;
    //Syphon
    ofTexture tex;
    ofxSyphonServer mainOutputSyphonServer;
    ofxSyphonServer individualTextureSyphonServer;
    ofxSyphonClient mClient;
    
    
    
   
    
    //OSC values sending
    int limitRightValue;
    
};
