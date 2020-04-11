#pragma once
#include <vector>
using namespace std;
class ScreenBuffer
{
public:
	void drawAll(COORD g, COORD p, vector<COORD> e, vector<COORD> r);
};