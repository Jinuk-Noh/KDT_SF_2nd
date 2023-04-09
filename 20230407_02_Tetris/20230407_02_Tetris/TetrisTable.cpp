#include "TetrisTable.h"



void TetrisBackup::updateBlock(Block* src, Block& backupSrc) {
	backupSrc.setX(src->getX());
	backupSrc.setY(src->getY());
	backupSrc.setRotationCnt(src->getRotationCnt());

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				backupSrc.setShape(i, j, k, src->getShape(i, j, k));
			}
		}
	}
}

void TetrisBackup::updateTable(vector<vector<int>>& src, vector<vector<int>>& backupTable) {
	backupTable.resize(src.size(), vector<int>(src.size()));
	copy(src.begin(), src.end(), backupTable.begin());
}


TetrisTable::TetrisTable(int x, int y) {
	this->x = x;
	this->y = y;
	blockObj = nullptr;

	for (int i = 0; i < y; i++) {
		vector<int> temp;
		for (int j = 0; j < x; j++) {
			temp.push_back(0);
		}

		this->table.push_back(temp);
	}

	for (int i = 0; i < x; i++) {
		table[0][i] = 1;
		table[y - 1][i] = 1;
	}

	for (int i = 1; i < y - 1; i++) {
		table[i][0] = 1;
		table[i][x - 1] = 1;
	}

	for (int i = 1; i < x - 1; i++) {
		table[y-1][i] = 4;
	}
}

void TetrisTable::DrawGameTable() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (table[i][j] == 1|| table[i][j]==4) printf("■");
			else if (table[i][j] == 2 || table[i][j] == 3) printf("★");
			else printf("  ");
		}
		printf("\n");
	}
}

void TetrisTable::createBlock() {
	srand(time(NULL));

	int select = rand() % 2 + 1;
	if (select == 1) blockObj = new BarBlock();
	else blockObj = new SqureBlock();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int y = j + blockObj->getY();
			int x = i + blockObj->getX();
			table[y][x] = blockObj->getShape(i, j, blockObj->getRotationCnt());
		}
	}
}

void TetrisTable::moveBlock(int key) {
	Block backupBlock;
	vector<vector<int>> backupTbl;

	TetrisBackup::updateBlock(blockObj, backupBlock);
	TetrisBackup::updateTable(table, backupTbl);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int y = j + blockObj->getY();
			int x = i + blockObj->getX();
			if (table[y][x] == 2) {
				table[y][x] = 0;
			}
		}
	}

	if (key == DOWN) blockObj->down();
	else if (key == LEFT) blockObj->left();
	else if (key == RIGHT) blockObj->right();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int y = j + blockObj->getY();
			int x = i + blockObj->getX();
			int bValue = blockObj->getShape(i, j, blockObj->getRotationCnt());

			if (bValue != 2) continue; // 블럭이 아니면 무시
			if (table[y][x] == 0) {
				table[y][x] = bValue;
			}
			else if (table[y][x] == 1) { // 벽에 닿는 경우
				copy(backupTbl.begin(), backupTbl.end(), table.begin());
				blockObj->setX(backupBlock.getX());
				blockObj->setY(backupBlock.getY());
				return; //벽에 닿으면 위동 취소
			}
			else if (table[y][x] == 3) {
				copy(backupTbl.begin(), backupTbl.end(), table.begin());
				blockObj->setX(backupBlock.getX());
				blockObj->setY(backupBlock.getY());
				if (key == DOWN) {
					BuildBlock();
					createBlock();
					return;
				}
			}if (table[y][x] == 4) {
				copy(backupTbl.begin(), backupTbl.end(), table.begin());
				blockObj->setX(backupBlock.getX());
				blockObj->setY(backupBlock.getY());
				if (key == DOWN) {
					BuildBlock();
					createBlock();
					return;
				}
			}
		}
	}
}

void TetrisTable::BuildBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int y = j + blockObj->getY();
			int x = i + blockObj->getX();
			int bValue = blockObj->getShape(i, j, blockObj->getRotationCnt());

			if (bValue != 2) continue;
			table[y][x] = 3;
		}
	}
}


void TetrisTable::RotateBlock() {
	Block backupBlock;
	vector<vector<int>> backupTbl;

	TetrisBackup::updateBlock(blockObj, backupBlock);
	TetrisBackup::updateTable(table, backupTbl);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int y = j + blockObj->getY();
			int x = i + blockObj->getX();
			if (table[y][x] == 2) {
				table[y][x] = 0;
			}
		}
	}

	blockObj->Rotation();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int y = j + blockObj->getY();
			int x = i + blockObj->getX();
			int bValue = blockObj->getShape(i, j, blockObj->getRotationCnt());

			if (bValue != 2) continue; // 블럭이 아니면 무시
			if (table[y][x] == 0) {
				table[y][x] = bValue;
			}
			else if (table[y][x] == 1 || table[y][x] == 4 || table[y][x] == 3) { // 벽에 닿는 경우
				copy(backupTbl.begin(), backupTbl.end(), table.begin());
				blockObj->setRotationCnt(backupBlock.getRotationCnt());
				return; //벽에 닿으면 위동 취소
			}
		}
	}
}


