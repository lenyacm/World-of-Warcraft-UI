#pragma once
#ifndef _WOLF_H_
#define _WOLF_H_

#include"Warriors.h"

class Wolf : public Warriors
{
private:
public:
	Wolf() {}
	Wolf(int newcolor, int newid, int newtype);
	void twice();
};
#endif // !_WOLF_H_