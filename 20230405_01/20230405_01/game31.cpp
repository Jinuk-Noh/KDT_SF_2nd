#include <iostream>
#include<cstdlib>
#include<ctime> 
#include <vector>

using namespace std;

bool input_user(int* lastNum, string* winner);
void input_computer(int* lastNum, string* winner);

int main()
{
    bool isFirst = false;
    int pickNum = 0;
    int num = 0;
    int* lastNum = &num;
    string w = "";
    string* winner = &w;
    srand(time(NULL));

    while (true)
    {
        cout << "1~2 사이 숫자 입력해주세요 ";
        cin >> pickNum;
        if (pickNum < 1 || pickNum > 2) continue;

        if (rand() % 2 + 1 == pickNum) {
            cout << "사용자가 선입니다." << endl;
            isFirst = true;
        }
        else {
            cout << "컴퓨터가 선입니다." << endl;
            isFirst = false;
        }

        break;
    }


    while (*lastNum < 31) {

        if (isFirst) {
            while (true)
            {
                if (input_user(lastNum, winner)) {
                    break;
                }
            }

            input_computer(lastNum, winner);

            //종료 조건
            if (*lastNum == 30) {
                *winner = "컴퓨터";
            }

            //컴퓨터가 부른 뒤 승자가 나타났는지 확인
            if (*winner != "") break;
        }
        else {
            input_computer(lastNum, winner);

            //종료 조건
            if (*lastNum == 30) {
                *winner = "컴퓨터";
            }

            //컴퓨터가 부른 뒤 승자가 나타났는지 확인
            if (*winner != "") break;

            while (true)
            {
                if (input_user(lastNum, winner)) {
                    break;
                }
            }
        }
    }

    cout << "게임 종료!" + *winner + "의 승리입니다.";
}


bool input_user(int* lastNum, string* winner) {
    int cnt = 0;
    // 사용자 입력
    cout << "개수를 입력하세요 : ";
    cin >> cnt;

    if (cnt < 1 || cnt > 3) {
        cout << "1~3 사이의 수를 입력하세요." << endl;
        return false;
    }

    cout << "사용자가 부른 숫자!" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ++ *lastNum << endl;
        if (*lastNum == 31) {
            *winner = "컴퓨터";
            break;
        }
    }

    cout << endl;

    return true;

    // 사용자 입력 끝
}

void input_computer(int* lastNum, string* winner) {
    int cnt = 0;
    // 컴퓨터 입력
    if (*lastNum == 27) cnt = 3; // 사용자가 31을 부르게 하기
    else if (*lastNum == 28) cnt = 2;
    else if (*lastNum == 29) cnt = 1;
    else cnt = rand() % 3 + 1; // 기본 랜덤

    cout << "컴퓨터가 부른 숫자!" << endl;
    for (int i = 0; i < cnt; i++) {

        cout << ++ * lastNum << endl;

        // 랜덤 상관없이 31이면 끝(사용자 승리 조건)
        if (*lastNum == 31) {
            *winner = "사용자";
            break;
        }
    }

    cout << endl;
    // 컴퓨터 입력 끝
}