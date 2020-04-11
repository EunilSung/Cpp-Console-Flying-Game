#pragma once
#include <Windows.h>
#include <vector>
#include "ScreenBuffer.h"

using namespace std;
class GameObject {

public:
	COORD location;
	vector<COORD> v;
	bool gameGoing = true;
	bool yesOrNo = false;
	bool result = false;
	bool enemyMoving = true;
	int enemyMovingSize = 0;
	bool rocketLimit = true;

	void inputRocket(COORD playerLocation);
	void bullkeyProcces(COORD playerLocation);
	void inputEnemy();
	void backFrame();
	void player();
	void drawEnemy();
	void moveRocket();
	void keyProcces();
	void drawScore(int score);
	void moveEnemy();
	void gameOver(int score);

};