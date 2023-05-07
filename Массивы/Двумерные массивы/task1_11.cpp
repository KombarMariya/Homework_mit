#include <iostream>
using namespace std;
// № 11
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;  // кол-во строк и столбцов
	int** a = new int*[n];     // выделение памяти под массив      
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> a[i][j];
		}
	cout << "Изначальная матрица" << endl;  // вывод изначальной матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	int k = 0, sum = 0;   // кол-во нечетных элементов и их сумма+
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((j <= i && j <= n - 1 - i) || (j >= i && j >= n - 1 - i)) {   // заштрихованная область
				if (a[i][j] % 2 != 0) {  // поиск нечетных элементов
					sum += a[i][j];
					k++;
				}
			}
		}
	}
	if (k == 0) {  
		cout << "Нечетных элементов нет" << endl;
	}
	cout << 1.0*sum / k;   // среднее арифметическое
	return 0;
}