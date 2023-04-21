#include<iostream>
using namespace std;
struct queue {
	int inf;
	queue * next;
};

void push(queue*& h, queue *&t, int x) { // вставка элемента в очередь
	queue * r = new queue; // создаем новый элемент
	r -> inf = x;
		r -> next = NULL; // всегда последний
	if (!h && !t) { // если очередь пуста
		h = t = r; // это и голова, и хвост
	}
	else {
		t -> next = r; // r - следующий для хвоста
		t = r; // теперь r - хвост
	}
}

int pop(queue*& h, queue *&t) { // удаление элемента из очереди
	queue * r = h; // создаем указатель на голову
	int i = h -> inf; // сохраняем значение головы
	h = h -> next; // сдвигаем указатель на следующий элемент
	if (!h) 
		t = NULL;
	delete r; // удаляем первый элемент
	return i;
}

void print(queue*& h) { // печать очереди
	queue* r = h;
	while (r) {
		cout << r->inf << ' ';
		r = r->next;
	}
	cout << endl;
}

void result(queue*& h, queue*& t) {
	// инициализация
	queue* h1 = NULL;
	queue* t1 = NULL;
	int maxstack = 0;
	int posled; 
	while (h && t) {
		int x = pop(h, t); // удаление элемента
		if (x > maxstack) { // поиск максимального элемента 
			maxstack = x;
		}
		push(h1, t1, x); // записываем в результат
		posled = x; // последний 
	}
	h = h1;
	t = t1; // передаем указатели

	h1 = NULL;
	t1 = NULL;

	while (h && t) {
		int x = pop(h, t); // удаление элемента
		push(h1, t1, x); // записываем в результат
		if (x == posled) { // если = последнему
			push(h1, t1, maxstack); // записываем максимальный
		}
	}
	h = h1; 
	t = t1; // передаем указатели
}

int main() {
	int n; // кол-во элементов в стеке
	cout << "n = ";
	cin >> n;
	queue* head = NULL; // инициализация
	queue* tail = NULL; // инициализация
	int x;
	for (int i = 0; i < n; i++) { // создание стека
		cin >> x;
		push(head, tail, x);
	}
	result(head, tail); // результат
	print(head);
	return 0;
}