// Дано множество точек на плоскости. Найти такую, сумма расстояний от которой до всех остальных максимальна.


#include <iostream>
#include <math.h>
using namespace std; 
struct point {  // структура точка
    double x, y;
};
point* create(int& n) {  // создание массива точек
    cout << "n = ";
    cin >> n;   // кол-во точек
    point * a = new point[n]; // массив точек
    for (int i = 0; i < n; i++) {
        cout << "Input " << i << " point coordinates (x, y): \n";
        cin >> a[i].x >> a[i].y;   // координаты точек
    }
    return a;
}
double dlina(point a, point b) { // растояние между двумя точками
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double summa(point* a, int n) {   // сумма расстояний от точки до других точек
    double summa = 0;
    for (int i = 0; i < n; i++) {
        summa = summa + dlina(a[i], a[i + 1]);
    }
    return summa;
}
int main() {
    int n;
    point* a = create(n);
    double max_summa = 0;
    double max_x;
    double max_y;
    for (int i = 0; i < n; i++) {   // поиск максимальной суммы и координат точки
        if (max_summa < summa(a, n)) {
            max_summa = summa(a, n);
            max_x = a[i].x;
            max_y = a[i].y;
        }
    }
    cout << "point coordinates x = " << max_x << endl;
    cout << "point coordinates y = " << max_y << endl;
    cout << "max_summa = " << max_summa << endl;
}

