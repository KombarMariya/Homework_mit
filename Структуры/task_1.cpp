/* Создать структуру Hotel, содержащую следующие данные: ФИО туриста, дату прибытия, количество дней пребывания в отеле. 
Определить людей, находящихся в отеле в заданный день. 
Необходимо проверить корректность ввода дат.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct Hotel {
    string name;      // имя
    string lastname;  // фамилия
    string patron;    // отчество
    int day1;         // день
    int month1;       // месяц
    int year1;        // год
    int kol;          // кол-во дней пребывания
    string d_prib;    // дата прибытия
};
struct date {
    int day;
    int month;
    int year;
};
date STR_date(string str) { // перевод из строки в дату
    date data;
    // день
    string str1 = str.substr(0, 2);
    const char* sd = str1.c_str();
    int dd = atoi(sd);
    data.day = dd;
    // месяц
    str1 = str.substr(3, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    data.month = dd;
    // год
    str1 = str.substr(6, 4);
    sd = str1.c_str();
    dd = atoi(sd);
    data.year = dd;
    return data;
}
bool vis(int y) { //високосный год
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
int EndOfMonth(int m, int y) { // кол-во дней в месяце
    switch (m) {
    case 1: case 3: case 5:
    case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: if (vis(y)) return 29;
          else return 28;
    }
}
int correct(string str) { // проверка корректности данных
    if (str.length() != 10) return -1;
    for (string::size_type i = 0; i < str.length(); i++) {
        if (i != 2 && i != 5) {
            if (!isdigit(str[i])) return -1;
        }
        date data = STR_date(str);
        if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year)) return -2;
        if (data.month <= 0 || data.month > 12) return -3;
        if (data.year == 0) return -4;
        return 1;
    }
}
bool turist(int d1, int m1, int y1, int k, int d2, int m2, int y2) {
    if ((m1 == m2) && (y1 == y2) && (d1 + k >= d2)) return true;  // месяц и год тот же
    else {
        if ((y1 == y1) && ((d1 + k) >> EndOfMonth(m1, y1))) { // год тот же, месяца разные
            int newd = d1 - EndOfMonth(m1, y1) + k;
            int newm = m1 + 1;
            if ((newm == m2) && (newd >> d2)) return true;
            else return false;
        }
        else {
            if ((m1 == 12) && ((d1 + k) >> EndOfMonth(m1, y1))) {    // года разные
                int newd = d1 - EndOfMonth(m1, y1) + k;
                int newm = 1;
                int newy = y1 + 1;
                if ((newm == m2) && (newy == y2) && (newd >> d2)) return true;
            }
            else return false;
        }
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    string data_int;
    cout << "Input date as dd.mm.yyyy\n";
    getline(cin, data_int);
    int fl = correct(data_int);
    if (fl == -1) cout << "Error input\n";
    else if (fl == -2) cout << "Error day\n";
    else if (fl == -3) cout << "Error month\n";
    else if (fl == -4) cout << "Error year\n";
    int numPeople;
    cout << "Введите количество туристов ";
    cin >> numPeople;
    string spisok_turist = "Spisok turist: ";
    vector<Hotel>a;
    Hotel People;
    for (int i = 0; i < numPeople; i++) {
        a.push_back(People);
        cout << "Введите ФИО ";
        cin >> a[i].name;
        cin >> a[i].lastname;
        cin >> a[i].patron;
        cout << "Введите количество дней пребывания ";
        cin >> a[i].kol;
        cout << "Введите дату прибытия ";
        cin >> a[i].d_prib;
        date data_prib = STR_date(a[i].d_prib);
        date data_int1 = STR_date(data_int);
        int dint_d = data_int1.day; // день интересующей даты
        int dint_m = data_int1.month; // месяц
        int dint_y = data_int1.year; // год
        if (turist(data_prib.day, data_prib.month, data_prib.year, a[i].kol, dint_d, dint_m, dint_y) == true)
            spisok_turist = spisok_turist + " " + a[i].name + " " + a[i].lastname + " " + a[i].patron; // туристы, проживающие в интересующую дату
    }
    cout << spisok_turist;
    return 0;
}
