#include <iostream>
#include <climits>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = "; cin >> n;      // размер массива
	int *a = new int[n];           // выделение памяти под массив
	for (int i = 0; i < n; i++) {        // заполнение массива элементами
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	int max = INT_MIN;   
	for (int i = 0; i < n; i++) {      // поиск максимального четного элемента
		if (a[i] % 2 == 0 && a[i] > max) {
			max = a[i];
		}
	}
	if (max == INT_MIN) {       // отсутствие четных элементов в массиве
		cout << "Четных элементов нет\n";
	}
	for (int i = 0; i < n; i++) {    
		if (a[i] == max) {
			cout << i << " ";   // вывод номера максимальных элементов
		}
	}

	return 0;
}