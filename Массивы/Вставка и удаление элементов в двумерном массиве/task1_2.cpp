#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;   // кол-во строк и столбцов
	int** a = new int* [n];
	for (int i = 1; i <= n+n; i++)
		a[i] = new int[n];    // выделение памяти
	for (int i = 1; i < n + 1; i++)   // заполнение массива элементами
		for (int j = 1; j < n + 1; j++) {
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

	bool f;
	int row = n;   // кол-во строк в изначальной матрице
	for (int j = 1; j <= n; j++) {
		f = true;
		for (int i = 1; i <= row; i++) {
			if (a[j][i] % 2 == 0) {       // проверка на четность в каждой строке
				f = false;                // если элемент четный, переход на следующую строку
				break;
			}
		}
		if (f) { // если все элементы строки нечетные
			for (int l = n + 1; l > j; l--) {
				for (int k = 1; k <= row; k++) {
					a[l][k] = a[l - 1][k];
				}
			}
			n++;
			j++;
		}
	}
	cout << endl;
	cout << "Результат" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= row; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}