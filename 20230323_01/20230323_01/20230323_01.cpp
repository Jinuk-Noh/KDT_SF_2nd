// 20230323_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    //std::cout << "Hello World!\n";

   /* int a = 1;
    int b = 2;

    std::cout << a + b;
    std::cout << "\n";

    float f = 1.2;
    float g = 3.9;

    std::cout << f + g;
    std::cout << "\n";

    bool c1 = true;
    bool c2 = false;

    std::cout << c1;
    std::cout << "\n";
    std::cout << c2;
    std::cout << "\n";

    char d = 'a';
    char e = 'b';

    std::cout << d;
    std::cout << "\n";
    std::cout << e;
    std::cout << "\n";

    std::string str1 = "안녕? \n";
    std::cout << str1;
    std::string str2 = "반가워 \n";
    std::cout << str2;*/

  /*  std::string str3 = "1";
    std::string str4 = "2";
    std::cout << str3+str4;

    std::cout << "\n";

    std::string str5 = "포스코";
    str5 = "코딩온";
    std::cout << str5;
    std::cout << "\n";*/

   /* int a;
    std::cin >> a;
    std::cout << a+3;*/
    
    //int a;
    //std::string b;
    //std::string c;

    //std::cin >> a;
    //std::cin >> b;
    //std::cin >> c;

    //std::cout << a<<b; // 타입이 다를 경우 <<로 연결하기
    //std::cout << "\n";
    ////std::cout << a + b; //타입이 다른 두개의 변수를 연결해서 오류 발생
    //std::cout << b + c; //타입이 같은경우 + 사용

    /*std::string name;
    std::cout << "이름을 입력하세요.";
    std::cout << "\n";
    std::cin >> name;

    int age;
    std::cout << "나이을 입력하세요.";
    std::cout << "\n";
    std::cin >> age;
   

    std::cout << "안녕하세요! " << name << "님" << "(" << age << "세)";*/

   /* 
        if (조건) {
            조건이 참일 때 실행할 것
        else if(조건2){
            조건 1이 거짓이고, 조건2가 참일 때
        }else{
            모든 조건이 거짓일 때
        }
    */


   /* int a = 5;
    if (a > 10) {
        std::cout << "a는 10보다 크다";
    }
    else if (a ==5) {
        std::cout << "a는 5이다.";
    }
    else {
        std::cout << "a는 10보다 크지 않고 5가 아니다.";
    }


    int temp;
    switch (temp) {
        case 1:
            std::cout << 1 << "temp 값은 1이다";
            break;

        default:
            break;
    }*/

    //삼항연산잔 a>5 ? 참: 거짓;

    //실습 2
    int age;
    std::cout << "실습2) 나이를 입력하세요 ";
    std::cin >> age;

    if (age >= 200) {
        std::cout << "나이가 너무 많습니다.";
    }
    else if (age >= 20) {
        std::cout << "성인";
    }
    else if (age >= 17) {
        std::cout << "고등학생";
    }
    else if (age>=14) {
        std::cout << "중학생";
    }
    else if ( age>=8) {
        std::cout << "초등학생";
    }
    else if (age >= 1) {
        std::cout << "유아";
    }

    std::cout << "\n";

    //실습 3
    std::string name;
    std::cout << "실습3) 이름을 입력하세요 ";
    std::cin >> name;

    if (name == "홍길동") {
        std::cout << "남자";
    }
    else if (name == "성춘향") {
        std::cout << "여자";
    }
    else {
        std::cout << "모르겠어요";
    }

    std::cout << "\n";

    //실습 4
    int num;
    std::cout << "실습4) 숫자 입력 \n";
    std::cin >> num;

    num % 5 == 0 ? std::cout << num << "는  5의 배수입니다." : std::cout << num << "는  5의 배수가 아니네요. ㅠㅠ";
    std::cout << "\n";

    //실습 5
    std::cout << "실습5) 두개의 벼수와 연산자를 입력 받아 실행 \n";
    int num1;
    int num2;
    char c;

    std::cout << "연산할 정수 두 개를 입력해 주세요.";
    std::cin >> num1;
    std::cin >> num2;

    std::cout << "\n";
    std::cout << "연산자를 입력해주세요.(+,-,*,/)";
    std::cin >> c;

    switch (c)
    {
        case '+':
            std::cout << "합은 " << num1 + num2;
            break;
        case '-':
            std::cout << "차는 "<<num1 - num2;
            break;
        case '/':
            std::cout << "몫은 "<<num1 / num2<<" 나머지는 "<<num1%num2;
            break;
        case '*':
            std::cout << "곲은 "<<num1 * num2;
            break;
        default:

            break;
    }


    

    
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
