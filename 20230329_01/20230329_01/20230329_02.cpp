#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Position {
	int x = 0;
	int y = 0;
};

struct Retangle {
	float width = 0;
	float height = 0;
};
//����ü
int main() {
	/*Position p;
	p.x = 3;
	p.y = 6;
	p = { 4,8 };

	cout << "x : " << p.x<<" , y : "<<p.y<<endl;*/


	Retangle t;
	
	cout << "���� ���� ���̸� �Է��ϼ��� : ";
	cin >>t.width >> t.height;
	//cin >> t.height;
	cout << "���̴� " << t.width * t.height;



}