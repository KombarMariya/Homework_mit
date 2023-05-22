// Дан неориентированный граф. Подсчитать степень каждой вершины.

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

void output_adj_list(map<int, list<int>> l_Adj) { // вывод списка смежности
    for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {
        cout << it->first << " : ";
        for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
            cout << *it_1 << "; ";
        cout << endl;
    }
    cout << endl;
}

void degree(map<int, list<int>> l_Adj) {  // подсчет степени каждой вершины
    for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {
        int count = 0;
        for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
            count++;
        cout << it->first << ": " << count << endl;
    }
}

int main() {
    map<int, list<int>> l_Adj = input_adj_list();
    output_adj_list(l_Adj);
    degree(l_Adj);
    return 0;
}
