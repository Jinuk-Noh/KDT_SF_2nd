#include<iostream>
#include<ctime>
#include<cstdlib>
#include <vector>
#include<algorithm> //remove �Լ� ���

using namespace std;

int main() {
	srand(time(NULL));

	vector<bool> dupleCheck(26, false); // 1~25/  0 ���x
	vector<bool> sameCheck; // 1~25/  0 ���x
	vector<int> comNum = vector<int>();
	vector<int> userNum = vector<int>();
	int rNum = 0;
	int cnt = 0; // ���� ����
	bool isSame = false; // �Է��� ���ڰ� ������ �ִ��� Ȯ���ϴ� ����

	while(comNum.size() < 6){
		
		rNum = rand() % 25 + 1;

		if(!dupleCheck[rNum]){
			dupleCheck[rNum] = true;
			comNum.push_back(rNum);
		}
	}

	/*cout << "Ȯ�ο�" << endl;
	for (auto i : comNum) {
		cout << i << " ";
	}
	cout << endl;*/

	sameCheck = dupleCheck;
	dupleCheck.assign(26, false);

	cout << "���ڴ� 1 ~ 25���� ���ڸ� �Է��� �� �ֽ��ϴ�."<<endl;
	while (userNum.size() < 6) {

		cout << userNum.size()+1<<"��° ��ȣ�� �Է��ϼ��� : ";
		cin >> rNum;

		// 1~25 ���� ���ڰ� �ƴ� ���
		if (rNum < 1 || rNum >25) {
			cout << "���ڴ� 1 ~ 25���� ���ڸ� �Է��� �� �ֽ��ϴ�." << endl;
			continue;
		}

		//�ߺ� üũ
		if (dupleCheck[rNum]) {
			cout << "�̹� �Էµ� �����Դϴ�. �ٽ� �Է����ּ���" << endl;
		}
		else {
			dupleCheck[rNum] = true;
			userNum.push_back(rNum); // << �Է� ���� Ȯ�� ������ ��� �� �Է��� ���� �Է½� Ȱ��

			//�Է��� ���� üũ - ���� ���� üũ�Ѱ͵� �ѹ� �� üũ��
			/*for (auto n : comNum) {
				if (rNum == n) cnt++;				
			}*/

			//üũ�Ѱ͵� ������ ���� �Ⱦ ����
			if (sameCheck[rNum]) {
				cnt++;
			}
		}
	}

	cout << 7 - cnt << "��" << endl;
}
