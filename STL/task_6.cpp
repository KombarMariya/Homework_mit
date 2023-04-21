#include <iostream>
#include <vector>
#include<numeric>
#include <algorithm>
using namespace std;
bool chet(int x) {   // четные
    return x % 2 == 0;
}
int X; 
bool nekratn(int x) { // не кратный X
    return x % X != 0;
}

int main() {
    setlocale(LC_ALL, "russian");
    vector <int> vec;
    int x, n;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {  // создание вектора
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    cout << "X = "; cin >> X;
    vector <int> temp(vec); // копия вектора
    replace_if(temp.begin(), temp.end(), nekratn, 0); // замена
    cout << "Сумма элементов, кратных X " << endl;
    cout << "sum = " << accumulate(temp.begin(), temp.end(), 0) << endl;

    int Min = *min_element(vec.begin(), vec.end());  // минимальный элемент
    int Max = *max_element(vec.begin(), vec.end());  // максимальный элемент
    cout << "Минимальный элемент: " << Min << endl;
    replace_if(vec.begin(), vec.end(), chet, Max);   // четные элементы заменяются на максимальный элемент
    cout << "Результат после замены четных на максимальный " << endl;
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод
        cout << *iter << " ";
    cout << endl;
    return 0;
}