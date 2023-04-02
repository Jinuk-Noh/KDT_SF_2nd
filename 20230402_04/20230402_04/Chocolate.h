#pragma once
#ifndef  __CHOCOLATE_H__
#define __CHOCLOATE_H__
#include "Snack.h"

class Chocolate : public Snack {
public:
	string shape;
	Chocolate(int price, string name, string manufacturer, string shape);

	void show();
};
#endif // ! __CHOCOLATE_H__
