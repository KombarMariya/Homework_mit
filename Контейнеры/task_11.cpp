#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <iterator> 
#include <map>

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    string word, firstNum;
    string number = "0123456789"; // все цифры
    map <string, int> let;  // слова
    map <string, int> num;  // числа
    string::size_type k;
    ifstream in("4_in.txt"); // открыть для чтения
    while (in.peek() != EOF) { // пока не конец файла 
        in >> word; // считываем слово
        k = word.find_first_not_of(number); // проверка: число или слово считали
        if (k == 0) { // если считанное слово не число
            let[word]++; // добавляем слово в контейнер к словам
        }
        else {
            if (num.empty()) { // если считаное слово число и контейнер с числами пустой
                firstNum = word; // определяем первое число
            }
            num[word]++; //добавляем число в контейнер к числам
        }
    }

    cout << "Первое число = " << firstNum << endl;
    int p = num[firstNum];
    cout << "Кол-во первого числа: "<< p<< endl;

    cout << "Cлова, встречающиеся столько же раз, сколько первое число: " << endl;
    for (auto itr = let.begin(); itr != let.end(); ++itr) {
        if (itr->second == p) {
            cout << itr->first << " " << itr->second << endl;
        }
    }
    return 0;
}
