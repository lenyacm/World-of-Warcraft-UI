#pragma once
#ifndef _WARRIORS_H_
#define _WARRIORS_H_

class Warriors {//武士
public:
	Warriors() = default;
	Warriors(int newcolor, int newid, int newtype);
	void get_hp(int);
	static void init(int life);
	static int total[2];//总生命元
	virtual void twice() {}
	virtual void happy(int) {}
	friend class City;
protected:
	int type;//武士的类型
	int id;//武士的编号
	int hp;//生命值
	int time;//当前小时
	int color;//0为red,1为blue
	int attack;//攻击力
	int kill;
};
#endif // !_WARRIORS_H_