#include "calculationPlus.h"

void calculationPlus::calculate() {
	double num;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num;

	setResult(getResult() + num);
	cout << "-------------------------------------------------------" << endl;
	cout << "��� : " << getResult() << endl;
	cout << "-------------------------------------------------------" << endl;
}