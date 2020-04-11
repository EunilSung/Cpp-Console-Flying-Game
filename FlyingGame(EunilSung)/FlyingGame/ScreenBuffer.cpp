#include<iostream>
#include <Windows.h>
#include "ScreenBuffer.h"
#include <vector>
using namespace std;
void ScreenBuffer::drawAll(COORD g, COORD p, vector<COORD> e, vector<COORD> r) {
	const int SCREEN_WIDTH = 50;
	const int SCREEN_HEIGHT = 20;
	const int SCREEN_PADDING = 0;
	const int FIELD_WIDTH = 49;
	const int FIELD_HEIGHT = 19;
	string frame[SCREEN_WIDTH][SCREEN_HEIGHT];
	string player[5] = { ">","-","0","-","<" };
	string enemy[5] = { "E","-","0","-","E" };
	string rocket[1] = { "!" };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), g);
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int h = 0; h < SCREEN_WIDTH; h++) {
			frame[h][i] = (i == 0 != i < FIELD_HEIGHT && SCREEN_PADDING < h && h < FIELD_WIDTH) ? ' ' : '*';
		}
	}

	for (int i = 0; i < 5; i++) {
		frame[p.X + i][p.Y] = player[i];
	}

	for (int i = 0; i < e.size(); i++) {
		for (int k = 0; k < 5; k++) {
			frame[e.at(i).X + k][e.at(i).Y] = enemy[k];
		}
	}

	for (int i = 0; i < r.size(); i++) {
		frame[r.at(i).X - 1][r.at(i).Y] = rocket[0];
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int h = 0; h < SCREEN_WIDTH; h++) {
			cout << frame[h][i];
		}
		cout << "\n";
	}
}
