#pragma once
#ifndef _OTHERS_H_
#define _OTHERS_H_

#include"City.h"
#include"head.h"
#include<vector>

#define DRAGON 0
#define NINJA 1
#define ICEMAN 2
#define LION 3
#define WOLF 4
#define PERIOD 4

extern std::vector<int> htime;

extern const char* s[2];
extern const char* ss[5];

extern int need[5], order[2], number[2], _attack[5], Warriors_temp[2], now_hour;
extern int creat_order[2][5];
extern bool head_num[2], game_over;
extern City Citys[22];
extern int City_sum;

extern IMAGE i_city;
extern IMAGE i_home0, i_dragon0, i_iceman0, i_lion0, i_ninja0, i_wolf0;
extern IMAGE i_home1, i_dragon1, i_iceman1, i_lion1, i_ninja1, i_wolf1;

extern HWND hWnd;

#endif // !_OTHERS_H_