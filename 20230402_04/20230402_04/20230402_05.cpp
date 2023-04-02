#include <iostream>
#include <vector>
#include "Snack.h"
#include "Candy.h"
#include "Chocolate.h"

using namespace std;


int main()
{
	 vector<Snack*> snackBasket;
	 int inputNum = 0;
	 string inputStr = "";
	 while (true) {
	 	cout << "과자 바구니에 추가할 간식을 고르시오(1 : 사탕, 2 : 초콜릿, 0 : 종료) : ";

	 	cin >> inputNum;
	 	switch (inputNum)
	 	{
	 	case 1:
	 		cout << "맛을 입력하세요 : ";
	 		cin >> inputStr;
	 		snackBasket.push_back(new Candy(2000, "목사탕", "사탕나라", inputStr));
	 		continue;
	 	case 2:
	 		cout << "모양을 입력하세요 : ";
	 		cin >> inputStr;
	 		snackBasket.push_back(new Chocolate(2000, "다크초코", "초코공장", inputStr));
	 		continue;
	 		break;
	 	case 0:
	 		cout << endl<<"과자 바구니에 담기 간식의 갯수는 " << Snack::getCnt() <<"개 입니다." << endl;
	 		break;
	 	default:
	 		cout << "0~2 숫자를 입력 해주세요" << endl;
	 		continue;
	 	}

	 	//0인 경우 switch break 타서 반복문 break로 종료
	 	break;
	 }

	 cout <<endl <<"과자 바구니에 담긴 간식 확인하기!" << endl;

	 for (auto s : snackBasket) {
	 	s->show();
	 }

	 for (auto s : snackBasket) {
	 	delete s;
	 }
}

