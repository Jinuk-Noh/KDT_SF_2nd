#include "calculation.h"

void calculation:: calculate() {
	cout << "-------------------------------------------------------" << endl;
	cout << "��� : " << getResult() << endl;
	cout << "-------------------------------------------------------" << endl;
}

double calculation::getResult() {
	return result;
}

void calculation::setResult(double num) {
	result = num;
}

void calculation::resetResult() {
	double num;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num;
		
	result = num;
}

//�Ҹ���
calculation::~calculation() {

}

double calculation::result = 0;