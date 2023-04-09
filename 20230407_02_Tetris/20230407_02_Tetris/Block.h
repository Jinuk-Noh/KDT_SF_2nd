#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include<iostream>
#include<ctime>


const int barblock[4][4][4] = {
		{
			{0,2,0,0},
			{0,2,0,0},
			{0,2,0,0},
			{0,2,0,0},
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{2,2,2,2},
			{0,0,0,0},
		},
		{
			{0,2,0,0},
			{0,2,0,0},
			{0,2,0,0},
			{0,2,0,0},
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{2,2,2,2},
			{0,0,0,0},
		},
};

const int squreblock[4][4][4] = {
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0},
		},
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0},
		},
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0},
		},
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0},
		},
	};

class Block {
protected:
	int rotationCnt;
	int x;
	int y;
	int shape[4][4][4];

public:
	int getShape(int x, int y, int r) {
		return shape[r][y][x];
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	int getRotationCnt() {
		return rotationCnt;
	}

	void down() {
		y++;
	}

	void left() {
		x--;
	}

	void right() {
		x++;
	}

	void Rotation() {
		this->rotationCnt = (rotationCnt + 1)%4;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	void setRotationCnt(int r) {
		this->rotationCnt = r;
	}

	void setShape(int r, int y, int x, int value) {
		this->shape[r][y][x] = value;
	}
};


class BarBlock : public Block {
public :
	BarBlock(){
		x = 20 / 2 - 3;
		y = 1;
		rotationCnt = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					shape[i][j][k] = barblock[i][j][k];
				}
			}
		}
	}
};

class SqureBlock : public Block {
public:
	SqureBlock() {
		x = 20 / 2 - 3;
		y = 1;
		rotationCnt = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					shape[i][j][k] = squreblock[i][j][k];
				}
			}
		}
	}
};
#endif // !__TETRIS_TABLE_H__