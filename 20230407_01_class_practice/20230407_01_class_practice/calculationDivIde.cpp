#include "calculationDivIde.h"

void calculationDivide:: calculate() {
	double num;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num;

	setResult(getResult() / num);
	cout << "-------------------------------------------------------" << endl;
	cout << "��� : " << getResult() << endl;
	cout << "-------------------------------------------------------" << endl;
}