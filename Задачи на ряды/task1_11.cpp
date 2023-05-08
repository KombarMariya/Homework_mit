#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "n = "; cin >> n;
	float x, eps = 0.0001;
	cout << "x = "; cin >> x;
	float a = x; // начальные значения
	float S = a;
	cout << "i = " << 0 << "    a = " << a << "     S = " << S << endl;  // вывод 1 шага 
	for (i = 0; abs(a) > eps && i <= n; i++) {
		a *= ((-1)*(2 * i + 1)*x*x) / (2 * i + 3);   // d = an+1 / an
		S += a;    // сумма 
		cout << "i = " << i + 1 << "    a = " << a << "    S = " << S << endl;
	}
	if (i > n) {
		cout << "Расходится";
	}
	else {
		cout << S << " " << acos(x);
	}
	return 0;
}