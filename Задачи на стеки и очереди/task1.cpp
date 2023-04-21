#include<iostream>
using namespace std;
struct stack { 
	int inf;
	stack * next;
};

void push(stack * &h, int x) { // вставка
	stack * r = new stack;
	r -> inf = x;
	r -> next = h;
	h = r;
}
int pop(stack * &h) { // удаление
	int i = h -> inf; // значение первого элемента
	stack * r = h; // указатель на голову стека
	h = h -> next; // перенос указателя на следующий элемент
	delete r; // удаление первого элемента
	return i; // возвращение значения
}

void reverse(stack*& h) { // "обращение" стека
	stack * head1 = NULL; // инициализация буферного стека
	while (h) // пока стек не пуст
		push(head1, pop(h)); // переписываем из одного стека в другой
	h = head1; // переобозначение указателей
}

stack* result(stack*& h) {
	stack * res = NULL; // инициализация
	stack * h1 = NULL;
	int maxstack = 0;
	int minstack = 1000;
	
	while (h) {
		int x = pop(h); // удаление первого элемента
		if (x > maxstack) { // поиск максимального элемента в стеке
			maxstack = x;	
		}
		if (x < minstack) { // поиск минимального элемента в стеке
			minstack = x;
		}
		push(h1, x); // записываем в результат
	}
	reverse(h1); // переворачиваем стек
	while (h1) {
		int y = pop(h1); // удаляем элемент из стека
		if (y == maxstack) { // сравнение элемента стека с максимальным элементом
			push(res, minstack); 
		}
		push(res, y); // записываем в результат
	}
	return res; 
}
int main() {
	int n; // кол-во элементов в стеке
	cout << "n = ";
	cin >> n;
	stack * head = NULL; // инициализация
	int x;
	for (int i = 0; i < n; i++) { // создание стека
		cin >> x;
		push(head, x);
	}
	stack * res = result(head); // результат
	while (res)
		cout << pop(res) << " "; // вывод на экран
	cout << endl;
	return 0;
}