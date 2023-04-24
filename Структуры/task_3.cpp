// Реализовать функции для работы с датой: определение количества прошедших дней, определение даты через N дней, корректность даты, определение дня недели.


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
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

date Next(date x, int n) {  // дата через n дней
    date y = x;
    int ostatok = 0;
    if (x.day + n <= EndOfMonth(x.month, x.year)) { // месяц и год остаются
        y.day = x.day + n;
        y.month = x.month;
        y.year = x.year;
        return y;
    }

    if (x.day + n > EndOfMonth(x.month, x.year)) {    // кол-во дней превышает кол-во дней в месяце
        ostatok = x.day - EndOfMonth(x.month, x.year) + n;
        for (int j = 1; j < n; j++) {
            if (ostatok > EndOfMonth(x.month, x.year)) {
                x.day = ostatok;
                x.month = x.month + j;
                x.year = x.year;
                if (x.month >= 12) {
                    x.month = 1;
                    x.year = x.year + 1;
                }
                ostatok = x.day - EndOfMonth(x.month, x.year);
            }
            else {
                y.day = ostatok;
                y.month = x.month + 1;
                y.year = x.year;
                if (y.month >= 12) {
                    y.month = 1;
                    y.year = y.year + 1;
                }
                return y;
            }
        }
    }
}

int between_dat(date x, date y) {  // подсчет дней между датами
    int k = 0;
    if (x.day < y.day && x.month == y.month && x.year == y.year) { // месяца и года одинаковые
        k = y.day - x.day;
        return k;
    }
    // месяц второй больше первого
    if (x.month < y.month && x.year == y.year) { // года одинаковые
        int d1 = EndOfMonth(x.month, x.year) - x.day;
        int d2 = y.day;
        for (int i = 1; i <= y.month - x.month - 1; i++) {
            k = k + EndOfMonth(x.month + i, x.year);
        }
        k = k + d1 + d2;
        return k;
    }
    if (x.month < y.month && x.year < y.year) { // года разные

        int d1 = EndOfMonth(x.month, x.year) - x.day;
        int d2 = y.day;

        int kol_g = y.year - x.year;

        for (int i = 1; i <= y.month - x.month - 1; i++) {
            k = k + EndOfMonth(x.month + i, x.year);

        }
        k = k + d1 + d2 + 366 * kol_g;
        return k;
    }
    // месяц первый больше второго
    if (x.month > y.month && x.year < y.year) { // года разные

        int d1 = EndOfMonth(x.month, x.year) - x.day;
        int d2 = y.day;

        int kol_g = y.year - x.year;
        int j = 1;
        for (int i = 1; i <= 11 - (x.month - y.month); i++) {

            if (y.month + i == 13) {
                j = i - x.month;
            }
            k = k + EndOfMonth(y.month - j, x.year);
            j = j + 1;

        }
        k = k + d1 + d2 + 366 * (kol_g - 1);
        return k;
    }
}

void print(date x) {  //печать данных на экран
    if (x.day < 10) cout << "0" << x.day << ".";
    else cout << x.day << ".";
    if (x.month < 10) cout << "0" << x.month << ".";
    else cout << x.month << ".";
    if (x.year < 10) cout << "000" << x.year;
    else if (x.year < 100) cout << "00" << x.year;
    else if (x.year < 1000) cout << "0" << x.year;
    else cout << x.year;
    cout << endl;
}

int weekday(int D, int M, int Y) {  // определение дня недели
    int a, y, m, R;
    a = (14 - M) / 12;
    y = Y - a;
    m = M + 12 * a - 2;
    R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    return R % 7;

}


int main() {
    setlocale(LC_ALL, "Rus");
    string data_ish1;
    cout << "Enter the first date(first date < second date) " << endl;
    getline(cin, data_ish1);
    int fl = correct(data_ish1);
    if (fl == -1) cout << "Error input\n";
    else if (fl == -2) cout << "Error day\n";
    else if (fl == -3) cout << "Error month\n";
    else if (fl == -4) cout << "Error year\n";
    string data_ish2;
    cout << "Enter the second date " << endl;
    getline(cin, data_ish2);
    int f2 = correct(data_ish2);
    if (f2 == -1) cout << "Error input\n";
    else if (f2 == -2) cout << "Error day\n";
    else if (f2 == -3) cout << "Error month\n";
    else if (f2 == -4) cout << "Error year\n";

    int n;
    cout << "Input a number of days " << endl; cin >> n;

    date data = STR_date(data_ish1);
    date data_2 = STR_date(data_ish2);

    date N_date = Next(data, n);
    cout << "Через " << n << " дней будет ";
    print(N_date);


    string S[7] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
    cout << "День недели (для первой даты) - " << S[weekday(data.day, data.month, data.year)] << endl;

    int kol_dn = 0;
    kol_dn = between_dat(data, data_2);

    cout << "Количество дней между дaтaми - " << endl;
    cout << kol_dn << endl;

    return 0;
}