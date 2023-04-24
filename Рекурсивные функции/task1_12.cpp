#include <iostream>
using namespace std;
int bindec(long long n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + 2 * bindec(n / 10);
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите n: ";
    cin >> n;  // ввод числа в двоичной системе
    cout << bindec(n);  // вывод числа в десятичной системе
}