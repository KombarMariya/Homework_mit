#include <iostream>
using namespace std;
template <typename X>
X** create(X c, int n, int m) {  //создание
    X** a = new X * [n];       //выделение памяти
    for (int i = 0; i < n; i++)
        a[i] = new X[m];
    for (int i = 0; i < n; i++)   //ввод массива
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

template <typename X>
void print(X** a, int n, int m) {   //печать
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}
template <typename X>
void zadanieArray(X** a, int n, int m) {    // столбцы меняются местами: первый с последним, второй с предпоследним и т.д.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            swap(a[i][j], a[i][m - 1 - j]);

        }
    }
    cout << endl;
    for (int i = 0; i < n; i++, cout << endl)   // печать нового массива
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}
int main() {
    int n; int m;
    cout << "n = "; cin >> n;  // ввод кол-ва строк
    cout << "m = "; cin >> m;  // ввод кол-ва столбцов

    int c = 1;  //определение для int
    cout << "Input int matrix: " << endl;
    int** a = create(c, n, m);
    print(a, n, m);
    zadanieArray(a, n, m);
    double d = 1;  //определение для double
    cout << "Input double matrix: " << endl;
    double** a1 = create(d, n, m);
    print(a1, n, m);
    zadanieArray(a1, n, m);
    char d1 = '1';  //определение для double
    cout << "Input char matrix: " << endl;
    char** a2 = create(d1, n, m);
    print(a2, n, m);
    zadanieArray(a2, n, m);
    return 0;
}