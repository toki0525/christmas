#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"

#define NUM_OF_SNOW 100
#define NUM_OF_TRANSLATE 3
#define NUM_OF_TREE 3
#define NUM_OF_LIGHT 14
#define NUM_OF_BALL1 4
#define NUM_OF_BALL2 7
#define NUM_OF_SNOW2 30
#define NUM_OF_PRESENT_TR 3


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer soundplayer;
    float *volume;
    
    //transalte
    float translate_x[NUM_OF_TRANSLATE];
    float translate_y[NUM_OF_TRANSLATE];
    
    float snow_x[NUM_OF_SNOW];
    float snow_y[NUM_OF_SNOW];
    float snow_size[NUM_OF_SNOW];
    float snow_speed[NUM_OF_SNOW];
    
    float tree_x1[NUM_OF_TREE];
    float tree_y1[NUM_OF_TREE];
    float tree_x2[NUM_OF_TREE];
    float tree_y2[NUM_OF_TREE];
    float tree_x3[NUM_OF_TREE];
    float tree_y3[NUM_OF_TREE];
    
    float light_x_red[NUM_OF_LIGHT];
    float light_y_red[NUM_OF_LIGHT];
    float light_size_red[NUM_OF_LIGHT];
    
    float light_x_white[NUM_OF_LIGHT];
    float light_y_white[NUM_OF_LIGHT];
    float light_size_white[NUM_OF_LIGHT];
    float light_speed_red[NUM_OF_LIGHT];
    float light_speed_white[NUM_OF_LIGHT];
    
    float santa_speed;
    
    float ball_x_yellow[NUM_OF_BALL1];
    float ball_y_yellow[NUM_OF_BALL1];
    float ball_size_yellow[NUM_OF_BALL1];
    float speed_yellow;
    
    float ball_x_blue[NUM_OF_BALL1];
    float ball_y_blue[NUM_OF_BALL1];
    float ball_size_blue[NUM_OF_BALL1];
    float speed_blue;
    
    float ball_x_pink[NUM_OF_BALL2];
    float ball_y_pink[NUM_OF_BALL2];
    float ball_size_pink[NUM_OF_BALL2];
    float speed_pink;
    
    float move_snow_x[NUM_OF_SNOW2];
    float move_snow_y[NUM_OF_SNOW2];
    float move_snow_size[NUM_OF_SNOW2];
    
    float present_x;
    float present_y;
    
    float present_tr_x[NUM_OF_PRESENT_TR];
    float present_tr_y[NUM_OF_PRESENT_TR];
    
    //key
    bool move = true;
    bool snowman;
    bool effect;
    
    //mouse
    bool present;
    bool move_snow;
    
    //effect
    ofxPostGlitch postglitch;
    ofFbo fbo;
    bool preseedkey = false;
};
