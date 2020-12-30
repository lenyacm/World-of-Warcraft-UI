#include"pch.h"
#include"Wolf.h"

Wolf::Wolf(int newcolor, int newid, int newtype) : Warriors(newcolor, newid, newtype)
{

}

void Wolf::twice()
{
	if (kill > 0 && kill % 2 == 0)
	{
		hp *= 2;
		attack *= 2;
	}
}