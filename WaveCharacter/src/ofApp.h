#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "par.h"
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
		void bChangeCharacter(bool &val);
		void initCanvas();
		void updateParticles();
		void beatSound();
	
	ofParameter<bool> _bChange;//显示字母
    ofParameterGroup _DisplayCharacter;
    ofxPanel _GUI;
    
	vector <par> particles;
	ofTrueTypeFont boneFont;
	ofFbo _Canvas;
	ofPixels _VFPx;
	ofColor color;
	string showC;
    
    //显示白线
	bool showLine;
	int screenw;
	int screenh;

	const int N = 256;	//频率谱划分数
	float spectrum[256];	//频率谱相应存储结构
	float time0 ;		

	ofSoundPlayer sound;
	
};
