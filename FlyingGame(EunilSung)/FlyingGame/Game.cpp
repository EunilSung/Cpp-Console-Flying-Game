#include "Game.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


void GameObject::drawScore(int score) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location);
	cout << "Score: " << score;
}
void GameObject::gameOver(int score) {
	location.X = 0;
	location.Y = 11;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location);
	if (score == 8) {
		cout << "YOU WIN!! \n" << "Score: " << score << "\n" << "Play Again? (y/n)";
	}
	else {
		cout << "YOU LOSE!! \n" << "Score: " << score << "\n" << "Play Again? (y/n)";
	}
	gameGoing = false;
}
void GameObject::backFrame() {
	const int SCREEN_WIDTH = 50;
	const int SCREEN_HEIGHT = 20;
	const int SCREEN_PADDING = 0;
	const int FIELD_WIDTH = 49;
	const int FIELD_HEIGHT = 19;
	char frame[SCREEN_WIDTH][SCREEN_HEIGHT];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location);
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int h = 0; h < SCREEN_WIDTH; h++) {

			frame[h][i] = (i == 0 != i < FIELD_HEIGHT && SCREEN_PADDING < h && h < FIELD_WIDTH) ? ' ' : '*';
			cout << frame[h][i];
		}
		cout << "\n";
	}
}

void GameObject::player() {

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location);
	cout << ">-O-<";
}
void GameObject::drawEnemy() {

	for (int i = 0; i < v.size(); i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), v.at(i));
		cout << "E-o-E";
	}
}
void GameObject::moveRocket() {

	for (int i = 0; i < v.size(); i++) {
		if (v.at(i).Y > 2) {
			v.at(i).Y--;
		}
		else {
			v.erase(v.begin() + i);
		}
	}
}
void GameObject::inputEnemy() {
	for (int i = 0; i < 8; i++) {
		v.push_back(location);
	}
	for (int i = 0; i < v.size() / 2; i++) {
		v.at(i).X = location.X + (10 * i);
		v.at(i).Y = location.Y + 1;
	}
	for (int i = v.size() / 2; i < v.size(); i++) {
		v.at(i).X = location.X + 5 + (10 * (i - (v.size() / 2)));
		v.at(i).Y = location.Y + 2;
	}
}
void GameObject::inputRocket(COORD playerLocation) {
	location.X = playerLocation.X + 3;
	location.Y = playerLocation.Y;
	v.push_back(location);
}
void GameObject::keyProcces() {

	if (GetAsyncKeyState(VK_LEFT) & (1 << 15))
	{
		if (location.X > 1)
			location.X--;
	}
	if (GetAsyncKeyState(VK_UP) & (1 << 15))
	{
		if (location.Y > 2)
			location.Y--;
	}
	if (GetAsyncKeyState(VK_RIGHT) & (1 << 15))
	{
		if (location.X < 44)
			location.X++;
	}
	if (GetAsyncKeyState(VK_DOWN) & (1 << 15))
	{
		if (location.Y < 18)
			location.Y++;
	}
	if (!gameGoing) {
		if (GetAsyncKeyState(0x59) & (1 << 15))
		{
			yesOrNo = false;
			result = true;
		}
		if (GetAsyncKeyState(0x4E) & (1 << 15))
		{
			exit(0);
		}
	}

}
void GameObject::bullkeyProcces(COORD playerLocation) {
	if (GetAsyncKeyState(VK_SPACE) & (1 << 15))
	{
		if (rocketLimit) {
			inputRocket(playerLocation);
		}
		rocketLimit = false;
	}
	else {
		rocketLimit = true;
	}
}

void GameObject::moveEnemy() {
	if (enemyMoving) {
		enemyMovingSize++;
		if (enemyMovingSize % 5 == 0) {
			for (int i = 0; i < v.size(); i++) {
				v.at(i).X++;
			}
		}
		if (enemyMovingSize == 20) {
			for (int i = 0; i < v.size(); i++) {
				v.at(i).Y++;
			}
			enemyMoving = false;
		}
	}
	else {
		enemyMovingSize--;
		if (enemyMovingSize % 5 == 0) {
			for (int i = 0; i < v.size(); i++) {
				v.at(i).X--;
			}
		}
		if (enemyMovingSize == 0) {
			for (int i = 0; i < v.size(); i++) {
				v.at(i).Y++;
			}
			enemyMoving = true;
		}
	}
}
