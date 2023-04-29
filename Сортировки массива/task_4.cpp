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
vector <int> korzina;
ifstream in("matrica.txt");
ofstream out("smatrica.txt");

vector <int> bloksort(vector<int>& numbers, int N, int mmax, int mmin) { // блочная сортировка
    int kol_korzin = 4; // количество корзин 
    vector <int> korzina0, korzina1, korzina2, korzina3; // определение векторов-корзин
    int m = (mmax - mmin) / kol_korzin; // диапазон чисел в корзине 
    cout << "mmax=" << mmax << endl;
    cout << "mmin=" << mmin << endl;
    for (int j = 0; j < N; j++) { // распределение чисел по корзинам
        int k = (numbers[j] - mmin) / m; // номер корзины
        if (k==0) {
            korzina0.push_back(numbers[j]); 
        }
        if (k==1) { 
            korzina1.push_back(numbers[j]);
        }
        if (k==2) { korzina2.push_back(numbers[j]);
        }
        if (k==3) {
            korzina3.push_back(numbers[j]);
        }  
        if (k==4) { korzina3.push_back(numbers[j]); 
        }
    }
    //сортировка корзин
    sort(korzina0.begin(), korzina0.end());
    sort(korzina1.begin(), korzina1.end());
    sort(korzina2.begin(), korzina2.end());
    sort(korzina3.begin(), korzina3.end());

    //перезаписываем все корзины в одну в обратном порядке
    korzina.insert(korzina.end(), korzina3.rbegin(), korzina3.rend());
    korzina.insert(korzina.end(), korzina2.rbegin(), korzina2.rend());
    korzina.insert(korzina.end(), korzina1.rbegin(), korzina1.rend());
    korzina.insert(korzina.end(), korzina0.rbegin(), korzina0.rend());
  
    korzina0.clear();
    korzina1.clear();
    korzina2.clear();
    korzina3.clear();
    return korzina;
}

int maximum(vector<int>& arr, int size) { // поиск максимума
    int max;
    max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minimum(vector<int>& arr, int size) {  // поиск минимума
    int min;
    min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int razm = 9; // размерность матрицы
    vector <int> a; // вектор строки матрицы
    int b[9][9]; // промежуточный массив всех чисел из файла
        while (in.peek() != EOF) { // выполняется, пока не закончится файл
            for (int i = 0; i < razm; i++) {
                for (int j = 0; j < razm; j++) {
                    in >> b[i][j];
                    cout << "b[" << i<<"," << j << "]=" << b[i][j] << " " << endl;
                }
            }
        }
        for (int k = 0; k < razm; k++) {
            for (int j = 0; j < razm; j++) { 
                a.push_back(b[k][j]);
                cout << "a[" << j << "]=" << a[j] << " " << endl;
            }
            bloksort(a, razm, maximum(a, razm), minimum(a, razm));
            for (int i = 0; i < razm; i++) { // запись в файл
                out << korzina[i] << " ";
            }
            out << endl;
            a.clear();
            korzina.clear();
        }
    return 0;
}



