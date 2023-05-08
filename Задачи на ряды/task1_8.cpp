#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "n = "; cin >> n;
	float x, eps = 0.0001;
	cout << "x = "; cin >> x;
	float a = 1; // начальные значения
	float S = a;
	cout << "i = " << 0 << "    a = " << a << "     S = " << S << endl;  // вывод 1 шага 
	for (i = 1; abs(a) > eps && i <= n; i++) {
		a *= -x;   // d = -x : d = an / an-1 = -x / 1 = -x
		S += a;    // сумма 
		cout << "i = " << i << "    a = " << a << "    S = " << S << endl;
	}
	if (i > n) {
		cout << "Расходится";
	}
	else {
		cout << S << " " << 1 / (1 + x);
	}
	return 0;
}