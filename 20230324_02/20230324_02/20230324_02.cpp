#include <iostream>

//int multiple(int a, int b) {
//    int result = a * b;
//    return result;
//}
//
//int test()
//{
//
//    int a = 2;
//    std::string b = "b";
//    return a;
//}
//
//std::string test_4() {
//    return "test4";
//}


int add(int a, int b);
int minus(int a, int b);
int multiple(int a, int b);
float divide(int a, int b);
void CheckNum(int a);
int CheckMax(int a, int b, int c);
//함수
int main()
{
    int num1; int num2; int num3;
   /* std::cout << "두 수를 입력하세요.";
    std::cin >> num1;
    std::cin >> num2;

    std::cout << "add :" << add(num1, num2) << "\n";
    std::cout << "minus :" << minus(num1, num2) << "\n";
    std::cout << "multiple :" << multiple(num1, num2) << "\n";
    std::cout << "divide :" << divide(num1, num2) << "\n";

    std::cout <<  "\n";
    std::cout << "숫자를 입력하세요.";
    std::cin >> num1;
    CheckNum(num1);*/

    std::cout << "\n";
    std::cout << "숫자를 세 개를 입력하세요.";
    std::cin >> num1;
    std::cin >> num2;
    std::cin >> num3;
    std::cout << "가장 큰 수 :" << CheckMax(num1, num2, num3) << "\n";
}

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    if (a > b) {
        return a - b;
    }
    else {
        return b - a;
    }
}

int multiple(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / (float)b;
}

void CheckNum(int a) {
    if (a % 2 == 0) {
        std::cout << "짝수" << "\n";
    }
    else {
        std::cout << "홀수" << "\n";
    }
}

int CheckMax(int a, int b, int c) {
    int max = 0;
    if (a < b) {
        max = b;
    }
    else {
        max = a;
    }

    if (max < c) {
        max = c;
    }
    
    return max;
}