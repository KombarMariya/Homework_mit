#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "n = "; cin >> n;   // кол-во элементов массива
	int x;
	cout << "x = "; cin >> x;
	int *a = new int[n];      // выделение памяти
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];          // заполнение массива элементами
	}

	cout << endl;
	int m = 0;   // счетчик нечетных элементов
	for (int i = 0; i <= n - 1; i++) {
		if ((a[i] % 2) != 0) {      // поиск нечетных элементов
			m++;
		}
	}

	int k = n - 1;  // индекс последнего элемента 

	for (int j = n - 1 + m; j > 0; j--) {  // n - 1 + m - индекс последнего элемента + кол-во нечетных элементов
		a[j] = a[k];
		if ((a[k] % 2) != 0) {   // проверка на четность
			a[j - 1] = x;        // перед нечетным ставится число x
			j--;
		}
		k--;
	}

	cout << "Результат" << endl;
	for (int i = 0; i < n + m; i++) {
		cout << a[i] << " ";
	}

	return 0;
}