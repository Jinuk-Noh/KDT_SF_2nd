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
		tasty = "달콤";
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
		shape = "네모";
		isCandy = false;
	}

	void show() {
		cout << shape<<endl;
	}


};


int main() {
	//new 키워도 메모리 공간 힙 영역에 확보
	/*Snack* snackBasket[4] = {new Candy(2000,"목사탕", "사탕나라"),new Candy(1500,"롤리팝", "사탕천국")
	,new Chocolate(500, "다크 초코","초코공장"), new Chocolate(500, "화이트 초코","초코공장") };*/


	//Chocolate c;
	//Snack* s = &c;//업캐스팅 - 동적 메모리가 아님 -- 스택영역에 담긴 주소를 읽기 때문 //new Chocolate(500, "다크 초코", "초코공장"); - 동적 메모리
	//동적 메모리 new / delete사용시 동적 메모리

	//Chocolate* c1 = (Chocolate*)s; //다운캐스팅

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

	Snack* snackBasket[4] = { new Candy(2000,"목사탕", "사탕나라"),new Candy(1500,"롤리팝", "사탕천국")
	,new Chocolate(500, "다크 초코","초코공장"), new Chocolate(500, "화이트 초코","초코공장") };

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




	// 망한 코드
	//Snack* snackBasket1 = new Snack[4]{ Candy(2000,"목사탕", "사탕나라"), Candy(1500,"롤리팝", "사탕천국")
	//, Chocolate(500, "다크 초코","초코공장"),  Chocolate(500, "화이트 초코","초코공장") };

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