#include "Person.h"
int Person::cnt = 0;
Person::Person(string name) {
	this->name = name;
	plusCnt();
}

int Person::getCnt() {
	return cnt;
}

void Person::plusCnt() {
	cnt++;
}

string Person::getName() {
	return this->name;
}