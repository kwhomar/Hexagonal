#pragma once
#include "Grid.h"

class Grid_Small :
	public Grid
{

	static const int roz_x = 20, roz_y = 20;
	
public:
	Hex plansza[roz_x][roz_y];
	Grid_Small();
	~Grid_Small();
};

