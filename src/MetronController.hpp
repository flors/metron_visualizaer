//
//  MetronController.hpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 3/8/19.
//

#ifndef MetronController_hpp
#define MetronController_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOSC.h"
#include "MetronBox.hpp"


#define PORT_R 12345
#define PORT_S 13001
#define HOST "localhost"

class MetronController{
    
    public:
    MetronController();
    void setup();
    void draw();
    void update();
    void motorsCallibrationOSC();
    void receiveOSC();
    void generateBoxes();
    vector <MetronBox> metronBoxes;
    ofxOscReceiver receive;
    ofxOscSender sender;
    int xSizeMetron;
    int ySizeMetron;
    int totalBoxes;
    
    private:

    float oscValueStick;
    float oscValueLight;
    float oscValueLight0;
    float oscValueLight1;
    float oscValueLight2;
    float oscValueLight3;
  
    int nRows;
    int nColumns;
   
};

#endif /* MetronController_hpp */
