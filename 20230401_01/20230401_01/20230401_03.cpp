#include <iostream>

using namespace std;

class Person {
public:
	Person(){
		cout << "������ �Դϴ�."<<endl;
	}
	virtual ~Person(){
		cout << "�Ҹ��� �Դϴ�."<<endl;
	} //�Ҹ���

	virtual void sleep() {
		cout << "���ڱ�";
	}
};

class Student:public Person {
	void sleep() {
		cout << "10�ÿ�";
	}
};


int main() {
	//Person p;//���� �޸� - ���� / ����� ������ ���� �� �޸� ������
	//Person* pp = new Person(); // ���� �޸� - �� / ��������� ���� �ʿ�

	//delete pp; // <<�Ҹ��� ȣ�� ��
	//cout << "�ȳ�" << endl;

	Person p = Student();
	p.sleep();

	Person* pp = new Student();
	pp->sleep();

	delete pp;
	//student �Ҹ��� �ȳ��� -> �θ��� �Ҹ��ڸ� �����Լ��� ��������
	// person �Ҹ���
	
}