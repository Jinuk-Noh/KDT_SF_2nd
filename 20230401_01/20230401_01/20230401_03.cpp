#include <iostream>

using namespace std;

class Person {
public:
	Person(){
		cout << "생성자 입니다."<<endl;
	}
	virtual ~Person(){
		cout << "소멸자 입니다."<<endl;
	} //소멸자

	virtual void sleep() {
		cout << "잠자기";
	}
};

class Student:public Person {
	void sleep() {
		cout << "10시에";
	}
};


int main() {
	//Person p;//정적 메모리 - 스택 / 사용한 영역이 끝날 때 메모리 해제됨
	//Person* pp = new Person(); // 동적 메모리 - 힙 / 명시적으로 해제 필요

	//delete pp; // <<소멸자 호출 됨
	//cout << "안녕" << endl;

	Person p = Student();
	p.sleep();

	Person* pp = new Student();
	pp->sleep();

	delete pp;
	//student 소멸자 안나옴 -> 부모의 소멸자를 가상함수로 만들어야함
	// person 소멸자
	
}