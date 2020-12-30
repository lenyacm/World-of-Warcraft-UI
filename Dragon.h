#pragma once
#ifndef _DRAGON_H_
#define _DRAGON_H_

#include"Warriors.h"

class Dragon : public Warriors
{
private:
public:
	Dragon() {}
	Dragon(int newcolor, int newid, int newtype);
	void happy(int);
};
#endif // !_DRAGON_H_