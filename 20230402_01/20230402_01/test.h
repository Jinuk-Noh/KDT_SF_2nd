#pragma once

#ifndef __PERSON_H__
#define __PERSON_H__
#include<iostream>
using namespace std;
class Person {
public:
    static int static_var; // 초기화 필요
    string name;
    static void static_method();
    void sleep();

    Person();
};

#endif // !1
