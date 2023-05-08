/* Дан файл, содержащий расписание телепрограммы одного канала на неделю.
В новый файл вывести только программы, идущие после 18 часов и до 21 часа. */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
int main() {
    setlocale(LC_ALL, "russian");
    string x, chas;
    ifstream in("4_in.txt");   // для чтения
    if (!in.is_open()) cout << "ошибка чтения файла";
    ofstream out("4_out.txt");  // для записи
    string::size_type pos_raz = 0;
    string raz_time = ":";
    int rez1;
    int rez2;

    while (in.peek() != EOF) {   // пока не дошли до конца файла
        getline(in, x);   // считываем из файла строку 
        pos_raz = x.find(raz_time);   // позиция, где встречается двоеточие
        chas = x.substr(pos_raz - 2, 2);  // выделяем из строки часы

        rez1 = chas.compare("18");  // сравниваем часы с 18, rez1 > 0 если больше 18 
        rez2 = chas.compare("20");  // сравниваем часы с 20, rez2 < 0 если меньше 21 

        if (rez1 >= 0 && rez2 <= 0) {  
            out << x << endl;   // запись найденной строки в файл
        }
    }
    in.close();
    return 0;
}