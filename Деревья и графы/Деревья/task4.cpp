// Дано дерево. Определить высоту узла X

#include <iostream>	
#include <queue>	
using namespace std;

struct tree {		
	int inf;
	tree* left;
	tree* right;
};

tree* node(int x) {	// начальный узел
	tree* n = new tree;
	n->inf = x;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void create(tree*& tr, int n) {	//  создание дерева 
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}

void preorder(tree* tr) {  // прямой обход 
	if (tr) {
		cout << tr->inf << " ";  // корень
		preorder(tr->left);   // левое 
		preorder(tr->right);  // правое
	}
}


int left_h(tree* tr) {	// высота левой ветки
	int k = 0;
	tree* y = tr;
	while (y) {
		k++;
		y = y->left;
	}
	return k - 1;
}


void find(tree* tr, int x, tree*& res) { // поиск
	if (tr) {
		if (tr->inf == x) {
			res = tr;
		}
		else {
			find(tr->left, x, res);
			find(tr->right, x, res);
		}
	}
}


void print(tree* tr, int k) {  // вывод дерева
	if (!tr) {
		cout << "Дерево пустое " << endl;
	}
	else {
		queue<tree*> cur, next;
		tree* r = tr;
		cur.push(r);
		int j = 0;

		while (cur.size()) {
			if (j == 0) {
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
					cout << ' ';
			}

			tree* buf = cur.front();
			cur.pop();
			j++;

			if (buf) {
				cout << buf->inf;
				next.push(buf->left);
				next.push(buf->right);
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << " ";
			}

			if (!buf) {
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << " ";

				cout << " ";

			}

			if (cur.empty()) {
				cout << endl;
				swap(cur, next);
				j = 0;
				k--;
			}
		}
	}
}


int main() {								
	setlocale(LC_ALL, "RUS");
	int n, x;
	cout << "Введите количество узлов в дереве: ";
	cin >> n;
	cout << "Введите числовые данные: " << endl;
	tree* tr = NULL;
	create(tr, n);	// cоздание и заполнение дерева
	int k = int(log((float)n) / log((float)2.0));
	print(tr, k);  // вывод дерева
	if (n > 0) {
		cout << "Узел x = ";
		cin >> x;
		tree* res = NULL;
		find(tr, x, res);
		if (res) {	// если x есть в дереве
			cout << "Высота узла x = " << left_h(res) << endl;
		}
		else {
			cout << "Узла x = " << x << " нет в дереве" << endl;
		}
	}
	return 0;	
}
