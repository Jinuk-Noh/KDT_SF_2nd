#include <iostream>
#include <vector>
#include<string>
#include <sstream>
using namespace std;

class Game {
	static vector<string> names;
	static int cnt;
	
public:
	static bool Check(vector<string> intputNames) {
		
		for (int i = 0; i < names.size(); i++) {
			if (names[i] != intputNames[i]) {
				return false;
			}
		}

		names = intputNames;
		cnt++;
		return true;
	}

	static void SetFirstName(string name) {
		names.push_back(name);
	}

	static bool isFirst() {
		if (names.size() == 0) {
			return true;
		}

		return false;
	}

	static int getCnt() {
		return cnt;
	}
};

int Game::cnt = 0;
vector<string> Game::names;


int main() {
	//vector<string> inputNames;
	//string name;

	//while (true) {
	//	cout << "이름 쌓기 ~ 이름 쌓기~: ";
	//	
	//	getline(cin, name);
	//	stringstream ss(name);
	//	//split
	//	while (ss >> name) {
	//		inputNames.push_back(name);
	//	}

	//	if (Game::isFirst()) {
	//		Game::SetFirstName(name);
	//	}

	//	if (Game::Check(inputNames) == false) {
	//		cout << endl<<"게임 종료! " << Game::getCnt() << "명까지 성공했습니다!";
	//		break;
	//	}

	//	inputNames.clear();

		string words;
		getline(cin, words);
		stringstream ss(words); // stream 생성
		while (getline(ss, words, ' ')) {
			cout << words << endl;
		}



}