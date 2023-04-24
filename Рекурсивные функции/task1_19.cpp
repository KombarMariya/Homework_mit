#include <iostream>
using namespace std;
void printer(int n, char a) {  // печать символов
	for (int i = 0; i < n; i++) {
		cout << a;
	}
}
void F(int p, int n, char a, int b) {  
	if (b > 0) {
		printer(p, ' ');   // печать пробелов
		printer(n, '*');   // печать *
		cout << endl;      // переход на следующую строку
		F(p - 1, n + 2, a, b - 1);    // вызов функции для следующей строки
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int b;   // кол-во строк в блоке
	int N;  // кол-во блоков
	cout << "Введите число блоков \n";
	cin >> N;
	b = 2;
	for (int i = 1; i <= N; i++) {   // печать блока
		F(N + N, 1, '*', b);    // вызов функции
		b++;
	}
	return 0;
}