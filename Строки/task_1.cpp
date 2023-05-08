//Дана строка, содержащая латинские буквы.Все гласные буквы заменить пробелом.

#include <iostream>
using namespace std;
#include <string>
int main() {
    string s;
    getline(cin, s);   // ввод строки
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {  // поиск гласных

            s.replace(i, 1, " ");  // гласные заменяются на пробел
        }
    }
    cout << "STRING: " << s << endl;  // вывод новой строки
    return 0;
}