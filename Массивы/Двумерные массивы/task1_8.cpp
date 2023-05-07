#include <iostream>
using namespace std;
// № 8
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;   // кол-во строк и стобцов 
	int** a = new int*[n];    // выделение памяти под массив
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
	int min = a[0][0], max = a[0][0];  // начальные значения для min, max
	int n_min = 0, n_max = 0;          // номера строк
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min) {     // первый min
				min = a[i][j];
				n_min = i;         // номер строки c min
			}
			if (a[i][j] >= max) {    // последний max
				max = a[i][j];
				n_max = i;       // номер строки с max
			}
		}
	}
	for (int j = 0; j < n; j++) {          // обмен строк
		swap(a[n_min][j], a[n_max][j]);
	}

	cout << endl;
	cout << "Новая матрица" << endl;      // вывод новой матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}
