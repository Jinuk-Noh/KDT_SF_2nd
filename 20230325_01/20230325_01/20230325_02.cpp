#include <iostream>

//���� �迭�� ������
int main() {
	//��������� �Է¹��� ���� �迭�� ũ�⸦ ������ ��

	//������ �޸��� �ּҸ� ���� ����


	//int n = 3;
	//int* p =&n;

	////std::cout << p;
	//////�ּҰ� ���

	////std::cout << *p;
	////�ּҰ��� ��� �� ���

	//std::string str = "aaa";
	//std::string* str_p = &str;

	//std::cout << str_p << "\n";
	//std::cout << *str_p << "\n";

	//int& num = n; // ���� ���� n�̶�� ������ num�̶�� ������ ���� ��Ȳ
	//std::cout << n << "\n";
	//
	//std::cout << &n << "\n";
	//
	//std::cout <<num << "\n";
	////std::cout << *num;
	//std::cout << &num << "\n";

	// �� ���� : ���� �޸� ���� - �Ҵ�� ������ ���� �����ؾ���, ���ÿ��� : ���� �޸� ����
	//�����͸� �̿��ϸ� ���� �޸𸮸� �������� �� �ִٴ� ���� �����͸� �̿��� ��� ������ �����޸𸮴� �ƴϴ�.
	//int* p = new int; // << �������� ����
	//delete p; //<�޸� ����

	//int num;
	////int arr[num] xx;
	//std::cin >> num;
	//int* arr = new int[num];


	//for (int i = 0; i < num; i++) {
	//	arr[i] = i + 1;
	//	std::cout << arr[i] << " ";
	//	std::cout << &arr[i] << " ";
	//	std::cout << arr+i << " ";
	//	//std::cout << *arr + +5 << " ";
	//	std::cout << *(arr + i) << " ";
	//}

	//delete[] arr;

	//num*num ���
	/*int num = 5;
	int** arr = new int* [num];

	for (int i = 0; i < num; i++) {
		arr[i] = new int[num];
	}

	for (int i = 0; i < num; i++) {
		delete[] arr[i];
	}

	delete[] arr;*/
	/*int x; int y;
	
	do {
		std::cout << "x�� �Է��ϼ��� : ";
		std::cin >> x;

		std::cout << "y�� �Է��ϼ��� : ";
		std::cin >> y;

		if (x <= 0 || y <= 0) {
			std::cout << "x�� y ��� ����� �Է����ּ��� \n";
		}
	} while (x <= 0 || y <= 0);

	
	int** arr = new int* [x];

	for (int i = 0; i < x; i++) {
		arr[i] = new int[y];
		
		for (int j = 0; j < y; j++) {
			arr[i][j] = (j + 1)+(i*y);
			std::cout << arr[i][j]<< " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < x; i++) {
		delete[] arr[i];
	}

	delete[] arr;*/

	int cnt;
	int* scores;
	int result = 0;
	std::cout << "�л� �� �Է� : ";
	std::cin >> cnt;

	scores = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		std::cout << i+1<<"�� �л��� ���� �Է� : ";
		std::cin >> scores[i];
	}

	for (int i = 0; i < cnt; i++) {
		result += scores[i];
	}

	std::cout <<  "���� ��� : "<<(float)result/cnt;

	delete[] scores;

	

}