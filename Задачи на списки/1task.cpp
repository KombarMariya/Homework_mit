#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void insert_after(list*& h, list*& t, list* r, int y) { // вставляем после r
    list* p = new list; // создаем новый элемент
    p->inf = y;
    if (r == t) { // если вставляем после хвоста
        p->next = NULL; // вставляемый элемент - последний
        p->prev = r; // вставляем после r
        r->next = p;
        t = p; // теперь хвост - p
    }
    else { // вставляем в середину списка
        r->next->prev = p; // для следующего за r элемента предыдущий - p
        p->next = r->next; // следующий за p - следующий за r
        p->prev = r; // p вставляем после r
        r->next = p;
    }
}

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
    list* minspisok = NULL; 
    list* tail = NULL; 
    list* mintail = NULL; 
    list* res = NULL; 
    list* restail = NULL; 

    int x; 
    int minspis = 10000;
    int fst;
    int i = 0;

    for (int i = 0; i < n; i++) { // заполнения списка
        cin >> x;
        push(spisok, tail, x);
    }

    minspisok = spisok;
    mintail = tail;

    while (spisok) { // пока не дошли до конца списка
        if (spisok->inf < minspis) { // поиск минимума
            minspis = spisok->inf;
        }
        spisok = spisok->next; // следующий элемент списка
    }
    while (minspisok) { // пока не дошли до конца списка
        int sp = minspisok->inf;
        if (i == 0) { // если первый элемент в списке
            fst = sp; // присваиваем переменной fst значение первого элемента
            i = 1; // i=1 первый элемент прошли
        };
        if (sp == fst) { 
            insert_after(minspisok, mintail, minspisok, minspis); // вставка минимального после элемента, равного первому
        }
        push(res, restail, sp); // запись в итоговый список
        minspisok = minspisok->next; // следующий элемент списка
    }
         
    cout << "result:" << endl; // печать результата 
    print(res, restail);

    return 0;
}
