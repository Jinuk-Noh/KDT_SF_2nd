#include "calculationPlus.h"

void calculationPlus::calculate() {
	double num;

	cout << "숫자를 입력해주세요 : ";
	cin >> num;

	setResult(getResult() + num);
	cout << "-------------------------------------------------------" << endl;
	cout << "결과 : " << getResult() << endl;
	cout << "-------------------------------------------------------" << endl;
}