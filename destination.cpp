//Author:Alexi Kessler
#ifndef DESTINATION_CPP
#define DESTINATION_CPP

#include "destination.h"

//Constructor
Dest::Dest()
{
	row = col = servTime = 0;
}
//getters and setters
void Dest::setRow(int r)
{
	row = r;
}

int Dest::getRow()
{
	return row;
}

void Dest::setCol(int c)
{
	col = c;
}

int Dest::getCol()
{
	return col;
}

void Dest::setServ(int s)
{
	servTime = s;
}

int Dest::getServ()
{
	return servTime;
}
#endif
