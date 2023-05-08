#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n = "; cin >> n;
	float y1 = 0.9; 
	float y2 = 1.1;
	cout << "i = " << 1 << "    y = " << y1 << endl;  
	cout << "i = " << 2 << "    y = " << y2 << endl;
	for (int i = 3; i <= n; i++) {
		float y = y2 / i + (1.0 / (i * i)) * y1;
		y1 = y2;
		y2 = y;
		cout << "i = " << i << "    y = " << y << endl; 
	}

	return 0;
}