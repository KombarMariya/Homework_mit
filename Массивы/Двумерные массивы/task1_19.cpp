#include <iostream>
using namespace std;
// № 19

int main() {
	setlocale(LC_ALL, "Russian");
	int n, k, snake = 0;
	cout << "n = "; cin >> n;     // кол-во строк и стобцов 
	int** a = new int*[n];        // выделение памяти под массив
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	k = 0;  // счетчик столбцов
	for (int j = 0; j < n; j++) {
		if (k++ % 2 != 0) {    // если счетчик столбцов - нечетное число
			for (int i = n - 1; i >= 0; i--) {
				a[i][j] = snake++;  // заполнение матрицы элементами (по строкам, нечетные столбцы)
			}
		}
		else {    // если счетчик столбцов - четное число
			for (int i = 0; i < n; i++) {
				a[i][j] = snake++;    // заполнение матрицы элементами (по строкам, четные столбцы)
			}
		}
	}
	cout << "Результат" << endl;   // вывод матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}