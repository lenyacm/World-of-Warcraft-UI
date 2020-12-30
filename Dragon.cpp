#include"pch.h"
#include<iostream>
#include"Dragon.h"
#include"Others.h"

Dragon::Dragon(int newcolor, int newid, int newtype) :Warriors(newcolor, newid, newtype)
{

}
void Dragon::happy(int _id)
{
	printf("%.3d:40 %s Dragon %d yelled in City %d\n", now_hour, s[color], id, _id);
}