//
//  MetronController.cpp
//  Metron_Visualizer
//
//  Created by Flor Salatino on 3/8/19.
//

#include "MetronController.hpp"

MetronController::MetronController(){
    
}

void MetronController::setup(){
    
    receive.setup(PORT_R);
    sender.setup(HOST, PORT_S);
    //metronBox.setup(ofGetWidth()/2, ofGetHeight()/2);
    int posXAux = 75;
    int posYAux = 150;
    int id = 1;
    
    MetronBox tempBox;
    for(int columns = 0; columns < 7; columns++ ){
        //Draw column of three boxes
        for (int i = 1; i<4; i++) {
            MetronBox tempBox;
            tempBox.setup(posXAux, i*posYAux, 80, id);
            metronBoxes.push_back(tempBox);
            id++;
        }
        
        //Draw column of two boxes
        //Move to right and down
        posXAux += 75;//154
        posYAux = 225;
        
        //Caja 4
        id++;
        tempBox.setup(posXAux, posYAux, 80, id);
        metronBoxes.push_back(tempBox);
        
        //Caja 5
        id++;
        posYAux = 375;
        tempBox.setup(posXAux, posYAux, 80, id);
        metronBoxes.push_back(tempBox);
        
        //Move right and up
        posXAux += 75;
        posYAux = 150;
        
        id++;
    }
    
    //Draw last 3 boxes
    //posXAux += 75;
    posYAux = 150;
    id++;
    for (int i = 1; i<4; i++) {
        tempBox.setup(posXAux,i*posYAux, 80, id);
        metronBoxes.push_back(tempBox);
        id++;
    }
}

void MetronController::receiveOSC(){
    
    while ( receive.hasWaitingMessages() )
    {
        ofxOscMessage m;
        receive.getNextMessage( &m );
        
        if(m.getAddress() ==  "/laterales"){
          cout << "Reveiving OSC: " << m.getArgAsFloat(0)<< "." << endl;
            
            
            for (int i = 0; i< metronBoxes.size(); i++) {
                if (m.getArgAsFloat(0) == 1){
                    metronBoxes[i].myStripLeftOn = true;
                    metronBoxes[i].myStripRightOn = true;
                }else{
                    metronBoxes[i].myStripLeftOn = false;
                    metronBoxes[i].myStripRightOn = false;
                }
                
            }
            
        }
        
        if(m.getAddress() ==  "/interior"){
            cout << "Reveiving OSC interior: " << m.getArgAsFloat(0)<< "." << endl;
            
            
            for (int i = 0; i< metronBoxes.size(); i++) {
                if (m.getArgAsFloat(0) == 1){
                    metronBoxes[i].myStripBoxOn = true;
                   
                }else{
                    metronBoxes[i].myStripBoxOn = false;
                    
                }
                
            }
            
        }
        
        if(m.getAddress() ==  "/motores"){
            //oscValueStick = m.getArgAsFloat(1);
            // cout << "Reveiving OSC: " << oscValue << "." << endl;
            for (int i = 0; i< metronBoxes.size(); i++) {
                metronBoxes[i].updateStickAngle( m.getArgAsFloat(i+1));
            }
            
            
        }
        
        if(m.getAddress() == "/caja1"){
            metronBoxes[0].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja2"){
            metronBoxes[1].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja3"){
            metronBoxes[2].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja4"){
            metronBoxes[3].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        
        if(m.getAddress() == "/caja5"){
            metronBoxes[4].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja6"){
            metronBoxes[5].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja7"){
            metronBoxes[6].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja8"){
            metronBoxes[7].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja9"){
            metronBoxes[8].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja10"){
            metronBoxes[9].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja11"){
            metronBoxes[10].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja12"){
            metronBoxes[11].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja13"){
            metronBoxes[12].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja14"){
            metronBoxes[13].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja15"){
            metronBoxes[14].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja16"){
            metronBoxes[15].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja17"){
            metronBoxes[16].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja18"){
            metronBoxes[17].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja19"){
            metronBoxes[18].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja20"){
            metronBoxes[19].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja21"){
            metronBoxes[20].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja22"){
            metronBoxes[21].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja23"){
            metronBoxes[22].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja24"){
            metronBoxes[23].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja25"){
            metronBoxes[24].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja26"){
            metronBoxes[25].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja27"){
            metronBoxes[26].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja28"){
            metronBoxes[27].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja29"){
            metronBoxes[28].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja30"){
            metronBoxes[29].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja31"){
            metronBoxes[30].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja32"){
            metronBoxes[31].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja33"){
            metronBoxes[32].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja34"){
            metronBoxes[33].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja35"){
            metronBoxes[34].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja36"){
            metronBoxes[35].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja37"){
            metronBoxes[36].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
        if(m.getAddress() == "/caja38"){
            metronBoxes[37].saveLightValues( m.getArgAsFloat(1), m.getArgAsFloat(0), m.getArgAsFloat(3),m.getArgAsFloat(2));
        }
    }
}




void MetronController::update(){
    for (int i = 0; i< metronBoxes.size(); i++) {
        metronBoxes[i].update(oscValueLight1, oscValueLight0, oscValueLight3,oscValueLight2);
    }
}

void MetronController::draw(){
     for (int i = 0; i<  metronBoxes.size(); i++) {
         metronBoxes[i].draw();
     }
}


