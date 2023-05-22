/*  Дан неориентированный граф.
Выполнить следующие задания :
    Вывести Эйлеров путь или Эйлеров цикл, если он существует.
    Реализовать топологическую сортировку.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> input_adj_list(int N) { // ввод списка смежности из файла 
    ifstream in("in.txt");
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

void top_sort(int x, vector<vector<int>>& Gr, vector<int>& order, vector<bool>& visited) { // топологическая сортировка
    visited[x] = true; // помечаем вершину x как посещенную 
    for (int i = 0; i < Gr[x].size(); i++) { // проходимся по всем смежным вершинам 
        if (!visited[Gr[x][i]]) { // если вершина еще не была посещена 
            top_sort(Gr[x][i], Gr, order, visited); // рекурсивно вызываем функцию для этой вершины 
        }
    }
    order.push_back(x); // записываем вершину x в order 
}

void euler_path(vector<vector<int>> Gr) { 
    int N = Gr.size();
    vector<int> degrees(N, 0); // степени вершин
    for (int i = 0; i < N; i++) {
        degrees[i] = Gr[i].size(); // вычисление степени каждой вершины
    }
    int v1 = -1, v2 = -1; // вершины с нечетными степенями
    for (int i = 0; i < N; i++) {
        if (degrees[i] % 2 == 1) { // если степень вершины нечетная
            if (v1 == -1) {
                v1 = i;
            }
            else if (v2 == -1) {
                v2 = i;
            }
            else {
                break; 
            }
        }
    }
    if (v1 != -1) { // если есть вершины с нечетными степенями
        Gr[v1].push_back(v2); // добавляем фиктивное ребро
        Gr[v2].push_back(v1);
    }
    stack<int> st;
    vector<int> res;
    st.push(0); // начальная вершина
    while (!st.empty()) {
        int v = st.top();
        if (degrees[v] != 0) { // если степень вершины не равна 0
            int u = Gr[v][0]; // смежная вершина
            st.push(u);
            degrees[v]--;
            degrees[u]--;
            Gr[v].erase(find(Gr[v].begin(), Gr[v].end(), u)); // удаляем ребро
            Gr[u].erase(find(Gr[u].begin(), Gr[u].end(), v));
        }
        else {
            res.push_back(v); // добавляем вершину в результат
            st.pop();
        }
    }
    if (v1 != -1) { // если было добавлено фиктивное ребро
        for (int i = 0; i < res.size() - 1; i++) {
            if ((res[i] == v1 && res[i + 1] == v2) || (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> temp(res.begin() + i + 1, res.end());
                temp.insert(temp.end(), res.begin() + 1, res.begin() + i + 1);
                res = temp;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (!Gr[i].empty()) { // если в графе остались ребра, то он несвязный
            cout << "Нет пути" << endl;
            return;
        }
    }
    cout << "Путь: ";
    for (int vertex : res) { // вывод пути
         cout << vertex << " ";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N = 8; // количество вершин в графе 
    vector<vector<int>> Gr = input_adj_list(N); // список смежности 
    output_adj_list(Gr);
    vector<int> order; // список вершин в топологическом порядке 
    vector<bool> visited(N, false); // массив посещенных вершин 
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { // если вершина еще не была посещена 
            top_sort(i, Gr, order, visited); // вызываем функцию топологической сортировки 
        }
    }
    reverse(order.begin(), order.end()); // переворачиваем список
    cout << "Топологическая сортировка: ";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }
    euler_path(Gr); 
    return 0;
}