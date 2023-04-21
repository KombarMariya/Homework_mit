#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool nechet(int x) {   // нечетные
    return x % 2 != 0;
}
int main() {
    vector <int> vec;
    int x, n;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {  // создание вектора
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }
    replace_if(vec.begin(), vec.end(), nechet, 0);  // замена нечетных на 0

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод
        cout << *iter << " ";
    cout << endl;
    return 0;
}