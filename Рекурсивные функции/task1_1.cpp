#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 1 || n == 0) return 1;
    return n * factorial(n - 1);
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите число n" << endl;
    cout << "n = ";
    cin >> n;    // ввод числа
    cout << n << "! = " << factorial(n);   // вывод факториала числа
    return 0;
}

