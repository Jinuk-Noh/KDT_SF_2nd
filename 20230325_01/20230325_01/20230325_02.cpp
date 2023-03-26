#include <iostream>

//동적 배열과 포인터
int main() {
	//사용자한테 입력받은 수로 배열의 크기를 지정할 때

	//포인터 메모리의 주소를 가진 변수


	//int n = 3;
	//int* p =&n;

	////std::cout << p;
	//////주소값 출력

	////std::cout << *p;
	////주소값에 담김 값 출력

	//std::string str = "aaa";
	//std::string* str_p = &str;

	//std::cout << str_p << "\n";
	//std::cout << *str_p << "\n";

	//int& num = n; // 참조 변수 n이라는 변수에 num이라는 별명을 붙인 상황
	//std::cout << n << "\n";
	//
	//std::cout << &n << "\n";
	//
	//std::cout <<num << "\n";
	////std::cout << *num;
	//std::cout << &num << "\n";

	// 힙 영역 : 동적 메모리 저장 - 할당과 해제를 직접 관리해야함, 스택영역 : 정적 메모리 저장
	//포인터를 이용하면 동적 메모리를 생성ㅇ할 수 있다는 거지 포인터를 이용한 모든 변수가 동적메모리는 아니다.
	//int* p = new int; // << 힙영역에 저장
	//delete p; //<메모리 해제

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

	//num*num 행렬
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
		std::cout << "x를 입력하세요 : ";
		std::cin >> x;

		std::cout << "y를 입력하세요 : ";
		std::cin >> y;

		if (x <= 0 || y <= 0) {
			std::cout << "x와 y 모두 양수를 입력해주세요 \n";
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
	std::cout << "학생 수 입력 : ";
	std::cin >> cnt;

	scores = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		std::cout << i+1<<"번 학생의 성적 입력 : ";
		std::cin >> scores[i];
	}

	for (int i = 0; i < cnt; i++) {
		result += scores[i];
	}

	std::cout <<  "성적 평균 : "<<(float)result/cnt;

	delete[] scores;

	

}