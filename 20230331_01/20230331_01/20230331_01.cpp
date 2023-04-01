#include <iostream>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name) {
        this->name = name;
    };

    void sleep() {
        cout << "잠자기";
    }

    int override_test(int num) {
        return num;
    }
};


class Student : public Person{ //접근제어자 부모에서 상속받은 멤버들의 한계 지정
public:
    Student() :Person("하나") {
        //기본 부모 생성자 호출
        //this->name;
        age = 7;

    };


    void study() {
        cout << "공부하기";
    }

    int override_test(int num){
        return num +this->age;
    }
};

class FreshMan : public Student {
    FreshMan() {

    }
};


int main()
{
    Person p = Person("김");
    Student s = Student();
    cout <<s.override_test(5);

}
