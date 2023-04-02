#include "test.h";

//#include <> // .h x ,내가 만들지 않은 파일
//#include "" //내가 만든 파일

int Person::static_var = 0;

void Person::static_method() {
    //일반 멤버 사용 불가
    //name = "김씨"; <<오류 발생

    static_var = 0;
}

void  Person::sleep() {
    //static 멤버 사용가능
    static_var = 1;
}

Person::Person() {
    static_var++;
    cout << static_var;
}
