#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofBackground(0);
    metronController.setup();
    
    //GUI
    int x = 70;
    int y = 530;
    int p = 200;
    int incY = 10;
    
    ofxDatGuiComponent* component;
    
    metronMatrix = new ofxDatGuiMatrix("Metron boxes", 38, true);
    metronMatrix->setPosition(x, y);
    metronMatrix->setRadioMode(true);
    metronMatrix->onMatrixEvent(this, &ofApp::onMatrixEvent);
    component = metronMatrix;
    components.push_back(component);//components[0]
    
    x += component->getHeight() + p;
    y += incY;
    mySliderLeft = new ofxDatGuiSlider("slider left", 0, 180, 0);
    mySliderLeft->setPosition(x, y);
    mySliderLeft->setPrecision(0);
    mySliderLeft->onSliderEvent(this, &ofApp::onSliderEventLeft);
    component = mySliderLeft;
    components.push_back(component);//components[1]
    
    y += component->getHeight() + incY;
    mySliderRight = new ofxDatGuiSlider("slider right", 0, 180, 0);
    mySliderRight->setPosition(x, y);
    mySliderRight->setPrecision(0);
    mySliderRight->onSliderEvent(this, &ofApp::onSliderEventRight);
    component = mySliderRight;
    components.push_back(component);//components[2]
    
    
    y += component->getHeight() + incY;
    component = new ofxDatGuiButton("Send");
    component->setPosition(x, y);
    component->onButtonEvent(this, &ofApp::onButtonSendEvent);
    components.push_back(component);//components[3]
    
    y += component->getHeight() + incY + 50;
    component = new ofxDatGuiButton("End callibration");
    component->setPosition(270, y);
    component->onButtonEvent(this, &ofApp::onButtonEndEvent);
    components.push_back(component);//components[4]
    
    callibrateBtn = new ofxDatGuiButton("Callibrate");
    callibrateBtn->setPosition(70, 530);
    callibrateBtn->onButtonEvent(this, &ofApp::onButtonCallibrateEvent);
    component = callibrateBtn;
    components.push_back(component);//components[5]
    
    
    indexMotorSelected = -1;
    
    
    
    //Syphon
    mainOutputSyphonServer.setName("Screen Output");
    individualTextureSyphonServer.setName("Texture Output");
    
    mClient.setup();
    
    //using Syphon app Simple Server, found at http://syphon.v002.info/
    mClient.set("","Simple Server");
    tex.allocate(200, 100, GL_RGBA);
    ofSetFrameRate(60);
    
    
    //JSON
    std::string file = "callibration.json";
    
    // Now parse the JSON
    bool parsingSuccessful = result.open(file);
    
}



//--------------------------------------------------------------
void ofApp::update(){
    metronController.receiveOSC();
    metronController.update();
    for(int i=0; i<components.size(); i++) components[i]->update();
}

//--------------------------------------------------------------

void ofApp::draw(){
    
    metronController.draw();
    
    // Syphon Stuff
    //ofSetColor(255, 255, 255, 255);
    mClient.draw(50, 50);
    
    mainOutputSyphonServer.publishScreen();
    
    individualTextureSyphonServer.publishTexture(&tex);
    
    //ofDrawBitmapString("Note this text is not captured by Syphon since it is drawn after publishing.\nYou can use this to hide your GUI for example.", 150,500);
    
    if(indexMotorSelected != -1){
        std::string text;
        int auxMotor = indexMotorSelected;
        text.append("Callibrating motor ");
        text.append(to_string (auxMotor+1));
        ofDrawBitmapString(text, 420,520);
        components[0]->draw();
        for(int i=1; i<components.size()-1; i++) components[i]->draw();
    }else{
        components[components.size()-1]->draw();
    }
    
    for (int i = 0; i<  metronController.metronBoxes.size(); i++) {
        metronController.metronBoxes[i].stick.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

void ofApp::onButtonSendEvent(ofxDatGuiButtonEvent e)
{
    cout << "onButtonEvent: " << e.target->getLabel() << endl;
    result["motors"][indexMotorSelected]["limitLeft"] = to_string(sliderLeftValue);
    result["motors"][indexMotorSelected]["limitRight"] = to_string(sliderRightValue);
    result.save("callibration.json", true);
    
    
    //Send OSC
    ofxOscMessage m1, m2;
    std::string content1, content2;
    
    content1.append("/m");
    content1.append(to_string(indexMotorSelected+1));
    content1.append("_r");
    m1.setAddress(content1);
    m1.addFloatArg(sliderRightValue);
    
    content2.append("/m");
    content2.append(to_string(indexMotorSelected+1));
    content2.append("_l");
    m2.setAddress(content2);
    m2.addFloatArg(sliderLeftValue);
    
    metronController.sender.sendMessage(m1, false);
    metronController.sender.sendMessage(m2, false);
}


void ofApp::onButtonEndEvent(ofxDatGuiButtonEvent e)
{
    cout << "onButtonEndEvent: " << e.target->getLabel() << endl;
    // retrieve a list of the indices of all buttons that are selected //
    //vector<int> metronMatrix->getSelected();
    // deselect everything in the matrix //
    metronController.metronBoxes[prevMotorSelected].callibrateBox(false);
    metronMatrix->clear();
    indexMotorSelected = -1;
    
    callibrateBtn->setEnabled(true);
    
}

void ofApp::onButtonCallibrateEvent(ofxDatGuiButtonEvent e)
{
    cout << "onButtonCallibrateEvent: " << e.target->getLabel() << endl;
    // retrieve a list of the indices of all buttons that are selected //
    //vector<int> metronMatrix->getSelected();
    // deselect everything in the matrix //
    //metronMatrix->clear();
    
    indexMotorSelected = 0;
    
    
    metronController.metronBoxes[indexMotorSelected].callibrateBox(true);
    
    float valueLeft = std::stof(result["motors"][indexMotorSelected]["limitLeft"].asString());
    float valueRight = std::stof(result["motors"][indexMotorSelected]["limitRight"].asString());
    
    mySliderLeft->setValue(valueLeft);
    mySliderRight->setValue(valueRight);
    callibrateBtn->setEnabled(false);
    
    
    prevMotorSelected = indexMotorSelected;
    
}


void ofApp::onSliderEventLeft(ofxDatGuiSliderEvent e)
{
    //cout << "onSliderEvent Left: " << e.value << "::" << e.scale << endl;
    sliderLeftValue = int(e.value);
}

void ofApp::onSliderEventRight(ofxDatGuiSliderEvent e)
{
    //cout << "onSliderEvent Left: " << e.value << "::" << e.scale << endl;
    sliderRightValue = int(e.value);
}

void ofApp::onMatrixEvent(ofxDatGuiMatrixEvent e)
{
    cout << "onMatrixEvent: " << e.child << "::" << e.enabled << endl;
    
    indexMotorSelected = e.child;
    metronController.metronBoxes[prevMotorSelected].callibrateBox(false);
    if (e.enabled == 1){
        
        metronController.metronBoxes[indexMotorSelected].callibrateBox(true);
        
        float valueLeft = std::stof(result["motors"][indexMotorSelected]["limitLeft"].asString());
        float valueRight = std::stof(result["motors"][indexMotorSelected]["limitRight"].asString());
        
        mySliderLeft->setValue(valueLeft);
        mySliderRight->setValue(valueRight);
        
        
    }else {
        metronController.metronBoxes[indexMotorSelected].callibrateBox(false);
        indexMotorSelected = -1;
    }
    
    prevMotorSelected = indexMotorSelected;
    
}



