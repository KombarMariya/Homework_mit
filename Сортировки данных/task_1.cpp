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
    out << left << setw(3) << x.Experience; // на стаж 3 позиций
    out << left << setw(10) << x.Salary << endl; // на зарплату 10 позиций
}

bool operator > (people a, people b) { // переопределяем оператор > в соответствии с условием
    if (a.Salary > b.Salary) return true;
    return false;
}

void bystray(vector<people>& x, int L, int R) {
    int n = size(x);
    int i = L;
    int j = R;
    auto opora = x[(i + j) / 2];
    while (i <= j) {
        while (opora > x[i]) {
            i++;
        }
        while (x[j] > opora) {
            j--;
        }
        if (i <= j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (j > L) {
        bystray(x, L, j);
    }
    if (i < R) {
        bystray(x, i, R);
    }        
}

int main() {
    vector <people> x;
    x = inFile();
    int n = size(x);
    bystray(x, 0, n-1);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}