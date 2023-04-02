#include <iostream>
#include <vector>
#include "test.h";
using namespace std;


//
//class Person {
//public:
//    static int static_var; // 초기화 필요
//
//    string name;
//
//    static void static_method() {
//        //일반 멤버 사용 불가
//        //name = "김씨"; <<오류 발생
//        
//        static_var = 0;
//    }
//
//    void sleep() {
//        //static 멤버 사용가능
//        static_var = 1;
//    }
//};
//
//int Person::static_var = 0; // 초기화 방법

class Studnet :public Person {

};

class Snack {
	int price;
	string name;
	string manufacturer;
	
public:
	static int cnt;
	bool isCandy;
	string getName() {
		return name;
	}

	virtual void show() {
		cout << "간식 바구니 안에 간식";
	};

	static int getCnt() {
		return cnt;
	}

	Snack(int price, string name, string manufacturer) {
		this->price = price;
		this->name = name;
		this->manufacturer = manufacturer;

		cnt++;
	}

	virtual ~Snack() {

	}
};

int Snack::cnt = 0;

class Candy : public Snack {
public:
	string tasty;
	Candy(int price, string name, string manufacturer, string tasty) :Snack(price, name, manufacturer) {
		this->tasty = tasty;
		isCandy = true;
	}

	void show() {
		cout << tasty + "맛 사탕" << endl;
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
		cout << shape + "모양 초콜릿" << endl;
	}
};



int main()
{
	Snack s1 = Snack(1000,"사탕","사탕공장");
	cout << "s1 cnt : " << s1.getCnt()<<endl;
	Snack s2 = Snack(1000, "사탕", "사탕공장");
	cout << "s2 cnt : " << s2.getCnt() << endl;
	Snack s3 = Snack(1000, "사탕", "사탕공장");
	cout << "s3 cnt : " << s1.getCnt() << endl;


	cout << "s1 cnt : " << s1.getCnt() << endl;
	cout << "s2 cnt : " << s2.getCnt() << endl;
	cout << "s3 cnt : " << s1.getCnt() << endl;


   /* Person p;
    p.name = "홍길동";
    Person p2;
    p2.name = "성춘향";

    p.static_var = 1;
    p2.static_var = 5;

    cout << p.static_var << " " << p2.static_var << endl;
    cout << Person::static_var;*/

	/*Snack* snackBasket[4] = { new Candy(2000,"목사탕", "사탕나라", "딸기"), new Candy(1500,"롤리팝", "사탕천국","콜라")
	,new Chocolate(500, "다크 초코","초코공장","네모"), new Chocolate(500, "화이트 초코","초코공장","하트") };

	for (auto s : snackBasket) {
		s->show();
	}

	for (auto s : snackBasket) {
		delete s;
	}*/

	//cout <<  ( &Candy::cnt == &Chocolate::cnt) << " " << (&Candy::cnt == &Snack::cnt)<<endl;

	//vector<Snack*> snackBasket;
	//int inputNum = 0;
	//string inputStr = "";
	//while (true) {
	//	cout << "과자 바구니에 추가할 간식을 고르시오(1 : 사탕, 2 : 초콜릿, 0 : 종료) : ";

	//	cin >> inputNum;
	//	switch (inputNum)
	//	{
	//	case 1:
	//		cout << "맛을 입력하세요 : ";
	//		cin >> inputStr;
	//		snackBasket.push_back(new Candy(2000, "목사탕", "사탕나라", inputStr));
	//		continue;
	//	case 2:
	//		cout << "모양을 입력하세요 : ";
	//		cin >> inputStr;
	//		snackBasket.push_back(new Chocolate(2000, "다크초코", "초코공장", inputStr));
	//		continue;
	//		break;
	//	case 0:
	//		cout << endl<<"과자 바구니에 담기 간식의 갯수는 " << Snack::getCnt() <<"개 입니다." << endl;
	//		break;
	//	default:
	//		cout << "0~2 숫자를 입력 해주세요" << endl;
	//		continue;
	//	}

	//	//0인 경우 switch break 타서 반복문 break로 종료
	//	break;
	//}

	//cout <<endl <<"과자 바구니에 담긴 간식 확인하기!" << endl;

	//for (auto s : snackBasket) {
	//	s->show();
	//}

	//for (auto s : snackBasket) {
	//	delete s;
	//}
}

