//
//  Stick.hpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 3/8/19.
//

#ifndef Stick_hpp
#define Stick_hpp

#include <stdio.h>
#include "ofMain.h"

class Stick{
    public:
    Stick(); //Constructor
    void setup(int _w, int _h, int _posX, int _posY_);
    void draw();
    void update();
    void setAngle(float _angle);
    
    
    private:
    int stickWidth;
    int stickHeight;
    float rotation;
    float angleValue;
    int posX;
    int posY;
    
    
};

#endif /* Stick_hpp */
