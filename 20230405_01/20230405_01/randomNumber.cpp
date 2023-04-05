#include<iostream>
#include<ctime>
#include<cstdlib>
#include <vector>
#include<algorithm> //remove 함수 사용

using namespace std;

int main() {
	srand(time(NULL));

	vector<bool> dupleCheck(26, false); // 1~25/  0 사용x
	vector<bool> sameCheck; // 1~25/  0 사용x
	vector<int> comNum = vector<int>();
	vector<int> userNum = vector<int>();
	int rNum = 0;
	int cnt = 0; // 맞춘 갯수
	bool isSame = false; // 입력한 숫자가 같은게 있는지 확인하는 변수

	while(comNum.size() < 6){
		
		rNum = rand() % 25 + 1;

		if(!dupleCheck[rNum]){
			dupleCheck[rNum] = true;
			comNum.push_back(rNum);
		}
	}

	/*cout << "확인용" << endl;
	for (auto i : comNum) {
		cout << i << " ";
	}
	cout << endl;*/

	sameCheck = dupleCheck;
	dupleCheck.assign(26, false);

	cout << "숫자는 1 ~ 25까지 숫자만 입력할 수 있습니다."<<endl;
	while (userNum.size() < 6) {

		cout << userNum.size()+1<<"번째 번호를 입력하세요 : ";
		cin >> rNum;

		// 1~25 사이 숫자가 아닌 경우
		if (rNum < 1 || rNum >25) {
			cout << "숫자는 1 ~ 25까지 숫자만 입력할 수 있습니다." << endl;
			continue;
		}

		//중복 체크
		if (dupleCheck[rNum]) {
			cout << "이미 입력된 숫자입니다. 다시 입력해주세요" << endl;
		}
		else {
			dupleCheck[rNum] = true;
			userNum.push_back(rNum); // << 입력 갯수 확인 용으로 사용 중 입력한 숫자 입력시 활용

			//입력한 숫자 체크 - 같은 숫자 체크한것도 한번 더 체크함
			/*for (auto n : comNum) {
				if (rNum == n) cnt++;				
			}*/

			//체크한것도 여러번 돌기 싫어서 만듬
			if (sameCheck[rNum]) {
				cnt++;
			}
		}
	}

	cout << 7 - cnt << "등" << endl;
}
