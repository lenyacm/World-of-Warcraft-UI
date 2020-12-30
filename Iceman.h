#pragma once
#ifndef _ICEMAN_H_
#define _ICEMAN_H_

#include"Warriors.h"

class Iceman : public Warriors
{
private:
public:
	Iceman() {}
	Iceman(int newcolor, int newid, int newtype);
};
#endif // !_ICEMAN_H_