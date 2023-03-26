#include <iostream>
//using namespace std;
using std::cout; //cout 만 접근을 풀어주겠다.

namespace tempNamespace {
	//변수
	int tempCnt;
	//메소드

}

//using namespace test;
//using namespace test1;
//namespace test{
//	int num = 1;
//}
//
//namespace test1 {
//	int num = 1;
//}

//namespace wooriBank {
//	int balance = 0;
//
//	double deposit(int money) {
//		return (double)money + 0.03 * money;
//	}
//}
//
//namespace hanaBank {
//	int balance = 0;
//
//	double deposit(int money) {
//		return (double)money + 0.05 * money;
//}

namespace seoul {
	//int resionNum;
	//string landMark;
}
namespace busan {
	//int resionNum;
	//string landMark;
}

using namespace busan;


int main() {

	tempNamespace::tempCnt = 77;
	cout << tempNamespace::tempCnt;
	//cin >> tempNamespace::tempCnt;

	/*seoul::resionNum = 1;
	seoul::landMark = "경복궁";
	resionNum = 2;
	landMark = "광안대교";

	cout << "서울 " << seoul::resionNum << " " << seoul::landMark << endl;
	cout << "부산 " << busan::resionNum << " " << busan::landMark << endl;*/
}