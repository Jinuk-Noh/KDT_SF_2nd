#include <iostream>
//배열
int main()
{
    std::string fruit[3] = { "apple","banana","grape" };
    
    //크기를 정해야함
    /*std::string fruit1[3];
    fruit1[0] = "apple";
    fruit1[1] = "banana";
    fruit1[2] = "grape";

    std::string frui21[] = {"apple","banana","grape"};

    std::cout << fruit<<std::endl;
    std::cout << fruit[0]<< std::endl;
    std::cout << fruit[1]<< std::endl;
    std::cout << fruit[2]<< std::endl;*/

    //sizeof() : 변수의 크기를 byte단위로
    //ex) sizeof(fruit)/sizeof(std::string)

    //std::string alphabat[2][4] = { {"a","b","c","d"},{"e","f","g","h"} };
    //int num[2][3] = { {2,2,2},{1,23,3} };

    //for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++) {
    //    for (int j = 0; j < sizeof(num[0])/sizeof(int); j++) {
    //        std::cout << num[i][j] << " ";
    //    }
    //    std::cout << "\n";
    //}

    ////for-each
    //for (auto n : num[0]) {

    //}

    /*std::string city[5] = { "Seuol","Tokyo", "Beijing", "Paris", "London" };
    for (auto c : city) {
        std::cout << c << std::endl;
    }*/


   /* std::string city2[5] = {};
    
    for (int i = 0; i < sizeof(city2) / sizeof(std::string); i++) {
        std::cout <<i+1 << "번 나라 이름 입력 ";
        std::cin >> city2[i];
    }

    for (auto c : city2) {
        std::cout << c <<" ";
    }*/
   /* int grade[5];
    for (int i = 0; i < sizeof(grade) / sizeof(int); i++) {
        std::cout << i + 1 << "번 학생의 성적을 입력하세요. ";
        std::cin >> grade[i];
    }

    int avg = 0;
    for (auto c : grade) {
        avg += c;
    }

    std::cout <<  "성적 평균 : "<< (float)avg / (sizeof(grade) / sizeof(int));*/

   /* int grade[3][2];
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "번 학생의 국어 수학 성적을 입력하세요. ";  
        std::cin >> grade[i][0];
        std::cin >> grade[i][1];
    }

    int korScore = 0;
    int mathScore = 0;
    for (auto c : grade) {       
        korScore += c[0];
        mathScore += c[1];
    }

    std::cout << "국어 평균 : " << (float)korScore / 3 <<"\n";
    std::cout << "수학 평균 : " << (float)mathScore / 3 << "\n";*/
    
    int correct[3] = { 1, 8, 5 };
    int user[3];

    int check[10] = { 0,0,0,0,0,0,0,0,0,0 };
    int dupleCheck[10] = {0,0,0,0,0,0,0,0,0,0};

    bool isDuple = false;
    //정답 갯수
    int cnt = 0;

    std::cout << "3개 숫자 입력 ";
    do {    
        if (isDuple) {
            std::cout << "중복된 숫자가 있습니다. 다시 입력하세요 ";

            for (int c : user) {
                if (c > 0) {
                    dupleCheck[c] = 0;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            std::cin >> user[i];
            
            while (user[i] > 9 || user[i]<1) {
                std::cin.clear();
                std::cout << i+1 <<"번째 숫자 부터 1~9 숫자를 다시 입력하세요 ";
                std::cin >> user[i];
                
            }

            dupleCheck[user[i]]++;

            if (dupleCheck[user[i]] > 1) {
                isDuple = true;
                std::cin.clear();
                
                break;
            }
            else {
                isDuple = false;
            }
        }
    } while (isDuple);

    for (int c: correct) {
        check[c]++;
    }

    for (int u : user) {
        if (check[u] == 1) {
            cnt++;
        }
    }

    std::cout << cnt << "개 맞춤!";
}