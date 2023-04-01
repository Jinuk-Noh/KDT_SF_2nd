#include<iostream>

using namespace std;



class Shape {
	int side_cnt; //���� ����
	int bt_side_length;// �غ��� ����

public:
	Shape(int bt_side_length, int side_cnt) {
		this->side_cnt = side_cnt;
		this->bt_side_length = bt_side_length;
	}

	void printInfo() {
		cout << "���� ���� : " << this->side_cnt << endl
			<< "�غ��� ���� : " << this->bt_side_length;
	}

	int get_side_lenght() {
		return bt_side_length;
	}
};

class Retangle : public Shape {
	int horizon_length; //���� ����

public:
	Retangle(int bt_side_lenght, int horizon_length):Shape(bt_side_lenght, 4) {
		this->horizon_length = horizon_length;
	}

	int area() {
		return this->get_side_lenght() * this->horizon_length;
	}


};

class Triangle : public Shape {
	int height; // ����

public:
	Triangle(int bt_side_lenght, int height) :Shape(bt_side_lenght, 3) {
		this->height = height;
	}

	float area() {
		return (this->get_side_lenght() * this->height)/2;
	}
};


int main() {
	Retangle r = Retangle(4,2); //�غ� 4, ���� 2
	cout << "-------�簢��-------" << endl;
	r.printInfo();
	cout << endl << "���� : " << r.area()<<endl;

	Triangle t = Triangle(2, 5); //�غ� 2, ���� 5
	cout << "-------�ﰢ��-------" << endl;
	t.printInfo();
	cout << endl << "���� : " << t.area()<<endl;

}