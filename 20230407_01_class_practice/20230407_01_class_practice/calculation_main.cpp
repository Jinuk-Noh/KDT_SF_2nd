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

		cout << "연산자를 입력해주세요 : ";
		cin >> oper;

		switch (oper)
		{
		case '+':
			c = new calculationPlus();			
			break;
		case '-':
			c = new calculationMinus();
			break;
		case '*':
			c = new calculationMultiple();
			break;
		case '/':
			c = new calculationDivide();
			break;
		default:
			cout << "잘못된 연산자를 입력하였습니다."<<endl;
			continue;
		}

		c->calculate();

		delete c;

		cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) : ";

		//정해진 값을 입력하지 않은 경우 계속 입력
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
				cout << "잘못된 명령어 입니다. 대소문자 확인 후 다시 입력해주세요 : ";
			}
		}
	}
}