// Дано предложение, содержащее знаки препинания. Поменять местами самое длинное и самое короткое слово.

#include <iostream> 
#include <string>
using namespace std;
int main() {
    string s1, s2, smax, smin;
    string razdel = "!?,.:;- "; // знаки пунктуации и пробел
    getline(cin, s1);    // ввод строки
    s1 += '.';          // добавление точки в конец строки
    string::size_type pos = 0, k;
    string::size_type pos_min = 0, pos_max = 0;
    string::size_type max = 0;
    string::size_type min = 100;
    k = s1.find_first_of(razdel);   // поиск конца первого слова
    while (k != string::npos) {     // пока находятся слова
        string word = s1.substr(pos, k - pos);   // копия слова
        if (word.length() > max) {    // поиск слова максимальной длины
            max = word.length();
            smax = word;
            pos_max = pos;   // позиция макс слова
        }
        if (word.length() < min) {    // поиск слова минимальной длины
            min = word.length();
            smin = word;
            pos_min = pos;  // позиция мин слова
        }
        if (ispunct(s1[k])) pos = k + 2;   // если нашелся знак препинания
        else pos = k + 1;
        k = s1.find_first_of(razdel, pos);   // поиск конца следующего слова
    }
    cout << "max word " << smax << endl;
    cout << "min word " << smin << endl;
    if (pos_max < pos_min) { // если максимальное слово впереди минимального
        s1.replace(pos_max, smax.length(), smin);   // максимальное заменяется на минимальное
        s1.replace(pos_min - smax.length() + smin.length(), smin.length(), smax);  // минимальное заменяется на максимальное
        cout << s1;   // вывод новой строки
    }
    if (pos_max > pos_min) { // если минимальное слово впереди максимального
        s1.replace(pos_max, smax.length(), smin); // максимальное заменяется на минимальное
        s2 = s1.substr(0, pos_min) + smax + s1.substr(pos_min);   // минимальное заменяется на максимальное
        cout << s2;  // вывод новой строки
    }
    return 0;
}