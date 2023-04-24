#include<iostream>
using namespace std;
int main() {
	const int N = 4;  // кол-во блоков
	for (int i = 1; i <= N; i++) {   // блоки
		for (int j = 1; j <= i; j++) //нечетные строки
			cout << i << " ";
		cout << endl;
		for (int j = 1; j <= i; j++) //четные строки
			cout << 11 - 2 * i << " ";
		cout << endl;
	}
	return 0;
}