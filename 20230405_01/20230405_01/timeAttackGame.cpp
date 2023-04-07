#include <iostream>
#include<cstdlib>
#include<ctime> 
#include <vector>

using namespace std;

bool checkDuple(string* inputWord, vector<vector<string>>* lstWords);

int main() {

	//시간 측정
	clock_t startTime = clock();
	//clock_t endTime = clock();
	//cout << "걸린 시간 : " << (endTime - startTime) / CLOCKS_PER_SEC << endl;

	string inputWords = "";
	string inputWord = "";
	int cnt = 0;
	//아스키 코드 순서97 ~ 122 - a ~ z  / 97 -96 = 1 ~ 122 -96 = 26
	vector<vector<string>> lstWords(27); //시작하는 단어들만 중복 체크함 0 사용 안함

	while (true) {

		cout << "다음 단어를 입력하세요 : ";
		cin >> inputWord;

		if (inputWords != "" && inputWord[0] != inputWords[inputWords.size() - 1]) {
			cout << "잘못된 입력니다." << endl;
			continue;
		}

		if (checkDuple(&inputWord, &lstWords)) {
			cout << "중복된 단어입니다. "<<endl;
			continue;
		}

		if ((clock() - startTime) / CLOCKS_PER_SEC >= 30) {
			cout << "타임 오버!" << endl;
			cout << "총 입력한 단어 갯수 : " << cnt << endl;
			break;
		}
		else {
			cnt++;
			if (inputWords != "") {
				inputWords = inputWords+"->" + inputWord;
			}
			else {
				inputWords += inputWord;
			}

			cout << inputWords << endl;
		}
	}
}

bool checkDuple(string *inputWord, vector<vector<string>>* lstWords) {

	string word = *inputWord;
	char lastChar = word[word.size() - 1];

	for (string str : (*lstWords)[lastChar - 96]) {
		if (word == str) return true; // 중복 발견
	}

	(*lstWords)[lastChar - 96].push_back(word);

	return false;
}