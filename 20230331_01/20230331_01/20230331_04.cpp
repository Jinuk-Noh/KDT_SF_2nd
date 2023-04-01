#include <iostream>

using namespace std;


class Student 
{
    string name;
    string school;
    int age;
    string number;

protected:
    Student(string name, string school, int age, string number) {
        this->name = name;
        this->school = school;
        this->age = age;
        this->number = number;
    }

    void lunch() {
        cout << "������ �н�" <<endl;
    }
  
};

class Kim : public Student {
  
public:
    Kim(string name, string school, int age, string number) :Student(name, school, age, number) {

    };

    void lunch() {
        cout << "������ �谡�� ���" << endl;
    }
};

class Baek : public Student {
    
public:
    Baek(string name, string school, int age, string number) :Student(name, school, age, number) {

    };

    void lunch() {
        cout << "������ ������ ����" << endl;
    }
};


int main()
{
    Kim kim = Kim("�达", "�����", 25, "2023001");
    Baek baek = Baek("�龾", "������", 28, "2020001");

    kim.lunch();
    baek.lunch();
}
