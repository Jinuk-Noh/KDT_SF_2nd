#include <iostream>
#include "Student.h"

using namespace std;
int main()
{
    Student s1 = Student("");
    s1.getName();
    cout <<s1.getCnt();

    Student s2 = Student("1");
    cout<<s2.getCnt();
    cout << s1.getCnt();

}
