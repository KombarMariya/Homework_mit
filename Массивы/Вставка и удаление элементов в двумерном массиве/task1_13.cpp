#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;   // кол-во строк и столбцов
	int x;
	cout << "x = "; cin >> x;   // элемент x
	int** a = new int*[n + 1];  // выделение памяти
	for (int i = 1; i <= n; i++)
		a[i] = new int[n];
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

	int b = 0;   // кол-во элементов, равных x, в каждой строке
	int k = 1;

	for (int i = 1; i <= n; i++) {
		b = 0;
		for (int l = 1; l <= n; l++) {  // поиск в строке элемента, равного x
			if (a[i][l] == x) {
				b++;
			}
		}
		if (b == 0) {   // если отсутствует в строке элемент, равный x 
			for (int j = 1; j <= n; j++) {
				a[k][j] = a[i][j];
			}
			k++;
		}

	}
	cout << endl;
	cout << "Результат" << endl;
	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
