#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool nechet(int x) {   // нечетные
    return x % 2 != 0;
}
bool chet(int x) {   // четные
    return x % 2 == 0;
}
int main() {
    setlocale(LC_ALL, "russian");
    vector <int> vec1;
    int x, n;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {  // создание первой последовательности
        cout << "a[" << i << "] = ";
        cin >> x;
        vec1.push_back(x);
    }
    vector <int> vec2;
    int y, m;
    cout << "m = ";
    cin >> m;
    for (int i = 0; i < m; i++) {  // создание второй последовательности
        cout << "a[" << i << "] = ";
        cin >> y;
        vec2.push_back(y);
    }
    cout << "Удаление четных элементов первой последовательности: " << endl;
    vector<int>::iterator it1 = remove_if(vec1.begin(), vec1.end(), chet);
    vec1.erase(it1, vec1.end());
    for (vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); it1++) 
        cout << *it1 << " ";
    cout << endl;

    cout << "Удаление нечетных элементов второй последовательности: " << endl;
    vector<int>::iterator it2 = remove_if(vec2.begin(), vec2.end(), nechet);
    vec2.erase(it2, vec2.end());
    for (vector<int>::iterator it2 = vec2.begin(); it2 != vec2.end(); it2++) 
        cout << *it2 << " ";
    cout << endl;

    cout << "Сортировка первой последовательности: " << endl;
    sort(vec1.begin(), vec1.end());
    for (vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); it1++)
        cout << *it1 << " ";
    cout << endl;

    cout << "Сортировка второй последовательности: " << endl;
    sort(vec2.begin(), vec2.end());
    for (vector<int>::iterator it2 = vec2.begin(); it2 != vec2.end(); it2++)
        cout << *it2 << " ";
    cout << endl;

    cout << "Объединение первой и второй последовательности: " << endl;
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    for (vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); it1++) 
        cout << *it1 << " ";
    cout << endl;

    cout << "Итоговая сортированная последовательность: " << endl;
    sort(vec1.begin(), vec1.end());
    for (vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); it1++)
        cout << *it1 << " ";
    cout << endl;
    return 0;
}