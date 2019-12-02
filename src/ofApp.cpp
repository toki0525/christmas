#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(51, 105, 255);
    
    ofSetCircleResolution(60);
    
    soundplayer.load("Xmas.mp3");
    soundplayer.setLoop(true);
    soundplayer.setVolume(1.0);
    soundplayer.play();
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    postglitch.setup(&fbo);
    postglitch.setFx(OFXPOSTGLITCH_NOISE, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_SHAKER, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CONVERGENCE, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_TWIST, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CUTSLIDER, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_GLOW, preseedkey);
    postglitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, preseedkey);
    
    //transalte
    translate_x[0] = 100;
    translate_y[0] = 200;
    translate_x[1] = ofGetWidth() - 400;
    translate_y[1] = 300;
    translate_x[2] = ofGetWidth()/2 - 50;
    translate_y[2] = ofGetHeight()/2 + 150;
    
    //snow
    for(int i =0; i < NUM_OF_SNOW; i++){
        snow_x[i] = ofRandom(0, ofGetWidth());
        snow_y[i] = ofRandom(0, ofGetHeight());
        snow_size[i] = ofRandom(1, 5);
        snow_speed[i] = ofRandom(2, 4);
    }
    
    //tree
    for(int i = 0; i < NUM_OF_TREE; i++){
        tree_x1[i] = 100;
        tree_x2[i] = i*-20;
        tree_x3[i] = i*20 + 200;
        tree_y1[i] = i*110;
        tree_y2[i] = i*100 + 200;
        tree_y3[i] = i*100 + 200;
    }
    
    //light-red
    for(int i = 0; i < NUM_OF_LIGHT; i++){
        light_x_red[i] = ofRandom(0, 200);
        light_y_red[i] = ofRandom(20, 400);
        light_size_red[i] = ofRandom(3, 6);
        light_speed_red[i] = 0.1;
        light_speed_white[i] = 0.1;
    }
    
    //light-white
    for(int i = 0; i < NUM_OF_LIGHT; i++){
        light_x_white[i] = ofRandom(0, 200);
        light_y_white[i] = ofRandom(20, 400);
        light_size_white[i] = ofRandom(3, 6);
        
    }
    
    //santa
    santa_speed = 2;
    
    //ball
    for(int i = 0; i < NUM_OF_BALL1; i++){
        ball_x_yellow[i] = ofRandom(50, ofGetWidth()-50);
        ball_y_yellow[i] = ofRandom(50, ofGetHeight()-50);
        ball_size_yellow[i] = ofRandom(80, 100);
        
        ball_x_blue[i] = ofRandom(50, ofGetWidth()-50);
        ball_y_blue[i] = ofRandom(50, ofGetHeight()-50);
        ball_size_blue[i] = ofRandom(30, 50);
    }
    
    for(int i = 0; i < NUM_OF_BALL2; i++){
        ball_x_pink[i] = ofRandom(50, ofGetWidth()-50);
        ball_y_pink[i] = ofRandom(50, ofGetHeight()-50);
        ball_size_pink[i] = ofRandom(30, 50);
    }
    
    speed_yellow = 1;
    speed_blue = 1;
    speed_pink = 1;
    
    //move_snow
    for(int i = 0; i < NUM_OF_SNOW2; i++){
        move_snow_x[i] = ofRandom(0, 200);
        move_snow_y[i] = ofRandom(0, ofGetHeight());
        move_snow_size[i] = ofRandom(2, 4);
    }
    
//    //present
//    present_x = 100;
//    present_y = 100;
//
//    present_tr_x[0] = present_x;
//    present_tr_x[1] = present_x - 50;
//    present_tr_x[0] = present_x + 50;
//
//    present_tr_y[0] = present_y - 80;
//    present_tr_y[0] = present_y - 150;
//    present_tr_y[0] = present_y - 150;
}

