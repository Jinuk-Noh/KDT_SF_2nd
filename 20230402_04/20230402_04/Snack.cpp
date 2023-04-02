#include "Snack.h"

string Snack::getName() {
	return name;
}

void Snack::show() {
	cout << "간식 바구니 안에 간식";
};

int Snack::getCnt() {
	return cnt;
}

Snack::Snack(int price, string name, string manufacturer) {
	this->price = price;
	this->name = name;
	this->manufacturer = manufacturer;

	cnt++;
}

Snack:: ~Snack() {

}

int Snack::cnt = 0;