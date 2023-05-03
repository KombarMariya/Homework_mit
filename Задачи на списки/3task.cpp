#include <iostream>
using namespace std;

struct list {
    int inf; // инициализация
    list* next;
    list* prev;
};

void swap(int* a, int* b) {  // подпрограмма обмена 2 элементов 
    int t = *a; *a = *b; *b = t;
}

list* lastNode(list* root) { // подпрограмма поиска последнего элемента связанного списка 
    while (root && root->next) // пока не конец списка
        root = root->next; 
    return root;
}

/* Рассматривает последний элемент как опору,
помещает все меньшие элементы слева от основы и все большие элементы справа от основы
*/
list* partition(list* l, list* h) {
    int x = h->inf; // значение первого элемента
    list* i = l->prev; // указатель на последнем элементе 
    for (list* j = l; j != h; j = j->next) { // выпонять пока указатели начала и конца списка не равны
        if (j->inf <= x) { // если элемент меньше последнего
            i = (i == NULL) ? l : i->next; // если конец списка, то указатель на последний элемент, в противном случае указатель на следующий элемент
            swap(&(i->inf), &(j->inf)); // вызов подпрограммы обмена местами элементов списка
        }
    }
    i = (i == NULL) ? l : i->next; // если конец списка, то указатель на последний элемент, в противном случае указатель на следующий элемент
    swap(&(i->inf), &(h->inf)); // вызов подпрограммы обмена местами элементов списка
    return i;
}

/*рекурсивная реализация быстрой сортировки для связанного списка */
void _quickSort(list* l, list* h) {
    if (h != NULL && l != h && l != h->next) {  // выполнять пока не конец списка и указатели начала и конца списка не равны
        list* p = partition(l, h);
        _quickSort(l, p->prev); // рекурсивный вывод функции
        _quickSort(p->next, h);  // рекурсивный вывод функции
    }
}

void quickSort(list* head) {  // основная функция для сртировки для связанного списка
    // Найдем следующий узел
    list* h = lastNode(head);
    _quickSort(head, h);
}

// Подпрограмма печати содержимого списка
void printList(list* head) {
    while (head) {  // пока не дошли до конца 
        cout << head->inf << " "; 
        head = head->next; // переход к следущему элементу
    }
    cout << endl;
}

/* Подпрограмма вставки в начало связанного списка */
void push(list** head_ref, int new_data) {
    list* p = new list; // создаем новый элемент
    p->inf = new_data; // запись нового значения
    p->prev = NULL; // перевод указателя на 1 элемент
    p->next = (*head_ref); 
    if ((*head_ref) != NULL) (*head_ref)->prev = p; // указатель следующего узла = указателю нового списка
    (*head_ref) = p;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << " n = ";
    cin >> n;
    list* a = NULL;
    int x;
    for (int i = 0; i < n; i++) { //заполняем список 
        cin >> x;
        push(&a, x);
    }
    cout << "Печать списка до сортировки \n";
    printList(a);
    quickSort(a);
    cout << "Печать списка после сортировки \n";
    printList(a);
    return 0;
}
