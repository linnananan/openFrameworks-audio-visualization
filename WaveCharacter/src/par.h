#pragma once
#include "ofMain.h"
class par
{
public:
	par();
	
	virtual ~par();

	ofVec2f pos;//表示粒子位置
	ofVec2f vel;//表示粒子移动速度变化
	ofVec2f frc;//表示力的变化
	//阻力系数
	float damping;
	//初始化粒子的位置与力
	void setInitialCondition(float px, float py, float vx, float vy);
	void update();
	//显示粒子
	void draw(ofColor c);
	void resetForce();//重设力大小为零
	void addForce(float x, float y);//使力变化
	//使传入点对相应点产生排斥力
	void addRepulsionForce(float x, float y, float radius, float scale);
	//使传入点对相应点产生吸引力
	void addAttractionForce(float x, float y, float radius, float scale);
	//增加粒子与粒子之间的相互排斥力
	void addRepulsionForce(par &p, float radius, float scale);
	//增加粒子与粒子之间的相互吸引力
	void addAttractionForce(par &p, float radius, float scale);
	//增加阻力
	void addDampingForce();


};

