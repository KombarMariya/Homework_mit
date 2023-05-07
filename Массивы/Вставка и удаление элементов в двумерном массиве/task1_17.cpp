#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;   // кол-во строк и столбцов
	int** a = new int*[n + 1];
	for (int i = 1; i <= n; i++)
		a[i] = new int[n];    // выделение памяти
	for (int i = 1; i <= n; i++)   // заполнение массива элементами
		for (int j = 1; j <= n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << endl;
	cout << "Изначальная матрица" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}

	int b = 0;    // кол-во четных элементов в каждом столбце
	int k = 1;

	for (int j = 1; j <= n; j++) {
		b = 0;
		for (int l = 1; l <= n; l++) {   
			if (a[l][j] % 2 == 0) {      // подсчет четных элементов в каждом столбце
				b++;
			}
		}

		if (b != n) {   // если в столбце не все элементы четные
			for (int i = 1; i <= n; i++) {
				a[i][k] = a[i][j];
			}
			k++;
		}

	}

	cout << endl;
	cout << "Результат" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < k; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
