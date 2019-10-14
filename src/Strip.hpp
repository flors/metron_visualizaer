//
//  Strip.hpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 1/8/19.
//

#ifndef Strip_hpp
#define Strip_hpp

#include <stdio.h>
#include "ofMain.h"


class Strip{
    public:
    
    //Methods
    Strip(); //Constructor
    void setup(int _orientation, int _w, int _h, int _posX, int _posY);
    void turnOn();
    void turnOff();
    void draw(); // draw method, this where you'll do the object's drawing
    void update(float intensity);
    void saveLightBrightness(float intensity);
    void setSelected(bool state);

    
    
    private:
    //Variables
    bool state;
    float brightness;
    ofColor color;
    int orientation; //0 = 45 deg to left or 1 = 45 deg to right or 2 = box light
    int angleValue;
    int stripHeight;
    int stripWidth;
    
    int posX;
    int posY;
    bool selected;
    
};
#endif /* Strip_hpp */
