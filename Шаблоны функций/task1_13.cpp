#include <iostream>
using namespace std;
template <typename X>
X** create(X c, int n, int m) {   //создание
    X** a = new X * [n];         //выделение памяти
    for (int i = 0; i < n; i++)
        a[i] = new X[m];
    for (int i = 0; i < n; i++)      //ввод массива
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

template <typename X>
void print(X** a, int n, int m) {        //печать
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}
template <typename X>
void zadanieArray(X** a, int n, int m) {    // меняется местами первая строка и строка, сумма элементов которой максимальна
    float s = 0; float s_max = 0; int n_i = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s = s + a[i][j];
        }
        if (s > s_max) {
            s_max = s;
            n_i = i;
        }
        s = 0;
    }
    for (int j = 0; j < m; j++) {
        swap(a[0][j], a[n_i][j]);
    }
    cout << endl;
    for (int i = 0; i < n; i++, cout << endl)        // печать нового массива
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}
int main() {
    int n; int m;
    cout << "n = "; cin >> n;      // ввод кол-ва строк
    cout << "m = "; cin >> m;      // ввод кол-ва столбцов

    int c = 1;      //определение для int
    cout << "Input int matrix: " << endl;
    int** a = create(c, n, m);
    print(a, n, m);
    zadanieArray(a, n, m);
    double d = 1;     //определение для double
    cout << "Input double matrix: " << endl;
    double** a1 = create(d, n, m);
    print(a1, n, m);
    zadanieArray(a1, n, m);
    return 0;
}