#pragma once
#ifndef _NINJA_H_
#define _NINJA_H_

#include"Warriors.h"

class Ninja : public Warriors
{
private:
public:
	Ninja() {}
	Ninja(int newcolor, int newid, int newtype);
};
#endif // !_NINJA_H_