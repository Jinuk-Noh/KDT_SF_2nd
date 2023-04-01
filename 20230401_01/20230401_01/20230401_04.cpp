#include<iostream>

using namespace std;


class Snack {
	int price;
	string name;
	string manufacturer;

public:
	bool isCandy;
	string getName() {
		return name;
	}

	virtual void show() {
		cout << "간식 바구니 안에 간식";
	};

	Snack(int price, string name, string manufacturer) {
		this->price = price;
		this->name = name;
		this->manufacturer = manufacturer;
	}

	virtual ~Snack() {

	}
};

class Candy : public Snack {
public:
	string tasty;
	Candy(int price, string name, string manufacturer, string tasty) :Snack(price, name, manufacturer) {
		this->tasty = tasty;
		isCandy = true;
	}

	void show() {
		cout << tasty + "맛 " + this->getName() << endl;
	}
};

class Chocolate : public Snack {
public:
	string shape;
	Chocolate(int price, string name, string manufacturer, string shape) :Snack(price, name, manufacturer) {
		this->shape = shape;
		isCandy = false;
	}

	void show() {
		cout << shape + "모양 " + this->getName() << endl;
	}
};


int main() {
	Snack* snackBasket[4] = {new Candy(2000,"목사탕", "사탕나라", "딸기"), new Candy(1500,"롤리팝", "사탕천국","콜라")
	,new Chocolate(500, "다크 초코","초코공장","네모"), new Chocolate(500, "화이트 초코","초코공장","하트")};

	for (auto s : snackBasket) {
		s->show();
	}

	for (auto s : snackBasket) {
		delete s;
	}
}