#include <iostream>
#include <fstream> //파일을 읽고, 쓸 수 있도록 관련 기능을 제공하는 헤더
#include <string>
#include <vector>
//파일 입출력


using namespace std;
int main()
{
    //open(파일명) 파일열기
    //is_open() 파일 열기 성공여부 bool 값
    //fail() 파일 열기 실패여부 bool값
    //close 파일 닫기

    //ifstream 파일의 내용을 가지고 프로그램에 입력할 수 있게 도와주는 클래스

    //ofstream 출력을 파일에 저장할 수 있게 돕는 클래스 프로그램 -> 파일

    //ifstream file;
    //file.open("hello.txt");

    ////string word1;
    ////string word2;

    //string line;
    //if (file.is_open()) {
    //    //cout << "success\n";
    //    //for (int i = 0; i < 3; i++) {
    //    //    //file >> word1 >> word2;
    //    //    //cout << word1 << " " << word2;

    //    //    getline(file, line);
    //    //    cout << line;

    //    //}

    //    while (getline(file, line)) {
    //        cout << line << endl;
    //    }
    //}
    //else cout << "fail\n";

    //file.close();


    //ofstream file2("bye.txt");

    //if (!file2.fail()) {
    //    file2 << "bye world!\n" << "bye bye \n";
    //}
    //else {
    //    cout << "fail to open file\n";
    //}

    //file2.close();
   
    //실습 0
    //ifstream helloFile;
    //string line;
    //vector<string> words;

    //helloFile.open("hello.txt");

    //if (helloFile.is_open()) {
    //    while (getline(helloFile, line)) {
    //        words.insert(words.begin(), line); // index가 아닌 주소
    //    }
    //}
    //else {
    //    cout << "Fail to open.";
    //}

    //ofstream outptFile;
    //outptFile.open("output.txt");

    //if (outptFile.is_open()) {
    //    
    //    for (auto s : words) {
    //        outptFile << s << endl;
    //    }
    //}
    //else {
    //    cout << "Fail to open.";
    //}

    //outptFile.close();

    //실습 1
    //ofstream os("member.txt");//, ios::app
    //
    //cout << "3명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요"<<endl;

    //if (os.is_open()) {
    //    vector<string> members;
    //    string name;
    //    string pw;
    //    for (int i = 0; i < 3; i++) {
    //        cout << i + 1 << "번째 회원 : ";
    //        cin >> name >> pw;
    //        members.push_back(name);
    //        members.push_back(pw);
    //    }

    //    for (int i = 0; i < members.size(); i++) {
    //        if (i % 2 == 0) {
    //            os << members[i] << " ";
    //        }
    //        else {
    //            os << members[i] << endl;
    //        }
    //    }

    //    os.close();
    //}
    //else {
    //    cout << "실패";
    //}

    //ifstream is;
    //string line;
    //is.open("member.txt");

    //if (is.is_open()) {
    //    cout << "회원 명부 파일 읽기"<<endl;
    //    while (getline(is, line)) {
    //        cout << line << endl;
    //    }

    //    is.close();
    //}

    //실습 2
    string line;
    string name;
    string pw;
    bool check = false;
    cout << "이름을 입력하세요. ";
    cin >> name;
    cout << "비번을 입력하세요. ";
    cin >> pw;

    ifstream is;

    is.open("member.txt");
    if (is.is_open()) {
        while (getline(is, line)) {
            if (line == (name + " " + pw)) {
                check = true;// cout << "로그인 성공";
                break;
            }
        }

        if (check) {
            cout << "로그인 성공"<<endl;
            
            string newNumbmer;
            string word;
            vector<string> members;

            bool isNew = true;

            cout << "전화번호를 입력해 주세요 : ";
            cin >> newNumbmer;


            ifstream stream("member_tel.txt");
            
            if (stream.is_open()) {
                
                while (!stream.eof()) {
                    stream >> word;
                    members.push_back(word);
                }

                stream.close();
            }

            for (int i = 0; i < members.size(); i = i + 2) {
                if (members[i] == name) {
                    members[i + 1] = newNumbmer;
                    isNew = false;
                }
            }
            
            if (isNew) {
                members.push_back(name);
                members.push_back(newNumbmer);
            }
                
            ofstream ostream("member_tel.txt");
            if (ostream.is_open()) {
                for (int i = 0; i < members.size(); i++) {
                    if (i % 2 == 0) {
                        ostream << members[i] << " ";
                    }
                    else {
                        ostream << members[i];
                        if (i != members.size() - 1) {
                            ostream << endl;
                        }
                    }
                }


                ostream.close();
            }
        }
        else {
            cout << "로그인 실패";
        }

        is.close();
    }
    else {
        cout << "로그인 실패";
    }
}