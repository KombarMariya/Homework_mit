#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "n = "; cin >> n;  // кол-во элементов массива
	int x;
	cout << "x = "; cin >> x;
	int y;
	cout << "y = "; cin >> y;
	int *a = new int[n];   // выделение памяти
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];      // заполнение массива элементами
	}

	int m = 0;   // счетчик элементов, равных x
	for (int i = 0; i <= n - 1; i++) {
		if (a[i] == x) {    // поиск элементов, равных x
			m++;
		}
	}

	int k = n - 1;    // индекс последнего элемента 

	for (int j = n - 1 + m; j > 0; j--) {    // n - 1 + m - индекс последнего элемента + кол-во элементов, равных x
		a[j] = a[k];
		if (a[k] == x) {      // проверка на равенство
			a[j - 1] = y;     // перед элементом, равным x, ставится число y
			j--;
		}
		k--;
	}

	cout << endl;
	cout << "Результат" << endl;
	for (int i = 0; i < n + m; i++) {
		cout << a[i] << " ";
	}


	return 0;
}