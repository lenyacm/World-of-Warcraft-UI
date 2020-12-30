#include"pch.h"
#include<iostream>
#include"Warriors.h"
#include"Others.h"

int  Warriors::total[2] = { 0 };

void Warriors::init(int life)//初始化生命元
{
	total[0] = total[1] = life;
}
Warriors::Warriors(int newcolor, int newid, int newtype)
{
	printf("%.3d:00 %s %s %d born\n", now_hour, s[newcolor], ss[newtype], newid);
	total[newcolor] -= need[newtype];
	id = newid;
	time = now_hour;
	color = newcolor;
	type = newtype;
	hp = need[newtype];
	attack = _attack[newtype];
	kill = 0;
}
void Warriors::get_hp(int a)//增加生命
{
	hp += a;
}