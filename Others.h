#pragma once
#ifndef _OTHERS_H_
#define _OTHERS_H_

#include"City.h"
#include"pch.h"

#define DRAGON 0
#define NINJA 1
#define ICEMAN 2
#define LION 3
#define WOLF 4

extern const char* s[2];
extern const char* ss[5];

extern int need[5], order[2], number[2], _attack[5], Warriors_temp[2], now_hour;
extern int creat_order[2][5];
extern bool head_num[2], game_over;
extern City Citys[22];
extern int City_sum;

#endif // !_OTHERS_H_