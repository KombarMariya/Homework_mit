#include <iostream>
#include <cmath>
using namespace std;


void moveDisk(int start, int end) {  // Функция для перемещения диска из начального стержня в конечный стержень
    cout << "Перемещение диска из стержня " << start << " в стержень " << end << endl;
}


void hanoi(int n, int start, int middle, int end) { // Функция для решения головоломки Ханойские башни
    if (n == 1) {  // случай, когда диск единственный
        moveDisk(start, end);
        return;
    }
    hanoi(n - 1, start, end, middle); // Рекурсивное перемещение n - 1 диска с начального стержня на средний стержень
    moveDisk(start, end); // Перемещение оставшегося n-го диска с начального стержня на конечный стержень
    hanoi(n - 1, middle, start, end);// Рекурсивное перемещение n - 1 диска с среднего стержня на конечный стержень
}

int main() {
    setlocale(LC_ALL, "russian");
    int n; // Количество дисков
    cout << "Введите количество дисков: ";
    cin >> n;
    hanoi(n, 1, 2, 3); // Вызов функции решения головоломки Ханойские башни
    cout << "Количество шагов: " << pow(2, n) - 1;
    return 0;
}