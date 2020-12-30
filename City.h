#pragma once
#ifndef _CITY_H_
#define _CITY_H_

#include<iostream>
#include"Warriors.h"

class City{
public:
	Warriors* data[2];
	~City()
	{
		for (int i = 0; i <= 1; i++)
			if (data[i] != NULL)
			{
				delete data[i];
				data[i] = NULL;
			}
	}
	int just_beat_win;
	void creat(int);
	void life_hp(int n);
	void output_hp();
	void beat_win(int);
	void beat();
	void go(City*, int);
	bool reach_headquater(int);
	void print_last_go();

private:
	int id;
	int color;
	int hp;
	int last_beat_win;
};

#endif // !_CITY_H_