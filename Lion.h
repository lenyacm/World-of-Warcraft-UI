#pragma once
#ifndef _LION_H_
#define _LION_H_

#include"Warriors.h"

class Lion : public Warriors
{
private:
public:
	Lion() {}
	Lion(int newcolor, int newid, int newtype);
	~Lion() {};
	void escape();
};
#endif // !_LION_H_