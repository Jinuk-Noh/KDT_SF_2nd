#include <iostream>
#include "calculation.h"
#include "calculationDivIde.h"
#include "calculationMinus.h"
#include "calculationMultiple.h"
#include "calculationPlus.h"

using namespace std;


int main() {
	int inputNum = 0;
	string comm = "";
	bool isRest = true;
	char oper;
	while (comm != "EXIT")
	{
		if (isRest) {
			calculation::resetResult();
			isRest = false;
		}

		calculation* c;

		cout << "�����ڸ� �Է����ּ��� : ";
		cin >> oper;

		switch (oper)
		{
		case '+':
			c = new calculationPlus();
			c->calculate();
			break;
		case '-':
			c = new calculationMinus();
			c->calculate();
			break;
		case '*':
			c = new calculationMultiple();
			c->calculate();
			break;
		case '/':
			c = new calculationDivide();
			c->calculate();
			break;
		default:
			cout << "�߸��� �����ڸ� �Է��Ͽ����ϴ�."<<endl;
			continue;
		}

		cout << "������ ��� �����Ͻðڽ��ϱ�? (Y : ���, AC : �ʱ�ȭ, EXIT : ����) : ";
		//������ ���� �Է����� ���� ��� ��� �Է�
		while (true) {
			cin >> comm;

			if (comm == "AC") {
				isRest = true;
				break;
			}
			else if (comm == "Y" || comm == "EXIT") {
				break;
			}
			else {
				cout << "�߸��� ��ɾ� �Դϴ�. ��ҹ��� Ȯ�� �� �ٽ� �Է����ּ��� : ";
			}
		}
	}
}