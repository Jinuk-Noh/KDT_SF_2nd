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
//구조체
int main() {
	/*Position p;
	p.x = 3;
	p.y = 6;
	p = { 4,8 };

	cout << "x : " << p.x<<" , y : "<<p.y<<endl;*/


	Retangle t;
	
	cout << "가로 세로 길이를 입력하세요 : ";
	cin >>t.width >> t.height;
	//cin >> t.height;
	cout << "넓이는 " << t.width * t.height;



}