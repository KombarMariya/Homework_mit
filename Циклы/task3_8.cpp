#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите n: ";
	cin >> n;
	int a = 0;
	int j = 0;
	int b = 0;    // b - значение a с предыдущего шага
	for (int i = 0; i <= n; ++i) {
		a = b + j;
		b = a;  
		if (i == 0) {
			j = 1;
		}
		else {
			j = j + 2;
		}
		cout << "i = " << i << "   a = " << a << endl; // вывод
	}
	return 0;
}
