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
	 	cout << "���� �ٱ��Ͽ� �߰��� ������ ���ÿ�(1 : ����, 2 : ���ݸ�, 0 : ����) : ";

	 	cin >> inputNum;
	 	switch (inputNum)
	 	{
	 	case 1:
	 		cout << "���� �Է��ϼ��� : ";
	 		cin >> inputStr;
	 		snackBasket.push_back(new Candy(2000, "�����", "��������", inputStr));
	 		continue;
	 	case 2:
	 		cout << "����� �Է��ϼ��� : ";
	 		cin >> inputStr;
	 		snackBasket.push_back(new Chocolate(2000, "��ũ����", "���ڰ���", inputStr));
	 		continue;
	 		break;
	 	case 0:
	 		cout << endl<<"���� �ٱ��Ͽ� ��� ������ ������ " << Snack::getCnt() <<"�� �Դϴ�." << endl;
	 		break;
	 	default:
	 		cout << "0~2 ���ڸ� �Է� ���ּ���" << endl;
	 		continue;
	 	}

	 	//0�� ��� switch break Ÿ�� �ݺ��� break�� ����
	 	break;
	 }

	 cout <<endl <<"���� �ٱ��Ͽ� ��� ���� Ȯ���ϱ�!" << endl;

	 for (auto s : snackBasket) {
	 	s->show();
	 }

	 for (auto s : snackBasket) {
	 	delete s;
	 }
}

