#pragma once

#ifndef  __SNACK_H__
#define __SNACK_H__

#include<iostream>
using namespace std;

class Snack {
	int price;
	string name;
	string manufacturer;

public:
	static int cnt;
	bool isCandy;
	string getName();
	virtual void show();
	static int getCnt();
	Snack(int price, string name, string manufacturer);
	virtual ~Snack();
};
#endif // ! __SNACK_H__
