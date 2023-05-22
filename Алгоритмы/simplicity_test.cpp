// Определить является ли число простым, используя алгоритм Миллера - Рабина

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long power(long long a, long long b, long long m) {  // Функция возведения в степень по модулю
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {  // Если степень b нечетная
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1; // Делим степень b на два
    }
    return res;
}


bool miller_rabin(long long n, int k) {  
    if (n <= 2 || n % 2 == 0) { // Если n четно или меньше 2, то это не простое число
        return n == 2;
    }
  
    long long d = n - 1, s = 0;  // Находим d и s такие, что n - 1 = d * (2 ^ s)
    while (d % 2 == 0) {
        d >>= 1;
        ++s;
    }

    for (int i = 0; i < k; ++i) { // Проверка k раз
        long long a = 2 + rand() % (n - 2);  // Выбираем случайное число a в диапазоне [2, n-2]
        long long x = power(a, d, n); // Вычисляем x = a^d mod n
        if (x == 1 || x == n - 1) { // Если x == 1 или x == n-1, переходим к следующей итерации
            continue;
        }
        for (int j = 0; j < s - 1; ++j) { // Повторяем s-1 раз
            x = x * x % n;
            if (x == n - 1) { // Если x == n-1, переходим к следующей итерации
                break;
            }
        }

        if (x != n - 1) { // Если ни одно из предыдущих условий не выполняется, n является составным
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "russian");
    long long n;
    int k;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k: ";
    cin >> k;
    if (miller_rabin(n, k)) {
        cout << n << " простое" << endl;
    }
    else {
        cout << n << " составное" << endl;
    }
    return 0;
}