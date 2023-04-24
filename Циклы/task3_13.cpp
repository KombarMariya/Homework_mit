#include <iostream> 
#include <cmath> 
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	float a, b, h;
	const float eps = 0.0001;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "h = ";
	cin >> h;
	if (a > b) swap(a, b);  //проверка корректности или замена
	for (float x = a; x < b + h; x += h)
		if ((x > -1 && x < 1) || abs(x - 1) < eps || abs(x + 1) < eps) {
			cout << "x = " << x << " Логарифм из неположительного числа\n";
		}
		else if (abs(x - 2) < eps) {
			cout << "x = " << x << " Деление на ноль\n";
		}
		else {
			float y = (log(x * x - 1)) / (sqrt(x * x - 4 * x + 4)); 
			cout << "x = " << x << " y = " << y << endl;  // вывод
		}
	return 0;

}