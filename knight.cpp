#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int N = 8; // размер доски

struct kletka { // координаты клетки
	int x, y;
	kletka(int x, int y) : x(x), y(y) {}
};

bool valid(kletka p) { // проверка нахождения клетки на доске
	return (p.x >= 0) && (p.x < N) && (p.y >= 0) && (p.y < N);
}

int distance(kletka p1, kletka p2) {  // расчет расстояние между двумя клетками
	int dx = abs(p1.x - p2.x);
	int dy = abs(p1.y - p2.y);
	return (dx + dy) / 3 + ((dx + dy) % 3 == 2);
}

vector<kletka> get_moves(kletka p) {  // получение возможных ходов коня из данной клетки
	vector<kletka> moves;
	int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // 8 возможных ходов с заданой позиции - координаты x
	int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; // 8 возможных ходов с заданой позиции - координаты y
	for (int i = 0; i < 8; i++) {
		kletka np(p.x + dx[i], p.y + dy[i]); // заполнение вектора возможными ходами
		if (valid(np)) { // проверка нахождения клетки на доске
			moves.push_back(np); // вставка нового элемента в вектор
		}
	}
	return moves; 
}

vector<kletka> poisk_puti(kletka start, kletka end) { // поиск кратчайшего пути конем между двумя клетками
	queue<kletka> q; // создание очереди
	bool visited[N][N]; // массив определения посещаемости поля
	memset(visited, false, sizeof(visited)); // заполнение массива visited значениями  
	int dist[N][N];
	memset(dist, -1, sizeof(dist)); // заполнение массива dist значениями
	int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	q.push(start); // ставим в очереди первый узел
	visited[start.x][start.y] = true; // true, если текущий узел - посещенный
	dist[start.x][start.y] = 0; // координаты коня
	while (!q.empty()) { // цикл до тех пор, пока очередь не станет пустой
		kletka p = q.front(); // p - первый элемент в очереди
		q.pop(); // lостаем новую клетку из очереди
		if ((p.x == end.x) && (p.y == end.y)) { // если пункт назначения достигнут
			break;
		}
		for (kletka np : get_moves(p)) { // рассматриваем только возможные ходы
			if (!visited[np.x][np.y]) { // если текущее поле  - не посещенное
				visited[np.x][np.y] = true; // присваиваем значение = текущий узел - посещенный
				dist[np.x][np.y] = dist[p.x][p.y] + 1; // переходим на следующую координату 
				q.push(np); // добавление в очередь
			}
		}
	}
	vector<kletka> puti;
	if (dist[end.x][end.y] != -1) { // если не начальная позиция фигуры
		puti.push_back(end); // вставляем новый элемент в вектор
		while (!((puti.back().x == start.x) && (puti.back().y == start.y))) { // если последний ход не совпадает с начальной позицией
			kletka p = puti.back(); // последний элемент вектора
			for (kletka np : get_moves(p)) { // рассматриваем только возможные ходы
				if (dist[np.x][np.y] == dist[p.x][p.y] - 1) { // если координата не совпадает с предыдущей 
					puti.push_back(np); // вставляем новый элемент в вектор
					break;
				}
			}
		}
		reverse(puti.begin(), puti.end()); // меняем местами начало и конец
	}
	return puti;
}

kletka convert(string s) {  // перевод координат в x и y
	return kletka(s[1] - '1', s[0] - 'A');
}

int main() {
	setlocale(LC_ALL, "RUS");
	string start, end;
	cout << "Введите начальную позицию коня: ";
	cin >> start;
	cout << "Введите конечную позицию коня: ";
	cin >> end;
	kletka p1 = convert(start); // перевод начальной шахматной координаты в координаты x и y
	kletka p2 = convert(end);  // перевод конечной шахматной координаты в координаты x и y
	vector<kletka> path = poisk_puti(p1, p2); // поиск кратчайшего пути конем между двумя клетками
	cout << "Кратчайший путь коня: ";
	for (kletka p : path) {
		char c = p.y + 'A';  // перевод из координат x и y в шахматные координаты
		int r = p.x + 1;
		cout << c << r << " "; // печать шахматных координат
	}
	return 0;
}