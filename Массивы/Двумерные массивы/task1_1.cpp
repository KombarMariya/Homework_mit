#include <iostream>
using namespace std;
// № 1
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;   // ввод кол-ва строк и столбцов
	int** a = new int*[n];      // выделение памяти под массив
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)    // заполнение массива элементами
		for (int j = 0; j < n; j++) {
			cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> a[i][j];
		}
	cout << endl;
	cout << "Изначальная матрица" << endl;  // вывод изначальной матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n / 2; i++) {  // меняем первую строку с последней и т.д.
		for (int j = 0; j < n; j++) {
			swap(a[i][j], a[n - 1 - i][j]);
		}
		cout << endl;
	}
	cout << "Новая матрица" << endl;  // вывод новой матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}