#include <iostream>
//using namespace std;
using std::cout; //cout �� ������ Ǯ���ְڴ�.

namespace tempNamespace {
	//����
	int tempCnt;
	//�޼ҵ�

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
	seoul::landMark = "�溹��";
	resionNum = 2;
	landMark = "���ȴ뱳";

	cout << "���� " << seoul::resionNum << " " << seoul::landMark << endl;
	cout << "�λ� " << busan::resionNum << " " << busan::landMark << endl;*/
}