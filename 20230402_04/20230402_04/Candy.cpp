#include "Candy.h"


	Candy::Candy(int price, string name, string manufacturer, string tasty) :Snack(price, name, manufacturer) {
		this->tasty = tasty;
		isCandy = true;
	}

	void Candy::show() {
		cout << tasty + "¸À »çÅÁ" << endl;
	}