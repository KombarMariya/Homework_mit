#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = "; cin >> n;   // кол-во элементов массива
	int *a = new int[n];     // выделение памяти
	srand((unsigned)time(NULL));
	cout << "Изначальный массив" << endl;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 300;      // заполнение массива случайными числами
		cout << a[i] << " ";
	}
	cout << endl;
	int k = 0;
	int b = 0;   // счетчик недвузначных элементов
	for (int i = 0; i < n; i++) {
		if ((9 >= a[i]) || (a[i] >= 100)) {   // поиск недвузначных элементов
			b++;
			a[k] = a[i];  // сдвиг недвузначных элементов
			k++;
		}
	}
	cout << endl;
	cout << "Результат" << endl;
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";
	}


	return 0;
}
