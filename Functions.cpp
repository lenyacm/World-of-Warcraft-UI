#include"pch.h"
#include"head.h"

void Functions::init()
{
	game_over = false;//游戏未结束
	now_hour = -1;//当前小时
	number[0] = number[1] = 0;//标记编号
	order[0] = order[1] = 0;//制造顺序
	head_num[0] = head_num[1] = false;
}

void Functions::creat()
{
	for (int i = 0; i != 2; ++i)
	{
		if (Warriors::total[i] >= need[creat_order[i][order[i]]])//生命元足以制造某武士
		{
			Warriors* temp;//要实例化的对象
			number[i]++;
			switch (creat_order[i][order[i]])
			{
			case 0:
				temp = new Dragon(i, number[i], creat_order[i][order[i]]);
				break;
			case 1:
				temp = new Ninja(i, number[i], creat_order[i][order[i]]);
				break;
			case 2:
				temp = new Iceman(i, number[i], creat_order[i][order[i]]);
				break;
			case 3:
				temp = new Lion(i, number[i], creat_order[i][order[i]]);
				break;
			case 4:
				temp = new Wolf(i, number[i], creat_order[i][order[i]]);
				break;
			default:
				temp = new Warriors(i, number[i], creat_order[i][order[i]]);
			}
			if (i == 0)
				Citys[0].data[0] = temp;
			else
				Citys[City_sum + 1].data[1] = temp;
			order[i] = (order[i] + 1) % 5;
		}
	}
}
void Functions::go_ahead()
{
	for (int i = City_sum + 1; i >= 1; i--)
		Citys[i].go(&Citys[i - 1], 0);
	for (int i = 0; i <= City_sum; i++)
		Citys[i].go(&Citys[i + 1], 1);
	Citys[0].data[0] = NULL;
	Citys[City_sum + 1].data[1] = NULL;
	if (Citys[0].reach_headquater(1))
	{
		printf("%.3d:10 red headquarter was taken\n", now_hour);
		game_over = true;
	}
	for (int i = 1; i <= City_sum; i++)
		Citys[i].print_last_go();
	if (Citys[City_sum + 1].reach_headquater(0))
	{
		printf("%.3d:10 blue headquarter was taken\n", now_hour);
		game_over = true;
	}
}
void Functions::pride()
{
	for (int i = 1; i != City_sum+1; ++i)
	{
		if (Warriors::total[1] < 8)
			break;
		if (Citys[i].just_beat_win == 1)
		{
			Citys[i].data[1]->get_hp(8);
			Warriors::total[1] -= 8;
		}
	}
	for (int i = City_sum; i != 0; --i)
	{
		if (Warriors::total[0] < 8)
			break;
		if (Citys[i].just_beat_win == 0)
		{
			Citys[i].data[0]->get_hp(8);
			Warriors::total[0] -= 8;
		}
	}
	for (int i = 0; i != 2; ++i)
	{
		Warriors::total[i] += Warriors_temp[i];
		Warriors_temp[i] = 0;
	}
}