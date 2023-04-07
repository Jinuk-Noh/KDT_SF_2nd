#pragma once

#ifndef __CALCULATION_H__
#define __CALCULATION_H__
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class calculation {
	static double result;

public:
	virtual void calculate();

	static double getResult();

	static void setResult(double num);

	static void resetResult();

	//¼Ò¸êÀÚ
	virtual ~calculation();

	

};
#endif // !__CALCULATION_H__


