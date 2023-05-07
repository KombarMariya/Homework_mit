#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = "; cin >> n;   // размер массива
	int *a = new int[n];      // выделение памяти под массив
	for (int i = 0; i < n; i++) {     // заполнение массива элементами
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	int k = 0;  // счетчик
	for (int i = 0; i < n; i++) {    // перебор номеров элементов
		if (a[i] % 2 != 0 && a[i] % 3 != 0) {    // нечетные и не делятся на 3
			cout << i << endl;       // вывод номера
			k++;
		}
	}
	if (k == 0) {
		cout << "Таких элементов нет ";
	}
	return 0;
}
