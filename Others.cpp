#include"pch.h"
#include"City.h"
#include<vector>

const char* s[2] = { "red","blue" };
const char* ss[5] = { "Dragon","Ninja","Iceman","Lion","Wolf" };

int need[5], order[2], number[2], _attack[5], Warriors_temp[2], now_hour/*当前小时*/;
int creat_order[2][5] = { {2,3,4,1,0},{3,0,1,2,4} };//制造武士的顺序
bool head_num[2], game_over;
City Citys[22];
int City_sum;//城市数
std::vector<int> htime(1000, 0);
HWND hWnd;