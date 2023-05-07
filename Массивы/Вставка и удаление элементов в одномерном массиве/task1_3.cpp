#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = "; cin >> n;    // кол-во элементов в массива
	int *a = new int[n];         // выделение памяти
	srand((unsigned)time(NULL));
	cout << "Изначальный массив" << endl;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 50;         // заполнение массива случайными числами
		cout << a[i] << " ";
	}
	cout << endl;
	int k = 0;
	int b = 0; // счетчик нечетных элементов
	for (int i = 0; i < n; i++) {
		if ((a[i] % 2) != 0) {   // проверка на четность
			b++;
			a[k] = a[i];  // сдвиг нечетных элементов
			k++;
		}
	}
	cout << endl;
	cout << "Результат" << endl;
	for (int i = 0; i < b; i++) {
		cout << a[i] << ' ';
	}


	return 0;
}