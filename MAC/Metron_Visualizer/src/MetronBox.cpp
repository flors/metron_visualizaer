//
//  MetronBox.cpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 3/8/19.
//

#include "MetronBox.hpp"


MetronBox::MetronBox(){
    
}

void MetronBox::setup(int posX, int posY, int _boxSize, int _boxID){
    
    boxPosX = posX;
    boxPosY = posY;
    boxSize = _boxSize;
    boxID = _boxID;
    
    myStripLeft.setup(0, 10,boxSize+20,boxPosX, boxPosY);
    myStripRight.setup(1, 10,boxSize+20, boxPosX, boxPosY);
    myStripBox.setup(2, boxSize,boxSize, boxPosX, boxPosY);
    
    stick.setup(10,boxSize+20,posX, posY);
    
}

void MetronBox::draw(){
    
    /*ofSetColor(255, 255, 255, 255);
    glPushMatrix();
    glTranslatef(boxPosX, boxPosY,0);
    float auxW = sqrt((boxSize*boxSize) + (boxSize*boxSize)) + boxSize/2.5;
    float auxH = sqrt((boxSize*boxSize) + (boxSize*boxSize)) + boxSize/2.5;
    ofNoFill();
    ofDrawRectangle(-auxW/2, 0+boxSize/10,  auxW , -auxH);
    ofFill();
    glPopMatrix();*/
    
    //stick.draw();
    myStripLeft.draw();
    myStripRight.draw();
    myStripBox.draw();
    
    
}

void MetronBox::update(float lightLeft, float lightRight, float lightCenterLeft, float lightCenterRight){
    stick.update();
    
}

void MetronBox::saveLightValues(float lightLeft, float lightRight, float lightCenterLeft, float lightCenterRight){
    
    if(myStripLeftOn){
        myStripLeft.saveLightBrightness(lightLeft);
    }else{
        myStripLeft.saveLightBrightness(0);
    }
    
    if(myStripRightOn){
        myStripRight.saveLightBrightness(lightRight);
    }else{
        myStripRight.saveLightBrightness(0);
    }
    
    if(myStripBoxOn){
        myStripBox.saveLightBrightness(lightCenterRight);
    }else{
        myStripBox.saveLightBrightness(0);
    }
}

void MetronBox::updateStickAngle(float angle){
    stick.setAngle(angle);
}

bool MetronBox::checkBoundingBox(int x, int y){
    
    if( x < boxPosX + boxSize/2 && x > boxPosX - boxSize/2 && y > boxPosY - boxSize && y < boxPosY){
        cout << "in box!" << endl;
        return true;
    }
    
    return false;
    
}

void MetronBox::callibrateBox(bool callibrate){
   
    if(callibrate){
        myStripLeft.setSelected(true);
        myStripRight.setSelected(true);
        myStripBox.setSelected(true);
    }else{
        myStripLeft.setSelected(false);
        myStripRight.setSelected(false);
        myStripBox.setSelected(false);
    }
   
}



