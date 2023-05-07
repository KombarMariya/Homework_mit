#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = "; cin >> n;    // размер массива
	int *a = new int[n];         //выделение памяти под массив
	for (int i = 0; i < n; i++) {       // заполнение массива элементами
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	int n_min = 0;
	for (int i = 1; i < n; i++) {       // поиск номера первого минимального элемента
		if (a[i] < a[n_min]) {
			n_min = i;
		}
	}
	int n_max = 0;
	for (int i = 1; i < n; i++) {      // поиск номера последнего максимального элемента 
		if (a[i] >= a[n_max]) {
			n_max = i;
		}
	}
	swap(a[n_min], a[n_max]);         // замена местами мин и макс элементов
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}