//--------------------------------------------------------------
void ofApp::update(){
    volume = ofSoundGetSpectrum(1);
    
    if(move == true){
        for(int i =0; i < NUM_OF_SNOW; i++){
            snow_y[i] = snow_y[i] + snow_speed[i];
            if(snow_y[i]> ofGetHeight() + 50){
                snow_y[i] = -50;
            }
        }
        
        translate_x[2] = translate_x[2] + santa_speed;
        if(translate_x[2] > ofGetWidth() + 600){
            translate_x[2] = -600;
        }
        
        for(int i = 0; i < NUM_OF_LIGHT; i++){
            light_size_red[i] = light_size_red[i] - light_speed_red[i];
            if(light_size_red[i] < 2){
                light_speed_red[i] = light_speed_red[i] * -1;
            }
            if(light_size_red[i] > 6){
                light_speed_red[i] = light_speed_red[i] * -1;
            }
            
            light_size_white[i] = light_size_white[i] - light_speed_white[i];
            if(light_size_white[i] < 2){
                light_speed_white[i] = light_speed_white[i] * -1;
            }
            if(light_size_white[i] > 6){
                light_speed_white[i] = light_speed_white[i] * -1;
            }
        }
        
        for(int i = 0; i < NUM_OF_BALL1; i++){
            ball_size_yellow[i] = volume[0] * 1300;
            
            ball_size_blue[i] = volume[0] * 1300;
        }
        
        for(int i = 0; i < NUM_OF_BALL2; i++){
            ball_size_pink[i] = volume[0] * 1300;
        }
    }
    
    if(present == true){
        present_y = present_y + 2;
        
        for(int i = 0; i < NUM_OF_PRESENT_TR; i++){
            present_tr_y[i] =  present_tr_y[i] + 2;
        }
    }
    if(effect == true){
        fbo.begin();
        
        ofBackground(51, 105, 255);
           
           //ball
           for(int i = 0; i < NUM_OF_BALL1; i++){
               ofSetColor(255, 215, 82, 150);
               ofDrawCircle(ball_x_yellow[i], ball_y_yellow[i], ball_size_yellow[i]);
               
               ofSetColor(82, 185, 255, 150);
               ofDrawCircle(ball_x_blue[i], ball_y_blue[i], ball_size_blue[i]);
           }
           
           for(int i = 0; i < NUM_OF_BALL2; i++){
               ofSetColor(255, 184, 234, 150);
               ofDrawCircle(ball_x_pink[i], ball_y_pink[i], ball_size_pink[i]);
           }
           
           //tree
           ofPushMatrix();
           ofTranslate(translate_x[0], translate_y[0]);
           
           ofSetColor(92, 62, 59);
           ofDrawRectangle(70, 350, 50, 150);
              
           ofSetColor(55, 143, 59);
           for(int i = 0; i < NUM_OF_TREE; i++){
               ofDrawTriangle(tree_x1[i], tree_y1[i], tree_x2[i], tree_y2[i], tree_x3[i], tree_y3[i]);
           }
           
           //light-red
           for(int i = 0; i < NUM_OF_LIGHT; i++){
               ofSetColor(255, 112, 112);
               ofDrawCircle(light_x_red[i], light_y_red[i], light_size_red[i]);
           }
           
           //light-white
           for(int i = 0; i < NUM_OF_LIGHT; i++){
               ofSetColor(255, 255, 255);
               ofDrawCircle(light_x_white[i], light_y_white[i], light_size_white[i]);
           }
           
           ofPopMatrix();
           
           //Santa
           ofPushMatrix();
           
           ofTranslate(translate_x[2], translate_y[2]);
           ofRotateZDeg(-15);
           
           ofSetColor(255, 253, 120);
           ofDrawRectangle(0, 0, 500, 100);
           ofDrawCircle(0, 50, 50);
           ofDrawCircle(500, 50, 50);
           
           ofSetColor(51, 105, 255);
           ofDrawEllipse(250, 25, 300, 50);
           
           ofSetColor(255, 240, 186);
           ofDrawCircle(250, -155, 40);
           
           ofSetColor(255, 122, 112);
           ofDrawEllipse(250, -45, 100, 200);
           
           ofSetColor(255, 255, 255);
           ofDrawEllipse(250, -130, 80, 30);
           
           ofSetColor(255, 122, 112);
           ofDrawTriangle(250, -280, 210, -190, 290, -190);
           
           ofSetColor(255, 255, 255);
           ofDrawEllipse(250, -190, 80, 30);
           ofDrawCircle(250, -280, 15);
           
           ofPopMatrix();
           
           //tree
           ofPushMatrix();
           ofTranslate(translate_x[1], translate_y[1]);
           
           ofSetColor(92, 62, 59);
           ofDrawRectangle(70, 350, 50, 150);
              
           ofSetColor(55, 143, 59);
           for(int i = 0; i < NUM_OF_TREE; i++){
               ofDrawTriangle(tree_x1[i], tree_y1[i], tree_x2[i], tree_y2[i], tree_x3[i], tree_y3[i]);
           }
           
           //light-red
           for(int i = 0; i < NUM_OF_LIGHT; i++){
               ofSetColor(255, 112, 112);
               ofDrawCircle(light_x_red[i], light_y_red[i], light_size_red[i]);
           }
           
           //light-white
           for(int i = 0; i < NUM_OF_LIGHT; i++){
               ofSetColor(255, 255, 255);
               ofDrawCircle(light_x_white[i], light_y_white[i], light_size_white[i]);
           }
           
           ofPopMatrix();
        
            //present
            if(present == true){
                ofSetColor(255, 184, 234);
                ofDrawCircle(present_x, present_y, 150);
                ofDrawTriangle(present_tr_x[0], present_tr_y[0], present_tr_x[1], present_tr_y[1], present_tr_x[2], present_tr_y[2]);
            }
           
           //snowman
           if(snowman == true){
               ofSetColor(255, 255, 255);
               ofDrawCircle(400, ofGetHeight()/2 + 150, 100);
               ofDrawCircle(400, ofGetHeight()/2 + 300, 120);
               
               ofSetColor(0, 0, 0);
               ofDrawCircle(360, ofGetHeight()/2 + 120, 10);
               ofDrawCircle(440, ofGetHeight()/2 + 120, 10);
               ofDrawCircle(400, ofGetHeight()/2 + 155, 40);
               
               ofSetColor(255, 255, 255);
               ofDrawCircle(400, ofGetHeight()/2 + 150, 40);
               ofDrawRectangle(360, ofGetHeight()/2 + 150, 80, 20);
           }
        
            //move_snow
            if(move_snow == true){
                for(int i = 0; i < NUM_OF_SNOW2; i++){
                    ofSetColor(217, 244, 255);
                    ofDrawCircle(move_snow_x[i], move_snow_y[i], move_snow_size[i]);
                }
            }
        
           //snow (fromt)
           for(int i = 0; i < NUM_OF_SNOW; i++){
               ofSetColor(217, 244, 255);
               ofDrawCircle(snow_x[i], snow_y[i], snow_size[i]);
           }
        
        fbo.end();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    postglitch.generateFx();
    fbo.draw(0, 0);
    
    if(effect == false){
        ofBackground(51, 105, 255);
        
        //ball
        for(int i = 0; i < NUM_OF_BALL1; i++){
            ofSetColor(255, 215, 82, 150);
            ofDrawCircle(ball_x_yellow[i], ball_y_yellow[i], ball_size_yellow[i]);
            
            ofSetColor(82, 185, 255, 150);
            ofDrawCircle(ball_x_blue[i], ball_y_blue[i], ball_size_blue[i]);
        }
        
        for(int i = 0; i < NUM_OF_BALL2; i++){
            ofSetColor(255, 184, 234, 150);
            ofDrawCircle(ball_x_pink[i], ball_y_pink[i], ball_size_pink[i]);
        }
        
        //tree
        ofPushMatrix();
        ofTranslate(translate_x[0], translate_y[0]);
        
        ofSetColor(92, 62, 59);
        ofDrawRectangle(70, 350, 50, 150);
           
        ofSetColor(55, 143, 59);
        for(int i = 0; i < NUM_OF_TREE; i++){
            ofDrawTriangle(tree_x1[i], tree_y1[i], tree_x2[i], tree_y2[i], tree_x3[i], tree_y3[i]);
        }
        
        //light-red
        for(int i = 0; i < NUM_OF_LIGHT; i++){
            ofSetColor(255, 112, 112);
            ofDrawCircle(light_x_red[i], light_y_red[i], light_size_red[i]);
        }
        
        //light-white
        for(int i = 0; i < NUM_OF_LIGHT; i++){
            ofSetColor(255, 255, 255);
            ofDrawCircle(light_x_white[i], light_y_white[i], light_size_white[i]);
        }
        
        ofPopMatrix();
        
        //Santa
        ofPushMatrix();
        
        ofTranslate(translate_x[2], translate_y[2]);
        ofRotateZDeg(-15);
        
        ofSetColor(255, 253, 120);
        ofDrawRectangle(0, 0, 500, 100);
        ofDrawCircle(0, 50, 50);
        ofDrawCircle(500, 50, 50);
        
        ofSetColor(51, 105, 255);
        ofDrawEllipse(250, 25, 300, 50);
        
        ofSetColor(255, 240, 186);
        ofDrawCircle(250, -155, 40);
        
        ofSetColor(255, 122, 112);
        ofDrawEllipse(250, -45, 100, 200);
        
        ofSetColor(255, 255, 255);
        ofDrawEllipse(250, -130, 80, 30);
        
        ofSetColor(255, 122, 112);
        ofDrawTriangle(250, -280, 210, -190, 290, -190);
        
        ofSetColor(255, 255, 255);
        ofDrawEllipse(250, -190, 80, 30);
        ofDrawCircle(250, -280, 15);
        
        ofPopMatrix();
        
        //tree
        ofPushMatrix();
        ofTranslate(translate_x[1], translate_y[1]);
        
        ofSetColor(92, 62, 59);
        ofDrawRectangle(70, 350, 50, 150);
           
        ofSetColor(55, 143, 59);
        for(int i = 0; i < NUM_OF_TREE; i++){
            ofDrawTriangle(tree_x1[i], tree_y1[i], tree_x2[i], tree_y2[i], tree_x3[i], tree_y3[i]);
        }
        
        //light-red
        for(int i = 0; i < NUM_OF_LIGHT; i++){
            ofSetColor(255, 112, 112);
            ofDrawCircle(light_x_red[i], light_y_red[i], light_size_red[i]);
        }
        
        //light-white
        for(int i = 0; i < NUM_OF_LIGHT; i++){
            ofSetColor(255, 255, 255);
            ofDrawCircle(light_x_white[i], light_y_white[i], light_size_white[i]);
        }
        
        ofPopMatrix();
        
        //present
        if(present == true){
            ofSetColor(255, 184, 234);
            ofDrawCircle(present_x, present_y, 150);
            ofDrawTriangle(present_tr_x[0], present_tr_y[0], present_tr_x[1], present_tr_y[1], present_tr_x[2], present_tr_y[2]);
        }
        
        //snowman
        if(snowman == true){
            ofSetColor(255, 255, 255);
            ofDrawCircle(400, ofGetHeight()/2 + 150, 100);
            ofDrawCircle(400, ofGetHeight()/2 + 300, 120);
            
            ofSetColor(0, 0, 0);
            ofDrawCircle(360, ofGetHeight()/2 + 120, 10);
            ofDrawCircle(440, ofGetHeight()/2 + 120, 10);
            ofDrawCircle(400, ofGetHeight()/2 + 155, 40);
            
            ofSetColor(255, 255, 255);
            ofDrawCircle(400, ofGetHeight()/2 + 150, 40);
            ofDrawRectangle(360, ofGetHeight()/2 + 150, 80, 20);
        }
        
        //move_snow
        if(move_snow == true){
            for(int i = 0; i < NUM_OF_SNOW2; i++){
                ofSetColor(217, 244, 255);
                ofDrawCircle(move_snow_x[i], move_snow_y[i], move_snow_size[i]);
            }
        }
        
        //snow (fromt)
        for(int i = 0; i < NUM_OF_SNOW; i++){
            ofSetColor(217, 244, 255);
            ofDrawCircle(snow_x[i], snow_y[i], snow_size[i]);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'q'){
        move = false;
    }
    
    if(key == 'w'){
        snowman = true;
    }
    
    //effect
    if(key == '1'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_NOISE, true);
    }
    
    if(key == '2'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
         postglitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE, true);
    }
    
    if(key == '3'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_SHAKER, true);
    }
    
    if(key == '4'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_CONVERGENCE, true);
    }
    
    if(key == '5'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_TWIST, true);
    }
    
    if(key == '6'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, true);
    }
    
    if(key == '7'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, true);
    }
    
    if(key == '8'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_CUTSLIDER, true);
    }
    
    if(key == '9'){
        effect = true;
        postglitch.setFx(OFXPOSTGLITCH_GLOW, true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'q'){
        move = true;
    }
    
    if(key == 'w'){
        snowman = false;
    }
    
    //effect
    if(key == '1'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_NOISE, false);
    }
    
    if(key == '2'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        postglitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE, false);
    }
    
    if(key == '3'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_SHAKER, false);
    }
    
    if(key == '4'){
        effect = false;
         postglitch.setFx(OFXPOSTGLITCH_CONVERGENCE, false);
    }
    
    if(key == '5'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_TWIST, false);
    }
    
    if(key == '6'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
    }
    
    if(key == '7'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, false);
    }
    
    if(key == '8'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_CUTSLIDER, false);
    }
    
    if(key == '9'){
        effect = false;
        postglitch.setFx(OFXPOSTGLITCH_GLOW, false);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(button == 0){
        move_snow = true;
    }
    
    if(button == 1){
        move_snow = true;
    }
    
    if(button == 2){
        move_snow = true;
    }
    
    for(int i = 0; i < NUM_OF_SNOW2; i++){
        move_snow_x[i] = ofRandom(x, x + 500);
        move_snow_y[i] = ofRandom(y, y + 1000);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    present = true;
    
    present_x = x;
    present_y = y;
    
    present_tr_x[0] = x;
    present_tr_x[1] = x - 120;
    present_tr_x[2] = x + 120;
        
    present_tr_y[0] = y - 130;
    present_tr_y[1] = y - 200;
    present_tr_y[2] = y - 200;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    present = false;
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
