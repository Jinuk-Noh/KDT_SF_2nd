#include "calculationMinus.h"

void calculationMinus::calculate() {
	double num;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num;

	setResult(getResult() - num);
	cout << "-------------------------------------------------------" << endl;
	cout << "��� : " << getResult() << endl;
	cout << "-------------------------------------------------------" << endl;
}