#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;   // кол-во строк и столбцов
	int** a = new int* [n + 1];
	for (int i = 1; i <= n; i++)
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
	int column = n;   // кол-во столбцов в изначальной матрице
	for (int i = 1; i <= n; i++) {
		f = true;
		for (int j = 1; j <= column; j++) {
			if (a[j][i] % 2 != 0) {       // проверка на четность в каждом столбце
				f = false;                // если элемент нечетный, переход на следующий столбец
				break;
			}
		}
	
		if (f) { // если все элементы столбца четные
			for (int j = n + 1; j > i; j--) {
				for (int k = 1; k <= column; k++) {
					a[k][j] = a[k][j - 1];
				}
			}
			n++;  
			i++;  
		}
	}
	cout << endl;
	cout << "Результат" << endl;
	for (int i = 1; i <= column; i++) {
		for (int j = 1; j <= n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
