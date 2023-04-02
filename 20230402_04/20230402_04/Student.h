#pragma once

#ifndef __STUDENT_H__
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person {
public:
	Student(string name);
};

#endif // !__STUDENT_H__
