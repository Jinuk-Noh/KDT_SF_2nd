#include <iostream>
#include<cstdlib>
#include<ctime> 
#include <vector>

using namespace std;

bool input_user(int* lastNum, string* winner);
void input_computer(int* lastNum, string* winner);

int main()
{
    srand(time(NULL)); // seed value srand의 값을 다르게 넣어야함 
    int num = rand(); // 
    cout << num <<endl;
    //버윔 지정 나머지 값이용
    cout << num % 25 << endl; // 0~-24
    cout << num % 25 + 1 << endl; //1~25
    cout << RAND_MAX << endl;

    srand(time(NULL));
    vector<int> v;
    int temp = 0;
    vector<int> checkArr(46,0);
    //bool isNew = true;

    while (v.size() < 6)
    {
        temp = rand() % 45 + 1;
        
        if (checkArr[temp] < 1) {
            v.push_back(temp);
        }

        checkArr[temp] = 1;

        /*for (int i : v) {
            if (i == temp) {
                isNew = false;
                break;
            }
            else {
                isNew = true;
            }
        }

        if (isNew) {
            v.push_back(temp);
        }*/
    }

    for (int i : v) {
        cout << i << " ";
    }
}
