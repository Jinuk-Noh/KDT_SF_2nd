#pragma once
#ifndef __TETRIS_TABLE_H__
#define __TETRIS_TABLE_H__

#include "Block.h"
#include <vector>

#define TABLE_X 20
#define TABLE_Y 38

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

using namespace std;


class TetrisBackup {
public:
	static void updateBlock(Block* src, Block& backupSrc);

	static void updateTable(vector<vector<int>>& src, vector<vector<int>>& backupTable);
};

class TetrisTable {
private :
	vector<vector<int>> table;
	Block* blockObj;
public:
	static char map[22][13];
	static char backup[22][13];

	int x;
	int y;
	
	TetrisTable(int x, int y);

	void DrawGameTable();

	void createBlock();

	void moveBlock(int key);

	void RotateBlock();

	void BuildBlock();

	//void createBlock(bool* isControl, Block block, int r) {
	//	if (*isControl) return;

	//	block.setPos(3, 1);

	//	for (int h = 0; h < 4; h++) {
	//		for (int w = 0; w < 4; w++) {
	//			if (block.getShape(w, h, r) == 2)
	//				map[1 + h][3 + w] = '2';
	//		}
	//	}

	//	*isControl = true;
	//};

	//void moveBlock(int x, int y,int r, Block block) {
	//	for (int h = 0; h < 4; h++) {
	//		for (int w = 0; w < 4; w++) {
	//			
	//			if (block.getShape(w,h,r) == 2) {
	//				map[y + h][x + w] = '2';
	//			}
	//			else if (block.getShape(w, h, r) == 0){
	//					map[y + h][x + w] = '0';
	//			}
	//		}
	//	}
	//}

	//void removeBlock(Block block) {
	//	for (int h = 0; h < 4; h++) {
	//		for (int w = 0; w < 4; w++) {
	//				if (block.getShape(w, h, block.getRotationCnt()) == 2)
	//					map[block.getY() + h][block.getX() + w] = '0';
	//		}
	//	}
	//}

	//void updateTable() {

	//}
};
//
//char TetrisTable::map[22][13] = {
//		{"111111111111"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"100000000001"},
//		{"144444444441"},
//};


#endif // !__TETRIS_TABLE_H__
