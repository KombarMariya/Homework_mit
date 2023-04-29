#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

ifstream in("Сотрудники.txt");
ofstream out("Сотрудники1.txt");
struct date { // дата
    int dd, mm, yy;
};
struct people { // данные о человеке
    string Surname; // фамилия
    string Dolj; // должносоть
    date DateOfBirth; // дата рождения
    int Experience; // стаж
    int Salary; // зарплата

};
date Str_to_Date(string str) { // из строки в дату
    date x;
    string temp = str.substr(0, 2); // день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // год
    x.yy = atoi(temp.c_str());
    return x;
}
vector<people> inFile() { // ввод из файла
    vector<people> x; 
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname; // фамилия
        in >> temp.Dolj; // должность
        string tmp; // дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Experience; // стаж
        in >> temp.Salary; // зарплата
        x.push_back(temp);
    }
    return x;
}

void print(people x) { // вывод в файл
    out << left << setw(10) << x.Surname << " "; // по левому краю, 10 позиций для фамилии
    out << left << setw(10) << x.Dolj << " "; // по левому краю, 10 позиций для фамилии
    if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.'; // добавляем 0
    else out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
    else out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy; // на год 6 позиций
    out << left << setw(3) << x.Experience; // на стаж 3 позиции
    out << left << setw(10) << x.Salary << endl; // на зарплату 10 позиций
}

bool operator > (people a, people b) { // переопределяем оператор > в соответствии с условием
    if (a.DateOfBirth.yy > b.DateOfBirth.yy) return true;
    if (a.DateOfBirth.yy == b.DateOfBirth.yy && a.DateOfBirth.mm > b.DateOfBirth.mm) return true;
    if (a.DateOfBirth.mm == b.DateOfBirth.mm && a.DateOfBirth.dd > b.DateOfBirth.dd) return true;
    return false;
}

void peremeshka(vector<people>& x) {
    int n = size(x);
    int k_begin = -1;
    int k_end = n - 1;
    int obmen = 0;
    while (k_begin <= k_end) {
        obmen = 0;
        k_begin = k_begin + 1; 
        for (int j = k_begin; j < k_end; j++) {
            if (x[j] > x[j+1]) {
                swap(x[j+1], x[j]);
                obmen = 1;
            }
        }
        if (obmen == 0) { return; }
        obmen = 0;
        k_end = k_end - 1;
        for (int j = k_end; j >= k_begin; j--) {
            if (x[j] > x[j + 1]) {
                swap(x[j + 1], x[j]);
                obmen = 1;
            }
        }
    }
}

int main() {
    vector <people> x;
    x = inFile();
    peremeshka(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}