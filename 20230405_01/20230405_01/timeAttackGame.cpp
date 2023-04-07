#include <iostream>
#include<cstdlib>
#include<ctime> 
#include <vector>

using namespace std;

bool checkDuple(string* inputWord, vector<vector<string>>* lstWords);

int main() {

	//�ð� ����
	clock_t startTime = clock();
	//clock_t endTime = clock();
	//cout << "�ɸ� �ð� : " << (endTime - startTime) / CLOCKS_PER_SEC << endl;

	string inputWords = "";
	string inputWord = "";
	int cnt = 0;
	//�ƽ�Ű �ڵ� ����97 ~ 122 - a ~ z  / 97 -96 = 1 ~ 122 -96 = 26
	vector<vector<string>> lstWords(27); //�����ϴ� �ܾ�鸸 �ߺ� üũ�� 0 ��� ����

	while (true) {

		cout << "���� �ܾ �Է��ϼ��� : ";
		cin >> inputWord;

		if (inputWords != "" && inputWord[0] != inputWords[inputWords.size() - 1]) {
			cout << "�߸��� �Է´ϴ�." << endl;
			continue;
		}

		if (checkDuple(&inputWord, &lstWords)) {
			cout << "�ߺ��� �ܾ��Դϴ�. "<<endl;
			continue;
		}

		if ((clock() - startTime) / CLOCKS_PER_SEC >= 30) {
			cout << "Ÿ�� ����!" << endl;
			cout << "�� �Է��� �ܾ� ���� : " << cnt << endl;
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
		if (word == str) return true; // �ߺ� �߰�
	}

	(*lstWords)[lastChar - 96].push_back(word);

	return false;
}