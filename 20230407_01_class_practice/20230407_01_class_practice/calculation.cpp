#include "calculation.h"

void calculation:: calculate() {
	cout << "-------------------------------------------------------" << endl;
	cout << "결과 : " << getResult() << endl;
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

	cout << "숫자를 입력해주세요 : ";
	cin >> num;
		
	result = num;
}

//소멸자
calculation::~calculation() {

}

double calculation::result = 0;