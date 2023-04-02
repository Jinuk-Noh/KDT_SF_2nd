#pragma once

#ifndef __CANDY_H__
#define __CANDY_H__
#include<iostream>
#include "Snack.h"
using namespace std;
class Candy : public Snack {
public:
	string tasty;
	Candy(int price, string name, string manufacturer, string tasty);
	void show();
};
#endif // !__CANDY_H__
