#include "test.h";

//#include <> // .h x ,���� ������ ���� ����
//#include "" //���� ���� ����

int Person::static_var = 0;

void Person::static_method() {
    //�Ϲ� ��� ��� �Ұ�
    //name = "�达"; <<���� �߻�

    static_var = 0;
}

void  Person::sleep() {
    //static ��� ��밡��
    static_var = 1;
}

Person::Person() {
    static_var++;
    cout << static_var;
}
