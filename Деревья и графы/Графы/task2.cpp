// Дан неориентированный граф. Вставить в граф ребро, соединяющее вершины A и B.

#include <iostream>
#include <fstream>
#include <list>
#include <map>

using namespace std;

map<int, list<int>> input_adj_list() { // ввод списка смежности из файла 
    ifstream in("input.txt");
    map<int, list<int>> l_Adj;
    int x, y;
    while (in.peek() != EOF) {
        in >> x >> y; // вводим ребро в виде x->y
        auto it_x = l_Adj.find(x); // ищем вершину x
        bool fl = true;
        if (it_x != l_Adj.end()) { // если вершина x уже существует
            for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
                if (*it_y == y) {
                    fl = false;
                    break;
                }
        }
        if (fl) { // неориентированный
            l_Adj[x].push_back(y);
            l_Adj[y].push_back(x);
        }
    }
    return l_Adj;
}

void output_adj_list(map<int, list<int>> l_Adj) {  // вывод списка смежности
    for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {
        cout << it->first << " : ";
        for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
            cout << *it_1 << "; ";
        cout << endl;
    }
    cout << endl;
}

void edge(map<int, list<int>>& l_Adj) {  // вставляем в граф ребро, соединяющее вершины A и B
    int A, B;
    cout << "Введите вершины A и B, которые нужно соединить:" << endl;
    cin >> A >> B;
    if (!l_Adj.count(A) || !l_Adj.count(A))
        return;
    else {
        l_Adj[A].push_back(B); // в список смежности вершины A добавляется вершина B
        l_Adj[A].sort(); // сортировка списка смежности
        l_Adj[A].unique(); // удаление повторяющихся элементов
        l_Adj[B].push_back(A); // в список смежности вершины B добавляется вершина A
        l_Adj[B].sort(); // сортировка списка смежности
        l_Adj[B].unique(); // удаление повторяющихся элементов
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    map<int, list<int>> l_Adj = input_adj_list();
    output_adj_list(l_Adj);
    edge(l_Adj);
    output_adj_list(l_Adj);
    return 0;
}