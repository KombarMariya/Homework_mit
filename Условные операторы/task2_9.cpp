#include <iostream>
#include <math.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	float X;
	cout << "Введите число ";
	cin >> X;
	const float eps = 0.00001;
	if (abs(X + 3) < eps || abs(X - 3) < eps) {
		cout << "Деление на ноль ";
	}
	else if (abs(X + 1) < eps) {
		cout << "Логарифм из неположительного числа ";
	}
	else if ((X < 3) || ((X > 3) && (X < 5))) {
		cout << "Корень из отрицательного числа ";
	}
	else {
		float F = sqrt((X - 5) / (X*X - 9)) + log(X*X + 2 * X + 1);
		cout << F;
	}
	return 0;
}