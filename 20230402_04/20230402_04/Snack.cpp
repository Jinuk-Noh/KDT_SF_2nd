#include "Snack.h"

string Snack::getName() {
	return name;
}

void Snack::show() {
	cout << "���� �ٱ��� �ȿ� ����";
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