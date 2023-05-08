#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	cout << "1. Круг\n2. Квадрат\n3. Треугольник\n4. Прямоугольник\n";  // меню
	int a; 
	cout << "Введите номер фигуры ";
	cin >> a;
	if (a == 1) { // круг
		float r;
		cout << "Введите радиус круга ";
		cin >> r;
		float S = M_PI * (r*r);
		float P = 2 * M_PI*r;
		cout << "Площадь круга " << S << endl;
		cout << "Периметр круга " << P;
	}
	else if (a == 2) { // квадрат
		float b;
		cout << "Введите сторону квадрата ";
		cin >> b;
		float S = b * b;
		float P = 4 * b;
		cout << "Площадь квадрата " << S << endl;
		cout << "Периметр квадрата " << P;
	}
	else if (a == 3) { //треугольник
		float x, y, z;
		cout << "Введите первую сторону треугольника ";
		cin >> x;
		cout << "Введите вторую сторону треугольника ";
		cin >> y;
		cout << "Введите третью сторону треугольника ";
		cin >> z;
		if (x + y <= z || x + z <= y || z + y <= x) {  // проверка на существование треугольника
			cout << "Не существует треугольника ";
		}
		else {
			float P = x + z + y;
			float Pl = P / 2;
			float S = sqrt(Pl*(Pl - x)*(Pl - y)*(Pl - z));

			cout << "Площадь треугольника " << S << endl;
			cout << "Периметр треугольника " << P;
		}
	}
	else if (a == 4) { // прямоугольник
		float d, h;
		cout << "Введите длину прямоугольника ";
		cin >> d;
		cout << "Введите ширину прямоугольника ";
		cin >> h;
		float S = d * h;
		float P = 2 * (d + h);
		cout << "Площадь прямоугольника " << S << endl;
		cout << "Периметр прямоугольника " << P;
	}
	system("pause");
	return 0;

}
