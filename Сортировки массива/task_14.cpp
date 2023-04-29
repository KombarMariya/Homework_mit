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

void vibor(vector<int>& vec) {  // подпрограмма сортировки выбором
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        auto min = it;
        for (auto i = it + 1; i != vec.end(); ++i) { // находим минимум из элементов массива
            if (*i < *min)
                min = i;
        }
        std::swap(*it, *min); // меняем местами минимальный элемент и i-тый элемент
    }
}

int main() {
    int razm = 9; // размерность матрицы
    int b[9][9]; // 2-мерный массив всех чисел из файла
    while (in.peek() != EOF) { // выполняется, пока не закончится файл
        for (int i = razm-1; i >= 0; i--) {
            for (int j = razm-1; j >= 0; j--) {
                in >> b[j][i]; // запись всех чисел из файла в массив b 
                cout << "b[" << j << "," << i << "]=" << b[j][i] << " " ;
            }
            cout<< endl;
        }
    }
    for (int k = 1; k < razm - 1; k++) { // k - номер диагоналии
        vector <int> a; // создаем вектор
        for (int i = 0; i < razm; i++) {
            if ((k + i) < razm) {
                a.push_back(b[i][k + i]); // добавляем в вектор a из массива b элемент b[i][k + i]
            }
        }
        //сортируем полученный вектор
        vibor(a); // вызываем функцию сортировки 
        int l = 0;
        for (int i = 0; i < razm; i++) {
            if ((k + i) < razm) {
                b[i][k + i]=a[l]; // элемент массива равен l элементу вектора
                l++;
            }
        }
        //очищаем вектор
        a.clear();

        for (int j = 0; j < razm; j++) {
            if ((k + j) < razm) {
                a.push_back(b[k + j][j]); // добавляем в вектор a из массива b элемент b[k+j][j]
            }
        }
        //сортируем полученный вектор
        vibor(a); // вызываем функцию сортировки 
        l = 0;
        for (int j = 0; j < razm; j++) {
            if ((k + j) < razm) {
                b[k + j][j]=a[l]; // элемент массива равен l элементу вектора
                l++;
            }
        }
        a.clear(); //очищаем вектор
    } 
    for (int i = razm - 1; i >= 0; i--) { // запись в выходящий файл отсортированного массива 
        for (int j = razm - 1; j >= 0; j--) {
            out << b[j][i] << " "; // элементы массива через пробел
         }
        out << endl; // переход на следующую строку
    }
    return 0;
}



