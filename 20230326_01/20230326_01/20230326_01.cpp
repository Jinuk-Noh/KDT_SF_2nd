#include <iostream>
#include <vector>
#include<string>

using namespace std;
//Vector
//자동으로 메모리를 할당해주는 배열
//크기를 추후에 지정 가능, 중간에 배열 크기 바꿀 수 있음
int main()
{
    /*vector<int> v1 = { 1,2,3 };
    vector<int> v2;
    vector<int> v3(3);
    vector<int> v4(3, 2);


    for (int i = 0; i < v4.size(); i++) {
        cout << v4.at(i) << " ";
    }*/

    vector<int> tempVector(5);
    
  /*  for (int i = 0; i < 5; i++) {
        tempVector[i] = i;
        cout << i + i<<"번째 :" << tempVector[i] << " ";

        tempVector.at(i) = i + 10;
        cout << i + 1<<"번째 :" << tempVector.at(i) << endl;
    }*/


    //cout <<"수정 전 : " << tempVector.size()<<endl;
    //tempVector.resize(7);
    tempVector.assign(2,7);
    //cout << "수정 후 : " << tempVector.size() << endl;

    /*for (int i = 0; i < tempVector.size(); i++) {
        cout << i + 1 << "번째 :" << tempVector[i] << endl;
    }*/


    tempVector.pop_back();
    tempVector.push_back(8);
    tempVector.push_back(9);

    tempVector.insert(tempVector.begin(), 12);

    for (int i = 0; i < tempVector.size(); i++) {
        cout << i + 1 << "번째 :" << tempVector[i] << endl;
    }

    tempVector.erase(tempVector.begin(), tempVector.begin()+2);

    for (int i = 0; i < tempVector.size(); i++) {
        cout << i + 1 << "번째 :" << tempVector[i] << endl;
    }

    tempVector.clear();
    cout<<tempVector.size();

    /*
    tempVector.pop_back();
    tempVector.push_back(8);
    tempVector.push_back(9);

    for (int i = 0; i < tempVector.size(); i++) {
        cout << i + 1 << "번째 :" << tempVector[i] << endl;
    }*/


    //vector<int> v = {1,2,3};
    ////vector<int>v(4);// 공간 4
    ////vector<int>v(5,1);//공간 5를 모든 요소 1

    //v.assign(5, 2);//이미 크기가 지정되 어있을 때, 크기 재설정 2로 초기화
    //v.resize(7);

    //v.push_back(6);// 마지막에 6을 넣겠다.
    ////v.pop_back();//제일 마지막 원소를 빼겠다.
    //
    ////v.insert(v.begin(),5); //원하는 위치에 원소를 넣겠다.
    ////v.begin();// vector의 시작 주소 반환
    ////front/ back - 첫요소/ 마지막 요소
    //v.erase(v.begin(), v.begin() + 3);
    //for (int i = 0; i < v.size(); i++) {
    //    cout << v.at(i)<< " ";
    //    v.at(i) = 9;
    //    cout << v[i] << endl;
    //}

    //v.clear();// 벡터 비움

    //for (int i = 0; i < v.size(); i++) {
    //    cout << v.at(i) << " ";
    //}

    ////2차원
    //vector < vector<int>> v2 = { {1,2},{3,4} };

    //for (int i = 0; i < v2.size(); i++) {
    //    for (int j = 0; j < v2.at(i).size(); j++) {
    //        cout << v2.at(i).at(j) << " ";
    //    }
    //    cout << endl;

    //}

   /* int x; int y;
    do {
        cout << "x를 입력하세요 ";
        cin >> x;
        cout << "y를 입력하세요 ";
        cin >> y;

        if (x < 1 || y < 1) {
            cout << "x와 y 모드 양수를 입력하세요 \n";
        }

    } while (x < 1 || y < 1);


    vector<vector<int>> v(x);
    int num = 0;
    for (auto temp : v) {
        temp.assign(y, 0);
        for (auto t : temp) {
            t = ++num;
            cout << t << " ";
        }
        cout << endl;
    }

    int n;
    vector<int> v2;
    do {

        cout << "숫자를 입력하세요 (0: exit) : ";
        cin >> n;
        v2.push_back(n);

    } while (n !=0);

    int result = 0;
    for (auto i : v2) {
        result += i;
    }

    cout << "사용자가 입력한 수의 합은 : "<< result;*/

    //97-122 26
    //vector<int> alphabet(26, 0);
    //string inputStr;
    //vector<char> resultStr;
    //int cnt = 0;

    //cout << "영어 소문자 입력 ";
    ////cin >> inputStr;
    ////cin.getline(inputStr, 200, '\n');
    //getline(cin, inputStr);

    //for (auto c : inputStr) {
    //    if (c < 97 || c>122) continue;
    //    alphabet.at((int)c - 97)++;
    //    if (alphabet.at((int)c - 97) == 1) {
    //        cnt++;
    //        resultStr.push_back(c);
    //    }
    //}

    //string a ="";

    //for (auto c : resultStr) {
    //    a.push_back(c);
    //    if (resultStr.back() != c) {
    //        a.append(", ");
    //    }
    //}

    //cout << cnt << "개("<<a<<")";
}

