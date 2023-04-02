#include "Chocolate.h"


	Chocolate::Chocolate(int price, string name, string manufacturer, string shape) :Snack(price, name, manufacturer) {
		this->shape = shape;
		isCandy = false;
	}

	void Chocolate::show() {
		cout << shape + "¸ð¾ç ÃÊÄÝ¸´" << endl;
	}
