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
    string Dolj; // должность
    date DateOfBirth; // дата рождения
    int Experience; // стаж
    int Salary; // зарплата

};
date Str_to_Date(string str) { // из строки в дату
    date x;
    string temp = str.substr(0, 2);  // день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);  // месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);   // год
    x.yy = atoi(temp.c_str());
    return x;
}
vector<people> inFile() {   // ввод из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname; // фамилия
        in >> temp.Dolj; // должность
        string tmp; // дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Experience;  // стаж
        in >> temp.Salary;  // зарплата
        x.push_back(temp);
    }
    return x;
}

void print(people x) {  // вывод в файл
    out << left << setw(10) << x.Surname << " "; // по левому краю, 10 позиций для фамилии
    out << left << setw(10) << x.Dolj << " "; // по левому краю, 10 позиций для должности
    if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.'; // добавляем 0
    else out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
    else out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy; // на год 6 позиций
    out << left << setw(3) << x.Experience; // на стаж 3 позиций
    out << left << setw(10) << x.Salary << endl; // на зарплату 10 позиций
}

bool operator > (people a, people b) { // переопределяем оператор > в соответствии с условием
    if (a.DateOfBirth.yy < b.DateOfBirth.yy) return true;
    if (a.DateOfBirth.yy == b.DateOfBirth.yy && a.Experience < b.Experience) return true;
    return false;
}

void rascheska(vector<people>& x) { // сортировка расческой
    int N = x.size();
    float gap = N / 1.247;
    
    while (gap >= 1) {
        if (gap < 1){
            gap = 1;
        }
        for (int j = 0; j < N - gap; j++) {
            int i = j + gap;
            if (x[j] > x[i]){
                swap(x[i], x[j]);
            }
        }
        gap = gap / 1.247;
    }
}

int main() {
    vector <people> x;
    x = inFile();
    rascheska(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}