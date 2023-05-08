// Дано предложение. Удалить все слова, в которых встречаются ВСЕ буквы заданного слова.

#include <iostream> 
#include <string>
using namespace std;
int main() {
    string s1, s2, slovo;
    string razdel = "!?,.:;- ";  // знаки пунктуации и пробел
    getline(cin, s1);   // ввод строки
    getline(cin, slovo);  // заданное слово
    s1 += ".";  // добавление точки в конец строки
    s2 = "";

    string::size_type pos = 0, k, kk, pos_word;
    k = s1.find_first_of(razdel);   // поиск конца первого слова
    while (k != string::npos) {  // пока находятся слова
        string word = s1.substr(pos, k - pos);   // копия слова
        pos_word = pos;   // позиция слова
        for (int i = 0; slovo[i]; i++) {  
            kk = word.find(slovo[i]); // поиск в слове символа slovo[i]
            if (kk > 1000) { // символа slovo[i] нет
                s2 = s2 + word + s1.substr((pos_word + word.length()), 1);   
                break;
            }

        }


        if (ispunct(s1[k])) pos = k + 2;  // если нашелся знак препинания
        else pos = k + 1;
        k = s1.find_first_of(razdel, pos);   // конец следующего слова
    }
    cout << "Result: " << s2 << endl; // вывод новой строки
    return 0;
}