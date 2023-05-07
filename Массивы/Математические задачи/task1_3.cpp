#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = ";  // кол-во строк треугольника Паскаля
	cin >> n;
	int **a = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		a[i] = new int[n + 1];  // выделение памяти под i-ую строку
	}
	// Заполнение массива
	a[0][0] = 1;
	a[1][0] = a[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i][0] = 1;
		for (int j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
		a[i][i] = 1;
	}
	// Вывод массива
	cout << "коэф. P(x)" << endl;
	for (int i = 0; i <= n; i++, cout << endl) {
		for (int j = 0; j <= i; j++) {
			cout << a[i][j] << " ";
		}
	}
	cout << endl;
	int **b = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		b[i] = new int[n + 1];   // выделение памяти
	}
	// Заполнение массива производных коэф. многочлена
	b[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		b[i][i] = 0;
		for (int j = 1; j <= i; j++) {
			b[i][j - 1] = j * a[i][j];
		}
	}
	// Вывод массива
	cout << "коэф. P'(x)" << endl;
	for (int i = 0; i <= n; i++, cout << endl) {
		for (int j = 0; j <= i; j++) {
			cout << b[i][j] << " ";
		}
	}
	cout << endl;
	// сложение массивов коэф. и производных коэф.
	cout << "коэф. P(x) + P'(x)" << endl;
	for (int i = 0; i <= n; i++, cout << endl) {
		for (int j = 0; j <= i; j++) {
			cout << b[i][j] + a[i][j] << " ";
		}
	}
	return 0;
}