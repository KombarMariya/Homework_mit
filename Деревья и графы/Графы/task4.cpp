// Дан неориентированный граф. Определить содержит ли он циклы. Если да, то вывести их.

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> input_adj_list(int N) { // ввод списка смежности из файла 
    ifstream in("input.txt");
    vector<vector<int>> Gr;
    Gr.resize(N); // устанавливаем размер вектора
    int x, y;
    while (in.peek() != EOF) {
        in >> x >> y;
        if (x > N || y > N) // если какое-то из чисел больше, чем количество вершин в графе
            continue;
        else {
            Gr[x].push_back(y); // добавление вершины y в список смежности вершины x
            Gr[y].push_back(x); // добавление вершины x в список смежности вершины y
        }
    }
    for (int i = 0; i < N; i++)
        // удаление повторяющихся элементов из списка смежности каждой вершины
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    return Gr;
}

void output_adj_list(vector<vector<int>> Gr) {  // вывод списка смежности
    for (int i = 0; i < Gr.size(); i++) {
        cout << i << ": ";
        for (int vertex_adj : Gr[i]) {
            cout << vertex_adj << " ";
        }
        cout << endl;
    }
    cout << endl;
}

const int N = 6; // устанавливаем размер графа
vector<vector<int>> Gr = input_adj_list(N);
int pr[N]; // массив для хранения предков вершин 
int used[N]; // массив для отметки использованных вершин в обходе графа
vector<vector<int>> cycles; // вектор для хранения циклов 
vector<vector<int>> cycles_sort; // вектор для хранения отсортированных циклов 

void add_cycles(int start, int end) { // функция для добавления циклов
    int cur = end; // начинаем с конца цикла
    vector<int> tmp; // вектор для хранения вершин в цикле
    while (cur != start) {
        tmp.push_back(cur); // добавление текущей вершины в вектор 
        cur = pr[cur];  // переход к предыдущей вершине в цикле
    }
    tmp.push_back(start);            // добавление начальной вершины цикла в вектор 
    reverse(tmp.begin(), tmp.end()); // обращение порядка элементов вектора цикла
    cycles.push_back(tmp);           // добавление вектора цикла в вектор всех найденных циклов
    sort(tmp.begin(), tmp.end());    // сортировка элементов вектора цикла 
    cycles_sort.push_back(tmp);      // добавление отсортированного вектора цикла в вектор отсортированных циклов
}

void DFS(int x) { // Функция нахождения циклов в графе
    used[x] = 1; // пометка вершины x как посещенной
    for (int i = 0; i < Gr[x].size(); i++) { // проходим по всем смежным вершинам
        if (pr[Gr[x][i]] == x) // если текущая вершина уже была посещена и является предком вершины x, то пропускаем ее
            continue;
        if (used[Gr[x][i]] == 0) { // если текущая вершина еще не была посещена, то рекурсивно запускаем функцию для нее
            pr[Gr[x][i]] = x; 
            DFS(Gr[x][i]); 
        }
        // если текущая вершина уже была посещена и не является предком вершины x, то добавляем найденный цикл
        else if (used[Gr[x][i]] == 1)
            add_cycles(Gr[x][i], x);
    }
    used[x] = 0; // пометка вершины x как непосещенной 
}

void result() { // функция вывода каждого найденного цикла вместе с его вершинами
    for (int i = 0; i < N; i++) {
        pr[i] = -1;
        used[i] = 0;
    }
    DFS(0); // находим циклы в графе, начиная с вершины 0
    map<vector<int>, int> cycle; // map для хранения циклов
    for (int i = 0; i < cycles_sort.size(); i++) {
        if (cycles_sort[i].size() > 2 && cycle.count(cycles_sort[i]) == 0) { // если цикл содержит более двух вершин и его еще нет в map
            cycle[cycles_sort[i]] = i;  // добавляем цикл в map
        }
    }
    for (auto it = cycle.begin(); it != cycle.end(); it++) {
        int i = it->second;
        cout << "Цикл: ";
        for (int j = 0; j < cycles[i].size(); j++) {
            cout << cycles[i][j] << " "; // вывод вершины
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    output_adj_list(Gr);
    result();
    return 0;
}