#include<iostream>

using namespace std;



class Shape {
	int side_cnt; //º¯ÀÇ °¹¼ö
	int bt_side_length;// ¹Øº¯ÀÇ ±æÀÌ

public:
	Shape(int bt_side_length, int side_cnt) {
		this->side_cnt = side_cnt;
		this->bt_side_length = bt_side_length;
	}

	void printInfo() {
		cout << "º¯ÀÇ °³¼ö : " << this->side_cnt << endl
			<< "¹Øº¯ÀÇ ±æÀÌ : " << this->bt_side_length;
	}

	int get_side_lenght() {
		return bt_side_length;
	}
};

class Retangle : public Shape {
	int horizon_length; //¼¼·Î ±æÀÌ

public:
	Retangle(int bt_side_lenght, int horizon_length):Shape(bt_side_lenght, 4) {
		this->horizon_length = horizon_length;
	}

	int area() {
		return this->get_side_lenght() * this->horizon_length;
	}


};

class Triangle : public Shape {
	int height; // ³ôÀÌ

public:
	Triangle(int bt_side_lenght, int height) :Shape(bt_side_lenght, 3) {
		this->height = height;
	}

	float area() {
		return (this->get_side_lenght() * this->height)/2;
	}
};


int main() {
	Retangle r = Retangle(4,2); //¹Øº¯ 4, ¼¼·Î 2
	cout << "-------»ç°¢Çü-------" << endl;
	r.printInfo();
	cout << endl << "³ÐÀÌ : " << r.area()<<endl;

	Triangle t = Triangle(2, 5); //¹Øº¯ 2, ¼¼·Î 5
	cout << "-------»ï°¢Çü-------" << endl;
	t.printInfo();
	cout << endl << "³ÐÀÌ : " << t.area()<<endl;

}