#include"pch.h"
#include <iostream>
#include <string>
#include"head.h"

using namespace std;

int main(double set[])
{
	//��ʼ����ʼ
	int now = 0;//�����set�����е�λ��
	Functions Warcraft; UI picture;
	Warriors::init(set[now++]);//��ʼ������Ԫ
	City_sum = set[now++];//��ʼ��������
	int total_time = set[now++];//��ʼ����ʱ��
	int already_time = 0;//��ʼ����ǰʱ��
	Warcraft.init();//��ʼ������

	for (int i = 0; i <= 4; i++) {
		need[i]=set[now++];//��ʼ������ֵ
	}
	for (int i = 0; i <= 4; i++) {
		_attack[i]=set[now++];//��ʼ��������
	}
	for (int i = 0; i != City_sum + 2; ++i)
		Citys[i].creat(i);//��ʼ������
	//��ʼ������

	while (1)
	{
		picture.init_ui();
		
		++now_hour;//����
		Warcraft.creat();//��ʿ����
		

		already_time += 10;
		if (already_time > total_time) break;
		Warcraft.go_ahead();//������˾�����ǰ��һ��
		if (game_over) break;

		already_time += 10;
		for (int i = 1; i <= City_sum; i++)
			Citys[i].life_hp(10);//ÿ�����в���10������Ԫ

		already_time += 10;
		if (already_time > total_time) break;
		for (int i = 1; i <= City_sum; i++)
			Citys[i].output_hp();//����Ԫ��ȡ��

		already_time += 10;
		if (already_time > total_time) break;
		for (int i = 1; i <= City_sum; i++)
			Citys[i].beat();//����������ʿ�ĳ��з���ս��
		Warcraft.pride();//��ɱ�����˵���ʿ���н���

		already_time += 10;
		if (already_time > total_time) break;
		for (int i = 0; i <= 1; i++)
			printf("%.3d:50 %d elements in %s headquarter\n", now_hour, Warriors::total[i], s[i]);//˾�������ӵ�е�����Ԫ����

		already_time += 10;
		if (already_time > total_time) break;
	}
	return 0;
}