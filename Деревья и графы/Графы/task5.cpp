// Дан невзвешенный граф неориентированный граф. Найти кратчайший путь между вершинами A и В.

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct queue {  // очередь
    int inf;
    queue* next;
};

void push(queue*& h, queue*& t, int x) {  // вставка элемента в очередь
    queue* r = new queue; // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t) {  // если очередь пуста
        h = t = r; // это и голова и хвост
    }
    else {
        t->next = r; // r - следующий для хвоста
        t = r;       // теперь r - хвост
    }
}

int pop(queue*& h, queue*& t) { // удаление элемента из очереди
    queue* r = h;   // создаем указатель на голову
    int i = h->inf; // сохраняем значение головы
    h = h->next;    // сдвигаем указатель на следующий элемент
    if (!h)         // если удаляем последний элемент из очереди
        t = NULL;
    delete r; // удаляем первый элемент
    return i;
}

vector<vector<int>> input_adj_list(int N) { // ввод списка смежности из файла 
    ifstream in("input.txt");
    vector<vector<int>> Gr;
    Gr.resize(N); // устанавливаем размер вектора
    int x, y;
    while (in.peek() != EOF) {
        in >> x >> y;
        if (x > N || y > N)  // если какое-то из чисел больше, чем количество вершин в графе
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

void output_adj_list(vector<vector<int>> Gr) { // вывод списка смежности
    for (int i = 0; i < Gr.size(); i++) {
        cout << i << ": ";
        for (int vertex_adj : Gr[i]) {
            cout << vertex_adj << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> BFS(vector<vector<int>> Gr, int N, int A, int B) {  // обход в ширину
    queue* visits = NULL; // очередь для хранения вершин, которые нужно посетить
    queue* tail = NULL;
    vector<int> dist(N, N); // вектор расстояний от начальной вершины до каждой из вершин графа
    vector<int> p(N, -1);  // вектор предков для каждой из вершин графа 
    dist[A] = 0;
    push(visits, tail, A);
    while (visits) {
        int v = pop(visits, tail);
        for (int u : Gr[v]) {
            // если расстояние до текущей смежной вершины больше, чем расстояние до текущей вершины + 1
            if (dist[u] > dist[v] + 1) { 
                p[u] = v; // устанавливается текущая вершина как предок для смежной вершины
                dist[u] = dist[v] + 1; // устанавливается новое расстояние до смежной вершины
                push(visits, tail, u); // добавляется смежная вершина в очередь на обработку
            }
        }
    }
    if (dist[B] == N) { // путь не найден
        return {};
    }
    vector<int> path; // вектор для хранения пути от начальной до конечной вершины
    int t = B;
    while (t != -1) {
        path.push_back(t); // добавление текущей вершины в вектор пути
        t = p[t];  // установление текущей вершины равной предку для текущей вершины
    }
    reverse(path.begin(), path.end()); // переворачиваем, т.к. путь был в обратном порядке 
    return path;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<vector<int>> Gr = input_adj_list(6);
    output_adj_list(Gr);
    cout << "Введите вершину A: ";
    int vertex_A;
    cin >> vertex_A;
    cout << "Введите вершину B: ";
    int vertex_B;
    cin >> vertex_B;
    vector<int> way_AB = BFS(Gr, 6, vertex_A, vertex_B);
    for (int i : way_AB) // выводим путь
        cout << i << " ";
}