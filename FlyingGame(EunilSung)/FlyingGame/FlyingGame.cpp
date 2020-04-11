#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "ScreenBuffer.h"

int main()
{
	GameObject gameObject{ 0,1 };
	GameObject playerObject{ 25,18 };
	GameObject enemyObject{ 4,1 };
	GameObject rocketObject;
	GameObject scoreObject{ 20,0 };
	CONSOLE_CURSOR_INFO cur_info;
	ScreenBuffer screenBuffer;
	int score = 0;
	bool getOut = false;
	cur_info.dwSize = 1;
	cur_info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
	enemyObject.inputEnemy();
	while (true) {
		playerObject.keyProcces();
		if (playerObject.gameGoing) {
			enemyObject.moveEnemy();
			rocketObject.bullkeyProcces(playerObject.location);
			rocketObject.moveRocket();
			scoreObject.drawScore(score);
			screenBuffer.drawAll(gameObject.location, playerObject.location, enemyObject.v, rocketObject.v);
		}
		else {
			if (playerObject.result) {
				if (!playerObject.yesOrNo) {
					main();
				}
				else {
					return 0;
				}
			}
		}
		if (enemyObject.v.size() == 0) {
			playerObject.gameOver(score);
		}

		for (int h = 0; h < enemyObject.v.size(); h++) {
			if (getOut == true) {
				break;
			}
			for (int k = 0; k < 6; k++) {
				for (int i = 0; i < 6; i++) {
					if (playerObject.location.X + k == enemyObject.v.at(h).X + i && playerObject.location.Y == enemyObject.v.at(h).Y) {
						playerObject.gameOver(score);
					}
				}
			}
			if (enemyObject.v.at(h).Y == 20) {
				playerObject.gameOver(score);
			}
			for (int i = 0; i < rocketObject.v.size(); i++) {
				if (getOut == true) {
					break;
				}
				for (int k = 0; k < 6; k++) {
					if (rocketObject.v.at(i).X == enemyObject.v.at(h).X + k && rocketObject.v.at(i).Y == enemyObject.v.at(h).Y) {
						rocketObject.v.erase(rocketObject.v.begin() + i);
						enemyObject.v.erase(enemyObject.v.begin() + h);
						score++;
						getOut = true;
						break;
					}
				}
			}
		}
		getOut = false;
		Sleep(60);
	}
}
