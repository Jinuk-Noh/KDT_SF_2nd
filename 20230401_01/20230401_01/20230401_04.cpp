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
		cout << "���� �ٱ��� �ȿ� ����";
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
		cout << tasty + "�� " + this->getName() << endl;
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
		cout << shape + "��� " + this->getName() << endl;
	}
};


int main() {
	Snack* snackBasket[4] = {new Candy(2000,"�����", "��������", "����"), new Candy(1500,"�Ѹ���", "����õ��","�ݶ�")
	,new Chocolate(500, "��ũ ����","���ڰ���","�׸�"), new Chocolate(500, "ȭ��Ʈ ����","���ڰ���","��Ʈ")};

	for (auto s : snackBasket) {
		s->show();
	}

	for (auto s : snackBasket) {
		delete s;
	}
}