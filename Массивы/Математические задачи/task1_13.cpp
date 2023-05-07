#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int k; cout << "k = ";         // кол-во строк треугольника Паскаля
	cin >> k;
	int **a = new int *[k + 1];
	for (int i = 0; i <= k; i++) {
		a[i] = new int[k + 1];     // выделение памяти   
	}
	// Заполнение массива
	a[0][0] = 1;
	a[1][0] = a[1][1] = 1;
	for (int i = 2; i <= k; i++) {
		a[i][0] = 1;
		for (int j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
		a[i][i] = 1;
	}

	// вычисление 2^k
	int S = 0;
	for (int i = 0; i <= k; i++) {
		if (i == k) {
			for (int j = 0; j <= i; j++) {
				S += a[i][j];
			}
		}
	}
	cout << S;   // вывод 2^k

	return 0;

}