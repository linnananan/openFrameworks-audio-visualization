#include "par.h"



par::par()
{
	setInitialCondition(0, 0, 0, 0);
	//设置阻力系数
	damping = 0.12f;
}
par::~par()
{
}
//更新位置
void par::update() {
	vel = vel + frc;
	pos = pos + vel;
}
//画粒子
void par::draw(ofColor c) {
	ofPushStyle();
	ofSetColor(c);
    ofCircle(pos.x, pos.y, 2);
	ofPopStyle();
}
//初始化粒子的位置与力
void par::setInitialCondition(float px, float py, float vx, float vy)
{
	pos.set(px, py);
	vel.set(vx, vy);
}
//重设力大小为零
void par::resetForce() {
	frc.set(0, 0);
}
//使力变化
void par::addForce(float x, float y) {
	frc.x = frc.x + x;
	frc.y = frc.y + y;
}
//使传入点对相应点产生排斥力
void par::addRepulsionForce(float x, float y, float radius, float scale) {
	ofVec2f posOfForce;
	posOfForce.set(x, y);
	//使用方法的对象点与传入点的矢量长与标量长
	ofVec2f diff = pos - posOfForce;
	float length = diff.length();
	//限定radius范围内力的作用有效
	bool bAmCloseEnough = true;
	if (radius > 0) {
		if (length > radius) {
			bAmCloseEnough = false;
		}
	}
	if (bAmCloseEnough == true) {
		//在radius范围内的对象粒子，离传入点距离长度越近的粒子，它的粒子系数pct越大（0.0-1.0）
		float pct = 1 - (length / radius); 
		diff.normalize();
		//对象粒子系数pct越大，传入点对该粒子排斥力越大
		frc.x = frc.x + diff.x * scale * pct;
		frc.y = frc.y + diff.y * scale * pct;
	}
}

//使传入点对相应点产生吸引力
void par::addAttractionForce(float x, float y, float radius, float scale) {
	
	ofVec2f posOfForce;
	posOfForce.set(x, y);

	ofVec2f diff = pos - posOfForce;
	float length = diff.length();

	bool bAmCloseEnough = true;
	if (radius > 0) {
		if (length > radius) {
			bAmCloseEnough = false;
		}
	}
	if (bAmCloseEnough == true) {
		float pct = 1 - (length / radius); 
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
		frc.y = frc.y - diff.y * scale * pct;
	}
}
//增加粒子与粒子之间的相互排斥力
void par::addRepulsionForce(par &p, float radius, float scale) {
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x, p.pos.y);
	ofVec2f diff = pos - posOfForce;
	float length = diff.length();

	bool bAmCloseEnough = true;
	if (radius > 0) {
		if (length > radius) {
			bAmCloseEnough = false;
		}
	}
	if (bAmCloseEnough == true) {
		float pct = 1 - (length / radius);  
		diff.normalize();
		frc.x = frc.x + diff.x * scale * pct;
		frc.y = frc.y + diff.y * scale * pct;
		p.frc.x = p.frc.x - diff.x * scale * pct;
		p.frc.y = p.frc.y - diff.y * scale * pct;
	}
}
//增加粒子与粒子之间的相互吸引力
void par::addAttractionForce(par &p, float radius, float scale) {
    ofVec2f posOfForce;
	posOfForce.set(p.pos.x, p.pos.y);
	ofVec2f diff = pos - posOfForce;
	float length = diff.length();

	bool bAmCloseEnough = true;
	if (radius > 0) {
		if (length > radius) {
			bAmCloseEnough = false;
		}
	}
	if (bAmCloseEnough == true) {
		float pct = 1 - (length / radius); 
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
		frc.y = frc.y - diff.y * scale * pct;
		p.frc.x = p.frc.x + diff.x * scale * pct;
		p.frc.y = p.frc.y + diff.y * scale * pct;
	}
}
//增加阻力
void par::addDampingForce() {
	frc.x = frc.x - vel.x * damping;
	frc.y = frc.y - vel.y * damping;
}


