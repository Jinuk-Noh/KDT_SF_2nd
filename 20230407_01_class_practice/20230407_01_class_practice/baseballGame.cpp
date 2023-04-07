#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>


using namespace std;

int main() {
	srand(time(NULL));

	cout << "�߱� ����" << endl<<endl;

	int numLoc[3] = { 0,0,0 }; // �ڸ���
	vector<bool> dupleCheck(10, false); // 1~9�� �ε��� ��� �ε��� 0�� ��� x ��ǻ�Ͱ� �Է��� ���ڰ� �ߺ����� Ȯ���ϰ� ����� �Է°� ���Ͽ� ball, strike ���ǿ� ���
	vector<bool> userDupleCheck(10, false); // 1~9�� �ε��� ��� �ε��� 0�� ��� x, ����ڰ� �Է��� ���� �ߺ�Ȯ��.
	bool isDuple = false;

	int cntStrike = 0;
	int cntBall = 0;
	int cntMiss = 0;

	//��ǻ�� ���� �Է�
	int rNum = 0;
	for (int i = 0; i < 3; i++) {
		rNum = rand() % 9 + 1;

		if (dupleCheck[rNum]) {
			i--; //�ߺ� ������ ��� �Է� Ƚ���� ��ȿ�� �Ѵ�.
		}
		else {
			numLoc[i] = rNum;
			dupleCheck[rNum] = true;
		}
	}

	cout << "��ǻ�� �Է� Ȯ�� �ڵ�" << endl;
	for (auto n : numLoc) {
		cout << n << " ";
	}
	cout << endl;

	//���� ȸ��
	int cntGame = 0;
	//����ڰ� �Է��� ����
	int input[3];
	while (true) {

		//���� ȸ���� ���� �ʱ�ȭ
		cntStrike = 0;
		cntBall = 0;
		cntMiss = 0;
		isDuple = false;
		userDupleCheck.assign(10, false);

		// ����ȸ��
		cntGame++;

		cout << endl << "1 ~ 9 ������ ���� 3���� �Է��Ͻÿ� (�̿��� ���� ����) ";
		
		for (int i = 0; i < 3; i++) {
			
			//cin ���� �ϳ��� ������ �Ҵ�
			cin >> input[i];

			//����ڰ� �Է��ϴ� ���� �ߺ�Ȯ��
			if (userDupleCheck[input[i]] == false) {
				userDupleCheck[input[i]] = true;
			}
			else {
				//���� �Է°� ����
				cin.ignore(3);
				cin.clear();

				isDuple = true;
				cout << "�ߺ��� ���ڴ� �Է��� �� �����ϴ�." << endl;
				break;
			}

			if (input[i] < 1 || input[i] > 9) {
				cout << "������ �����մϴ�." << endl;
				break;
			}

			//�´� ��ȣ�� �ִ� �� Ȯ��
			if (dupleCheck[input[i]] == false) {
				cntMiss++;				
			}
			else {
				//�ڸ����� �´��� Ȯ�� ������ ��Ʈ����ũ ���� +1 �ƴϸ� �� ���� +1
				if (numLoc[i] == input[i]) {
					cntStrike++;
				}
				else {
					cntBall++;
				}
			}
		}

		//�ߺ� �Է��� �Ͽ� ��ȿ�� �ϰ� �ٽ� �Է� ����
		if (isDuple) {
			cntGame = cntGame - 1 < 0 ? 0 : cntGame - 1;
			continue;
		}

		//�ٸ� �Է��� ���� ��� cntStrike + cntBall + cntMiss ���� 3�� �� �� ����
		if (cntStrike + cntBall + cntMiss != 3) break;

		if (cntStrike != 3) {
			cout << "Strike : " << cntStrike << "   Ball : " << cntBall << endl;			
		}
		else {
			cout << cntGame << "�� ���� ������ϴ�." << endl;
			break;
		}
	}
}