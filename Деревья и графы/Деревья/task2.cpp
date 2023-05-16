// Дано дерево. Вывести путь от корня до узла X

#include <iostream>
#include <string>
using namespace std;

struct tree {
    int inf;
    tree* left;
    tree* right;
    tree* parent;
};

tree* node(int x) { // начальный узел
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) { // вставка
    tree* n = node(x);
    if (!tr) tr = n; // если дерево пустое - корень
    else {
        tree* y = tr;
        while (y) { // ищем куда вставлять
            if (n->inf > y->inf) // правая ветка
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; // узел становится правым ребенком
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf) // левая ветка
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y; // узел становится левым ребенком
                    y->left = n;
                    break;
                }
        }
    }
}

void inorder(tree* tr) {  // симметричный обход 
    if (tr) {
        inorder(tr->left);      // левое
        cout << tr->inf << " "; // корень
        inorder(tr->right);     // правое
    }
}


tree* find(tree* tr, int x) {  // поиск
    if (!tr || x == tr->inf) // нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); // ищем по левой ветке
    else
        return find(tr->right, x); // ищем по правой ветке
}


void way(tree* tr, int x) {	 // вывод пути
    if (!tr) {
        cout << "Дерево пустое" << endl;
    }
    else if (x == tr->inf) { // если дерево имеет только корень, равный элементу x
        cout << tr->inf << ' ';
    }
    else if (x > tr->inf) {
        cout << tr->inf << ' ';
        return way(tr->right, x);	// ищем по правой ветке
    }

    else if (x < tr->inf) {
        cout << tr->inf << ' ';
        return way(tr->left, x); // ищем по левой ветке
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    int n, x;
    cout << "Введите количество узлов в дереве: ";
    cin >> n;
    cout << "Введите числовые данные: " << endl;
    tree* tr = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }
    cout << "Отсортированный вывод дерева: " << endl;
    inorder(tr);
    cout << endl;
    cout << "Узел x = ";
    cin >> x;
    if (find(tr, x)) {	// если узел x можно найти в дереве, выводим путь
        way(tr, x);
    }
    else {
        cout << "Узел x не содержится в дереве" << endl;
    }
    return 0;
}
