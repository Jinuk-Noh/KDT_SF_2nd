#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>


using namespace std;

int main() {
	srand(time(NULL));

	cout << "야구 게임" << endl<<endl;

	int numLoc[3] = { 0,0,0 }; // 자릿수
	vector<bool> dupleCheck(10, false); // 1~9를 인덱싱 사용 인덱스 0은 사용 x 컴퓨터가 입력한 숫자가 중복인지 확인하고 사용자 입력과 비교하여 ball, strike 조건에 사용
	vector<bool> userDupleCheck(10, false); // 1~9를 인덱싱 사용 인덱스 0은 사용 x, 사용자가 입력한 값을 중복확인.
	bool isDuple = false;

	int cntStrike = 0;
	int cntBall = 0;
	int cntMiss = 0;

	//컴퓨터 숫자 입력
	int rNum = 0;
	for (int i = 0; i < 3; i++) {
		rNum = rand() % 9 + 1;

		if (dupleCheck[rNum]) {
			i--; //중복 숫자일 경우 입력 횟수를 무효로 한다.
		}
		else {
			numLoc[i] = rNum;
			dupleCheck[rNum] = true;
		}
	}

	cout << "컴퓨터 입력 확인 코드" << endl;
	for (auto n : numLoc) {
		cout << n << " ";
	}
	cout << endl;

	//게임 회차
	int cntGame = 0;
	//사용자가 입력한 숫자
	int input[3];
	while (true) {

		//다음 회차를 위한 초기화
		cntStrike = 0;
		cntBall = 0;
		cntMiss = 0;
		isDuple = false;
		userDupleCheck.assign(10, false);

		// 게임회차
		cntGame++;

		cout << endl << "1 ~ 9 사이의 숫자 3개를 입력하시오 (이외의 숫자 종료) ";
		
		for (int i = 0; i < 3; i++) {
			
			//cin 에서 하나씩 변수에 할당
			cin >> input[i];

			//사용자가 입력하는 숫자 중복확인
			if (userDupleCheck[input[i]] == false) {
				userDupleCheck[input[i]] = true;
			}
			else {
				//남은 입력값 비우기
				cin.ignore(3);
				cin.clear();

				isDuple = true;
				cout << "중복한 숫자는 입력할 수 없습니다." << endl;
				break;
			}

			if (input[i] < 1 || input[i] > 9) {
				cout << "게임을 종료합니다." << endl;
				break;
			}

			//맞는 번호가 있는 지 확인
			if (dupleCheck[input[i]] == false) {
				cntMiss++;				
			}
			else {
				//자릿수가 맞는지 확인 맞으면 스트라이크 갯수 +1 아니면 볼 갯수 +1
				if (numLoc[i] == input[i]) {
					cntStrike++;
				}
				else {
					cntBall++;
				}
			}
		}

		//중복 입력을 하여 무효로 하고 다시 입력 받음
		if (isDuple) {
			cntGame = cntGame - 1 < 0 ? 0 : cntGame - 1;
			continue;
		}

		//다른 입력을 받은 경우 cntStrike + cntBall + cntMiss 값이 3이 될 수 없음
		if (cntStrike + cntBall + cntMiss != 3) break;

		if (cntStrike != 3) {
			cout << "Strike : " << cntStrike << "   Ball : " << cntBall << endl;			
		}
		else {
			cout << cntGame << "번 만에 맞췄습니다." << endl;
			break;
		}
	}
}