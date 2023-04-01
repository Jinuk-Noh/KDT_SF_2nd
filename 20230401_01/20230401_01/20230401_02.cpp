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

	virtual void show() = 0;

protected:
	Snack(int price, string name, string manufacturer) {
		this->price = price;
		this->name = name;
		this->manufacturer = manufacturer;
	}
};

class Candy : public Snack{
public:
	string tasty;
	Candy(int price, string name, string manufacturer) :Snack(price, name, manufacturer) {
		tasty = "����";
		isCandy = true;
	}
	
	void show() {
		cout << tasty<<endl;
	}
};

class Chocolate : public Snack {
public:
	string shape;
	Chocolate(int price, string name, string manufacturer) :Snack(price, name, manufacturer) {
		shape = "�׸�";
		isCandy = false;
	}

	void show() {
		cout << shape<<endl;
	}


};


int main() {
	//new Ű���� �޸� ���� �� ������ Ȯ��
	/*Snack* snackBasket[4] = {new Candy(2000,"�����", "��������"),new Candy(1500,"�Ѹ���", "����õ��")
	,new Chocolate(500, "��ũ ����","���ڰ���"), new Chocolate(500, "ȭ��Ʈ ����","���ڰ���") };*/


	//Chocolate c;
	//Snack* s = &c;//��ĳ���� - ���� �޸𸮰� �ƴ� -- ���ÿ����� ��� �ּҸ� �б� ���� //new Chocolate(500, "��ũ ����", "���ڰ���"); - ���� �޸�
	//���� �޸� new / delete���� ���� �޸�

	//Chocolate* c1 = (Chocolate*)s; //�ٿ�ĳ����

	/*for (auto s : snackBasket) {
		cout << s->getName()<<" ";
		if (s->isCandy) {
			auto* temp = (Candy*)s;
			temp->show();
			
		}
		else {
			auto* temp = (Chocolate*)s;
			temp->show();
		}
	}

	for (auto s : snackBasket) {
		delete s;
	}*/

	Snack* snackBasket[4] = { new Candy(2000,"�����", "��������"),new Candy(1500,"�Ѹ���", "����õ��")
	,new Chocolate(500, "��ũ ����","���ڰ���"), new Chocolate(500, "ȭ��Ʈ ����","���ڰ���") };

	for (auto s : snackBasket) {
		cout << s->getName()<<" ";
		if (s->isCandy) {
			auto* temp = dynamic_cast<Candy*>(s);
			temp->show();

		}
		else {
			auto* temp = dynamic_cast<Chocolate*>(s);
			temp->show();
		}
	}

	for (auto s : snackBasket) {
		delete s;
	}




	// ���� �ڵ�
	//Snack* snackBasket1 = new Snack[4]{ Candy(2000,"�����", "��������"), Candy(1500,"�Ѹ���", "����õ��")
	//, Chocolate(500, "��ũ ����","���ڰ���"),  Chocolate(500, "ȭ��Ʈ ����","���ڰ���") };

	//for (int i = 0; i < 4; i++) {
	//	snackBasket1[i].getName();

	//	if (snackBasket1[i].isCandy) {
	//		Candy* temp = (Candy*)&snackBasket1[i];
	//		temp->get_show();
	//	}
	//	else {
	//		Chocolate* temp = (Chocolate*)&snackBasket1[i];
	//		temp->show();
	//	}
	//}


	//delete[] snackBasket1;
}