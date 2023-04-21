#include<iostream>
using namespace std;
struct stack {
	string inf;
	stack* next;
};

void push(stack*& h, string x) { // вставка
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}
string pop(stack*& h) { // удаление
	string i = h->inf; // значение первого элемента
	stack* r = h; // указатель на голову стека
	h = h->next; // перенос указателя на следующий элемент
	delete r; // удаление первого элемента
	return i; // возвращение значения
}

void reverse(stack*& h) { // "обращение" стека
	stack* head1 = NULL; // инициализация буферного стека
	while (h) // пока стек не пуст
		push(head1, pop(h)); // переписываем из одного стека в другой
	h = head1; // переобозначение указателей
}

stack* result(stack*& h) {
	stack* res = NULL; // инициализация
	int first = 0;
	reverse(h);
	while (h) {
		string x = pop(h); // удаление первого элемента
		push(res, x); // записываем в результат
		if ((x == "a"|| x == "e" || x == "у" || x == "i" || x == "u" || x == "o") && (first == 0)) { // поиск первой гласной буквы в стеке
			first = 1;
			push(res, "?"); // записываем в результат	
		}
	}
	reverse(res);
	return res;
}

int main() {
	int n; // кол-во элементов в стеке
	cout << "n = ";
	cin >> n;
	stack* head = NULL; // инициализация
	string x;
	for (int i = 0; i < n; i++) { // создание стека
		cin >> x;
		push(head, x);
	}
	
	stack* res = result(head); // результат
	while (res)
		cout << pop(res) << " "; // вывод на экран
	cout << endl;
	return 0;
}