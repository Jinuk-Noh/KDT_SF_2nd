#include "calculationMultiple.h"

void calculationMultiple::calculate() {
	double num;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num;

	this->setResult(getResult() * num);
	cout << "-------------------------------------------------------" << endl;
	cout << "��� : " << getResult() << endl;
	cout << "-------------------------------------------------------" << endl;
}
