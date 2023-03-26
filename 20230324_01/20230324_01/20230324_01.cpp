#include <iostream>


//반복문
int main()
{
	////for 초기값; 조건문; 증감문
	//for (int i = 0; i < 5; i++) {
	//	std::cout << "안녕하세요" <<std::endl;
	//}

	//int i = 0;
	//while (i<5) {
	//	std::cout << "안녕하세요" << std::endl;
	//	i++;
	//}

	//실습 1 구구단 만들기
	//std::cout << "5단만 출력"<<std::endl;
	//for (int i = 1; i < 10; i ++ ) {
	//	std::cout << "5 * " << i << " = " << 5 * i << std::endl;
	//}

	//for (int i = 1; i < 10; i++) {

	//	std::cout << "----" << i << "단 ----" << std::endl;

	//	for (int j = 1; j < 10; j++) {
	//		std::cout << i<<" * " << j << " = " << i * j << std::endl;
	//	}
	//}

	//std::cout<< std::endl;
	//std::cout << std::endl;

	////실습 2 1부터 n까지 합 구하기

	//int num;
	//int result = 0;
	//std::cout << "1부터 n까지의 합 구하기" << std::endl;
	//std::cout << "숫자(양의 정수)를 입력하세요 : ";
	//std::cin >> num;
	//

	//for (int i = 1; i <= num; i ++ ) {
	//	result += i;
	//}

	//std::cout << "1부터 "<< num<<"까지의 합은 : "<< result<< std::endl;
	//std::cout << std::endl;

	////실습3 while문 사용해보기
	//int cnt = 1;
	//std::cout << "5단만 출력 while" << std::endl;
	//while (cnt < 10) {
	//	std::cout << "5 * " << cnt << " = " << 5 * cnt << std::endl;
	//	cnt++;
	//}

	//cnt = 1;
	//while (cnt < 10) {
	//	num = 1;
	//	std::cout << "----" << cnt << "단 ----" << std::endl;
	//	while (num<10) {
	//		std::cout << cnt << " * " << num << " = " << cnt * num << std::endl;
	//		num++;
	//	}
	//	cnt++;
	//}
	//std::cout << std::endl;

	////실습 4 사용자가 입력한 숫자 더하기
	//std::cout << "사용자가 입력한 숫자 더하기" << std::endl;

	//result = 0;

	//while (true) 
	//{
	//	std::cout << "숫자를 입력하세요(0: exit) : ";
	//	std::cin >> num;

	//	result += num;
	//	if (num == 0) {
	//		std::cout << "사용자가 입력한 수의 합은 : "<< result << std::endl;
	//		break;
	//	}
	//}

	//번외 입력한 숫자만큼 별 찍기
	/*int c =0;
	std::cout << "input : ";
	std::cin >> c;

	std::cout << "output : \n";
	for (int i = 0; i < c; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}*/


	
}

