// 1 задача
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
	cout << "введите целое число ";
	cin >> i;
	int n = 1 << i; // единица сдвигается на i битов влево, i - кол-во нулей
	cout << n;
	return 0;
}
/* Пример: 2**15 это 1 и 15 нулей */


// 2 задача
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "Введите целое число n ";
	cin >> n;
	cout << "Введите целое число i ";
	cin >> i;
	n = n | (1 << i);
	cout << n;
	return 0;
}
/* Пример: 
n = 9  1001 
i = 1  0001
1001
|
0010
------
1011    равно 11
*/


// 3 задача
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "Введите целое число n ";
	cin >> n;
	cout << "Введите целое число i ";
	cin >> i;
	n = n & ~(i << 1);
	cout << n;
	return 0;
}
/* Пример:
n = 11  1011
i = 1  0001
1011
&
1101
-------
1001   равно 9   
*/





// 4 задача
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "Введите целое число n ";
	cin >> n;
	cout << "Введите целое число i ";
	cin >> i;
	n = n ^ (1 << i);
	cout << n;
	return 0;

}
/* Пример:
n = 5  0101
i = 3  0011
0101
^
1000
------
1101   равно 13
*/



// 5 задача
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n, y;
	cout << "введите целое число n ";
	cin >> n;
	y = n >> 1;
	if (n == (y << 1)) {
		cout << "четное";
	}
	else {
		cout << "нечетное";
	}
}
/* 5 задача
Пример с четным:
n = 20     10100
y = 10     01010
10100 равно 10100 - 20 четное
Пример с нечетным:
n = 11     1011
y = 5      0101
1011 не равно 1010 - 11 нечетное */






