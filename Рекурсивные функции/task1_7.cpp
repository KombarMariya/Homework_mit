#include <iostream>
using namespace std;
int A(int n, int m) {
    if (n == 1) {
        return m;
    }
    return (m - n + 1) * A(n - 1, m);  
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    cout << "Введите n: ";  
    cin >> n;  // ввод n
    cout << "Введите m: ";
    cin >> m;  // ввод m
    cout << A(n, m);  // вывод функции 
    return 0;
}