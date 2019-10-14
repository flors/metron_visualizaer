//
//  Stick.cpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 3/8/19.
//

#include "Stick.hpp"

Stick::Stick(){
    

}

void Stick::setup(int _w, int _h, int _posX, int _posY){
    stickWidth = _w;
    stickHeight = _h;
    posX = _posX;
    posY = _posY;
    
}

void Stick::draw(){
    
    ofSetColor(150, 150, 170, 255);
    glPushMatrix();
    //glTranslatef(ofGetWidth()/2, ofGetHeight()/2,0);
    glTranslatef(posX, posY,0);
    glRotatef(135+rotation,0,0,1);
    ofDrawRectangle(-stickWidth/2,0, stickWidth, stickHeight);
    glPopMatrix();
    
}

void Stick::setAngle(float _angle){
    angleValue = _angle;
    
}

void Stick::update(){
  rotation = angleValue;
    
}

