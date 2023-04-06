#include <iostream>
#include <vector>
#include <format>
#include<string>


using namespace std;
int main()
{
	int n = 0;

	while (n % 2 == 0) {
		cout << "홀 수만 입력 하세요 : ";
		cin >> n;
	}

	if (n == 1) {
		cout << n;
		return 0;
	}

	vector < vector<int>> arr(n, vector<int>(n,0));
	int startX = 0;
	int startY = (n / 2);

	for (int i = 1; i <= n * n; i++) {
		arr[startX][startY] = i;

		if (i % n == 0) {
			startX++;
		}
		else {
			startX= startX-1 < 0 ? n-1: startX-1;
			startY++;
		}

		//배열 범위 넘어가지 않게 확인
		startX = startX % n;
		startY = startY % n;
	}

	for (auto v : arr) {
		for (auto a : v) {
			
			cout.width(to_string(n*n).size());
			cout.fill('0');
			cout << a << " ";
		}

		cout << endl;
	}
}
