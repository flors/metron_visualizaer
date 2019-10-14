//
//  MetronBox.hpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 3/8/19.
//

#ifndef MetronBox_hpp
#define MetronBox_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Strip.hpp"
#include "Stick.hpp"

class MetronBox{
    
    public:
    MetronBox();
    void setup(int posX, int posY, int _boxSize, int _boxID);
    void draw();
    void update(float lightLeft, float lightRight, float lightCenterLeft, float lightCenterRight);
    void saveLightValues(float lightLeft, float lightRight, float lightCenterLeft, float lightCenterRight);
    void updateStickAngle(float angle);
    void turnLightsOn();
    void turnLightsOff();
    void addNewBox();
    bool checkBoundingBox(int x, int y);
    void callibrateBox(bool callibrate);
    Stick stick;
    bool myStripBoxOn;
    bool myStripRightOn;
    bool myStripLeftOn;
    
    
    private:
    
    Strip myStripBox;
    Strip myStripRight;
    Strip myStripLeft;
    int boxPosX;
    int boxPosY;
    int boxSize;
    int boxID;
    
};

#endif /* MetronBox_hpp */
