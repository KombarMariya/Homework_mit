#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) { // вставка элемента в конец списка
    list* r = new list; // создаем новый элемент
    r->inf = x;
    r->next = NULL; 
    if (!h && !t) { // если список пуст
        r->prev = NULL; // первый элемент
        h = r; // голова
    }
    else {
        t->next = r; // r - следующий для хвоста
        r->prev = t; // хвост - предыдущий для r
    }
    t = r; // r теперь хвост
}

void print(list* h, list* t) { // печать элементов списка
    list* p = h; // указатель на голову
    while (p) { // пока не дошли до конца списка
        cout << p->inf;
        p = p->next; // переход к следующему элементу
    }
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    list* spisok = NULL; //инициализация
    list* nchspisok = NULL; 
    list* chspisok = NULL; 
    list* tail = NULL; 
    list* chtail = NULL; 
    list* nchtail = NULL; 

    int x;
    for (int i = 0; i < n; i++) { // заполнение списка
        cin >> x;
        push(spisok, tail, x);
    }
    while (spisok) { // пока не дошли до конца списка
        if (spisok->inf % 2 == 0) { // заполняем список четных
            push(chspisok, chtail, spisok->inf);
        }
        if (spisok->inf % 2 != 0) { // заполняем список нечетных
            push(nchspisok, nchtail, spisok->inf);
        }
        spisok = spisok->next; // следующий элемент списка
    }

    spisok = chspisok; // меняем указатели
    tail = chtail;

    while (nchspisok) { // пока не дошли до конца списка
        push(spisok, tail, nchspisok->inf); // добавляем в список нечетные
        nchspisok = nchspisok->next; // следующий элемент списка
    }

    cout << "result:" << endl; //п ечать результата 
    print(spisok, tail);

    return 0;
}
