#include<iostream>
#include<string>
#include <cstdlib>

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
};


int prior(string s) { // удаление
	string znaki = "(+-/*";
	int i=0;
	string::size_type k;
	k = znaki.find_first_of(s);
	if (k == 0) i = 1;
	if (k == 1 || k == 2) i = 2;
	if (k == 3 || k == 4) i = 3;
	return i; // возвращение значения
}


int main() {
	string stroka = "a*(b+c*d)+e"; //выражение в инфиксной форме
	string res=""; //результат в постфиксной форме
	string arifm = "(+-*/)";
	string skobka1 = "(";
	string skobka2 = ")";
	string s1="";
	string x = "";
	stack* znak = NULL; // инициализация стека
	int i;
	int pustoy = 0;
	string::size_type ks, kz, k;
	//пока не дошли до конца строки
	for (string::size_type j = 0; j < stroka.size(); j++) {
		s1 = stroka[j];
		ks = s1.find_first_of(skobka1); //поиск открывающеся скобки
		k = s1.find_first_of(arifm); // поиск знака операции
		kz = s1.find_first_of(skobka2); // поиск закрывающей скобки
		if (ks == 0)//если нашли открывающую скобку 
		{
			push(znak, s1); // записываем в стек
			pustoy = 1; //стек не пустой
			continue;
		} 
		
		if (k != 0) res = res + s1; //операнд записываем в результирующую строку
		if ((k == 0)&&(pustoy==0))//если нашли знак операции и стек пустой
		{ 
			push(znak, s1); //знак операции записываем в стек
			pustoy = 1; //стек не пустой
			continue;
		}
		
		if (kz == 0) {//если закрывающаяся скобка
			//пока вершина стека не открывающая скобка
			while (znak) {
				x = pop(znak);
				push(znak, x);
				if (x != "(") { //извлекаем из стека и записываем в результат
					x = pop(znak);
					res = res + x;
				}
				if (x == "(") //удаляем из стека закрывающую скобку
				{
					x = pop(znak);
					break;
				}
			}
		}
				
						
		if ((k == 0) && (kz != 0)) //если знак операции и не скобка 
		{
			x = znak->inf; //первый элемент стека
			if (prior(s1) > prior(x)) { //приоритет знака операции > приоритета элемента стека
				push(znak, s1); //записываем знак операции в стек
			}
			else
			{
				while (znak) {
					if (prior(s1) <= prior(x)) {//пока приоритет знака операции <= приоритета элемента стека
					x = pop(znak);
					res = res + x;
					break;
				}
			}
			push(znak, s1); //записываем знак операции в стек
			}
		}
	}
	while (znak) {//пока стек не пуст
		x = pop(znak); //извлекаем из стека вершину
		res = res + x; //и записывем в результат
	}
	cout << "rezultat = " << res;
	return 0;
}