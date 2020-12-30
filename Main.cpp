#include"pch.h"
#include <iostream>
#include <string>
#include"head.h"

using namespace std;

int main(double set[])
{
	//初始化开始
	int now = 0;//标记在set数组中的位置
	Functions Warcraft; UI picture;
	Warriors::init(set[now++]);//初始化生命元
	City_sum = set[now++];//初始化城市数
	int total_time = set[now++];//初始化总时长
	int already_time = 0;//初始化当前时间
	Warcraft.init();//初始化其他

	for (int i = 0; i <= 4; i++) {
		need[i]=set[now++];//初始化生命值
	}
	for (int i = 0; i <= 4; i++) {
		_attack[i]=set[now++];//初始化攻击力
	}
	for (int i = 0; i != City_sum + 2; ++i)
		Citys[i].creat(i);//初始化城市
	//初始化结束

	while (1)
	{
		picture.init_ui();
		
		++now_hour;//整点
		Warcraft.creat();//武士降生
		

		already_time += 10;
		if (already_time > total_time) break;
		Warcraft.go_ahead();//朝敌人司令部方向前进一步
		if (game_over) break;

		already_time += 10;
		for (int i = 1; i <= City_sum; i++)
			Citys[i].life_hp(10);//每个城市产出10个生命元

		already_time += 10;
		if (already_time > total_time) break;
		for (int i = 1; i <= City_sum; i++)
			Citys[i].output_hp();//生命元的取走

		already_time += 10;
		if (already_time > total_time) break;
		for (int i = 1; i <= City_sum; i++)
			Citys[i].beat();//在有两个武士的城市发生战斗
		Warcraft.pride();//对杀死敌人的武士进行奖励

		already_time += 10;
		if (already_time > total_time) break;
		for (int i = 0; i <= 1; i++)
			printf("%.3d:50 %d elements in %s headquarter\n", now_hour, Warriors::total[i], s[i]);//司令部报告它拥有的生命元数量

		already_time += 10;
		if (already_time > total_time) break;
	}
	return 0;
}