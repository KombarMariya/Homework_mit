#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n = "; cin >> n;   // размер массива
	int *a = new int[n];     // выделение памяти под массив
	srand((unsigned)time(NULL));   // начальная точка генерации
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 50;     // случайное число от 0 до 49
		cout << a[i] << " ";
	}
	cout << endl;
	int b, c;
	cout << "b = "; cin >> b;    // ввод диапазона
	cout << "c = "; cin >> c;
	if (b > c) swap(b, c);      //замена значений, если b > c
	int k = 0;     // кол-во нечетных элементов
	int sum = 0;   // сумма нечетных элементов
	for (int i = 0; i < n; i++) {       // поиск нечетных элементов, не попадающих в диапазон
		if (a[i] % 2 != 0 && (a[i] < b || a[i] > c)) {
			k++;
			sum += a[i];
		}
	}
	if (k == 0) {
		cout << "Таких элементов нет\n";
	}
	else {
		cout << "Среднее арифметическое: " << 1.0*sum / k << endl;
	}
	return 0;
}
