#pragma once
#ifndef _WARRIORS_H_
#define _WARRIORS_H_

class Warriors {//��ʿ
public:
	Warriors() = default;
	Warriors(int newcolor, int newid, int newtype);
	void get_hp(int);
	static void init(int life);
	static int total[2];//������Ԫ
	virtual void twice() {}
	virtual void happy(int) {}
	friend class City;
protected:
	int type;//��ʿ������
	int id;//��ʿ�ı��
	int hp;//����ֵ
	int time;//��ǰСʱ
	int color;//0Ϊred,1Ϊblue
	int attack;//������
	int kill;
};
#endif // !_WARRIORS_H_