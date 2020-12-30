#include"pch.h"
#include"City.h"
#include"Others.h"

void City::beat_win(int _color)
{
	just_beat_win = _color;
	if (color != _color && last_beat_win == _color)
	{
		color = _color;
		printf("%.3d:40 %s flag raised in City %d\n", now_hour, s[_color], id);
	}
	last_beat_win = _color;
}
void City::life_hp(int n)
{
	hp += n;
}
void City::output_hp()
{
	int turn = -1;
	if (data[0] != NULL && data[1] == NULL) turn = 0;
	if (data[1] != NULL && data[0] == NULL) turn = 1;
	if (turn != -1)
	{
		printf("%.3d:30 %s %s %d earned %d elements for his headquarter\n", now_hour, s[turn], ss[data[turn]->type], data[turn]->id, hp);
		Warriors::total[turn] += hp;
		hp = 0;
	}
}
void City::beat()
{
	int turn, turn2, left_hp = 0;
	just_beat_win = -1;
	if (data[0] == NULL || data[1] == NULL)
		return;
	if (color == 0 || (color == -1 && id % 2 == 1)) { turn = 0; turn2 = 1; }
	else { turn = 1; turn2 = 0; }
	printf("%.3d:40 %s %s %d ", now_hour, s[turn], ss[data[turn]->type], data[turn]->id);
	printf("attacked %s %s %d in City %d with %d elements and force %d\n", s[turn2], ss[data[turn2]->type], data[turn2]->id, id, data[turn]->hp, data[turn]->attack);
	if (data[turn2]->type == LION)
		left_hp = data[turn2]->hp;
	data[turn2]->hp -= data[turn]->attack;
	if (data[turn2]->hp <= 0)
	{
		int nIDEvent = ((data[turn2]->id) - 1) * 13 + (2 * (int)((data[turn2]->type) + 1) + data[turn2]->color + 1);
		htime[nIDEvent] = 0;
		KillTimer(hWnd, nIDEvent);
		printf("%.3d:40 %s %s %d was killed in City %d\n", now_hour, s[data[turn2]->color], ss[data[turn2]->type], data[turn2]->id, id);
		delete data[turn2];
		data[turn2] = NULL;
		data[turn]->kill++;
		data[turn]->twice();
		if (left_hp != 0)
			data[turn]->hp += left_hp;
		data[turn]->happy(id);
		printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n", now_hour, s[turn], ss[data[turn]->type], data[turn]->id, hp);
		Warriors_temp[turn] += hp;
		hp = 0;
		beat_win(turn);
	}
	else
	{
		if (data[turn2]->type != NINJA)
		{
			printf("%.3d:40 %s %s %d fought back against %s %s %d in City %d\n", now_hour, s[turn2],
				ss[data[turn2]->type], data[turn2]->id, s[turn], ss[data[turn]->type], data[turn]->id, id);
			if (data[turn]->type == LION)
				left_hp = data[turn]->hp;
			else left_hp = 0;
			data[turn]->hp -= data[turn2]->attack / 2;
			if (data[turn]->hp <= 0)
			{
				int nIDEvent = ((data[turn]->id) - 1) * 13 + (2 * (int)((data[turn]->type) + 1) + data[turn]->color + 1);
				htime[nIDEvent] = 0;
				KillTimer(hWnd, nIDEvent);
				printf("%.3d:40 %s %s %d was killed in City %d\n", now_hour, s[data[turn]->color], ss[data[turn]->type],data[turn]->id, id);
				delete data[turn];
				data[turn] = NULL;
				if (left_hp != 0)
					data[turn2]->hp += left_hp;
				printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n", now_hour,
					s[turn2], ss[data[turn2]->type], data[turn2]->id, hp);
				Warriors_temp[turn2] += hp;
				hp = 0;
				beat_win(turn2);
			}
			else
			{
				data[turn]->happy(id);
				last_beat_win = -1;
			}
		}
		else
		{
			data[turn]->happy(id);
			last_beat_win = -1;
		}
	}
}
void City::go(City* next, int _color)
{
	data[_color] = next->data[_color];
	if (data[_color] != NULL && data[_color]->type == ICEMAN)
	{
		if ((_color == 0 && id % 2 == 0) || (_color == 1 && (City_sum - id) % 2 == 1))
		{
			data[_color]->hp -= 9;
			if (data[_color]->hp <= 0) data[_color]->hp = 1;
			data[_color]->attack += 20;
		}
	}
}
bool City::reach_headquater(int _color)
{
	if (data[_color] == NULL)
		return false;
	printf("%.3d:10 %s %s %d reached %s headquarter with %d elements and force %d\n", now_hour,
		s[_color], ss[data[_color]->type], data[_color]->id, s[1 - _color], data[_color]->hp, data[_color]->attack);
	if (head_num[_color])
		return true;
	head_num[_color] = true;
	return false;
}
void City::print_last_go()
{
	for (int i = 0; i <= 1; i++)
		if (data[i] != NULL)
			printf("%.3d:10 %s %s %d marched to City %d with %d elements and force %d\n", now_hour,
				s[i], ss[data[i]->type], data[i]->id, id, data[i]->hp, data[i]->attack);
}

void City::creat(int _id)
{
	data[0] = data[1] = NULL;
	id = _id;
	last_beat_win = -1;
	just_beat_win = -1;
	color = -1;
	hp = 0;
}