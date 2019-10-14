//
//  Strip.cpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 1/8/19.
//

#include "Strip.hpp"

Strip::Strip(){
    

}

void Strip::setup(int _orientation, int _w, int _h, int _posX, int _posY){
    state = false; //strip state is off
    stripHeight = _h;
    stripWidth = _w;
    posX = _posX;
    posY = _posY;
    selected = false;
    
    
    orientation = _orientation;
    brightness = 255;
    

    
    if(orientation == 0 || orientation == 2){
        angleValue = 135;
    }else if(orientation == 1){
        angleValue = 225;
    }
}


void Strip::draw(){
    
    
    if (!selected){
        ofSetColor(255, 255, 255, brightness);
    }else{
        
        ofSetColor(255, 0, 0, 255);
    }
    glPushMatrix();
    
    //glTranslatef(ofGetWidth()/2, ofGetHeight()/2,0);
    glTranslatef(posX, posY,0);

    if(orientation == 0 || orientation == 1){
        glRotatef(angleValue,0,0,1);
        ofDrawRectangle(-stripWidth/2, -5, stripWidth, stripHeight);
    }else{
        
        glRotatef(135,0,0,1);
        ofDrawRectangle(-stripWidth - (stripWidth/6.6), stripWidth/6.6, stripWidth, stripHeight);
    }
    
    glPopMatrix();
}

void Strip::update(float intensity){
    //cout << "Update strip brightness: " << intensity << "." << endl;
    //brightness = intensity*240;
    //brightness = 255;
}

void Strip::saveLightBrightness(float intensity){
     brightness = intensity*200;
}

void Strip::setSelected(bool state){
    selected = state;
}


