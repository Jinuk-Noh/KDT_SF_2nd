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
        cout << "Á¡½ÅÀº ÇÐ½Ä" <<endl;
    }
  
};

class Kim : public Student {
  
public:
    Kim(string name, string school, int age, string number) :Student(name, school, age, number) {

    };

    void lunch() {
        cout << "Á¡½ÉÀº ±è°¡³× ±è¹ä" << endl;
    }
};

class Baek : public Student {
    
public:
    Baek(string name, string school, int age, string number) :Student(name, school, age, number) {

    };

    void lunch() {
        cout << "Á¡½ÉÀº ¹éÁ¾¿ø ÇÇÀÚ" << endl;
    }
};


int main()
{
    Kim kim = Kim("±è¾¾", "°í·Á´ë", 25, "2023001");
    Baek baek = Baek("¹é¾¾", "¿¬¼¼´ë", 28, "2020001");

    kim.lunch();
    baek.lunch();
}
