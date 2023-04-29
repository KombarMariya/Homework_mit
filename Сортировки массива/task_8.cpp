#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <list>
#include <algorithm>

using namespace std;
ifstream in("matrica.txt");
ofstream out("smatrica.txt");


void slianie(int* a, int l, int r) { // Функция сортировки слиянием
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    slianie(a, l, mid); // рекурсивно вызываем функцию сортировки для каждой половины
    slianie(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int* buf = new int[r - l + 1]; // создание дополнительного массива 
    for (int step = 0; step < r - l + 1; step++) { // для всех элементов дополнительного массива
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > r) || ((i <= mid) && (a[i] < a[j]))) {
            buf[step] = a[i];
            i++;
        }
        else {
            buf[step] = a[j];
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; step++)
        a[l + step] = buf[step];
}

int main() {
    int razm = 9; // размерность матрицы
    int a [9]; //  массив строки матрицы
    int b [9][9]; // промежуточный 2-мерный массив всех чисел из файла
    int poryadok = 0; // переменная-указатель, что строка кратна 3
    while (in.peek() != EOF) { // выполняется, пока не закончится файл
        for (int i = 0; i < razm; i++) {
            for (int j = 0; j < razm; j++) {
                in >> b[i][j]; // запись всех чисел из файла в массив b 
            }
        }
    }
    for (int k = 0; k < razm; k++) { // по строкам матрицы 
        for (int j = 0; j < razm; j++) {
            a[j]=b[k][j]; // запись в одномерный массив a строки из промежуточного массива b
            cout << "a[" << j << "]=" << a[j] << " " << endl;
        }
        poryadok++;
        slianie(a, 0, razm - 1); // вызываем функцию сортировки  
        if (poryadok % 3 == 0) {   // каждая третья строка по убыванию
            for (int i = razm - 1; i >= 0; i--) { // запись в файл
                out << a[i] << " ";
            }
        }
        else {    // все остальные строки по возрастанию
            for (int i = 0; i < razm; i++) { // запись в файл
                out << a[i] << " ";
            }
        }
        out << endl;
    }
    return 0;
}



