#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#include"TetrisTable.h"
#include"Block.h"


// 참고https://geundung.dev/14
// 참고https://seokjin2.tistory.com/32

using namespace std;

void init() {
	system("mode con cols=100 lines=50 | title 게임제목");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void title_draw() {
	printf("\n\n\n\n"); // 4칸 개행
	printf("			#####    #####    #####     ######    ###    ###	\n");
	printf("			  #      #          #      #     #     #    #		\n");
	printf("			  #      ####       #      ######      #    ####	\n");
	printf("			  #      #          #      #     #     #        #	\n");
	printf("			  #      #####      #      #      #   ###   ####	\n");
	printf("			--------------------------------------------------  \n");
}

void movexy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyConrol() {

	int result = -1;
	int i = _getch();

	if (i == 32) {
		return 32;
	}

	if (i == 224) {
		i = _getch();
		switch (i)
		{
		case 72:
			result = UP;
			break;
		case 80:
			result = DOWN;
			break;
		case 77:
			result = RIGHT;
			break;
		case 75:
			result = LEFT;
			break;
		default:
			result = -1;
			break;
		}
	}

	return result;;
}

int menu_draw() {
	int x = 46;
	int y = 12;

	movexy(x - 2, y);
	printf("> 게임시작");
	movexy(x, y + 1);
	printf("종료");
	printf("\n");

	while (1) {
		int n = keyConrol();

		switch (n) {
		case UP:
			if (y > 12) {
				movexy(x - 2, y);
				printf(" ");
				movexy(x - 2, --y);
				printf(">");
			}
			break;
		case DOWN:
			if (y < 13) {
				movexy(x - 2, y);
				printf(" ");
				movexy(x - 2, ++y);
				printf(">");
			}
			break;
		case 32:
			return y - 12;
			break;
		}
	}
}



//
//void game_draw(int* x, int* y) {
//	system("cls");
//
//	//10x20 (+2, +2)
//	//printf("게임 실행 화면 \n");
//
//	bool isControl = false;
//
//	//그리기
//	for (int h = 0; h < 22; h++) {
//		for (int w = 0; w < 12; w++) {
//			char temp = TetrisTable::map[h][w];
//			if (temp == '0') {
//				printf("  ");
//			}
//			else if (temp == '1' || temp == '4') {
//				printf("■");
//			}
//			else if (temp == '2') {
//				printf("★");
//			}
//		}
//		printf("\n");
//	}
//
//	movexy(0, 0);
//}

void game_loop() {

	int playing = 1;

	TetrisTable tt = TetrisTable(TABLE_X, TABLE_Y);

	system("cls");
	tt.createBlock();
	tt.DrawGameTable();

	float time;
	clock_t start = clock();
	bool isControl = false;
	while (playing) {
		
		time = (float)(clock() - start) / CLOCKS_PER_SEC;
		if (time >= 1.5) {
			tt.moveBlock(DOWN);
			start = clock();
		}

		if (_kbhit()) {
			int key = keyConrol();
			switch (key)
			{
			case UP:
				tt.RotateBlock();
				break;
			default:
				tt.moveBlock(key);
				break;
			}
		}
		movexy(0, 0);
		tt.DrawGameTable();


		/*if (!isControl) {
			table.spawnBlock(&isControl, block, 0);
			y = 1;
		}
		else {

			table.removeBlock(block);

			y++;

			block.setPos(x, y);

			table.moveBlock(x, y, block.getRotationCnt(), block);
		}

 		for (int h = 0; h < 22; h++) {
			for (int w = 0; w < 12; w++) {
				char temp = TetrisTable::map[h][w];
				if (temp == '0') {
					printf("  ");
				}
				else if (temp == '1' || temp == '4') {
					printf("■");
				}
				else if (temp == '2') {
					printf("★");
				}
			}
			printf("\n");
		}


		movexy(0, 0);
		Sleep(1000);*/
	}
}





int main()
{
	init();

	while (1) {
		title_draw();
		int menuCode = menu_draw();

		if (menuCode == 0) {
			game_loop();
		}
		else {
			return 0;
		}

		system("cls");
	}
}

