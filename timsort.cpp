#include <iostream>  
using namespace std;
const int RUN = 64;

int min(int x, int y) { // подпрограмма выбора минимума
    if (x < y) {
        return x;
    }
    else {
        return y;
    }
}
// сортировка вставками
void vstavka(int* array, int start_index, int end_index) {
    for (int i = start_index + 1, j, temp; i <= end_index; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && temp <= array[j]) {
            array[j + 1] = array[j]; //меняем местами 
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}
// подпрограмма слияния
void  sliaynie(int* array, int start_index, int mid, int end_index) {
    int i, j, k;
    int left_size = mid - start_index + 1;
    int right_size = end_index - mid;
    int* left_array;
    int* right_array;
    left_array = new int [left_size];
    right_array = new int [right_size];
    for (int i = 0; i < left_size; i++) {
        left_array[i] = array[start_index + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_array[j] = array[mid + 1 + j];
    }
    i = 0, j = 0, k = start_index;
    for (; i < left_size && j < right_size; k++) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
    }
    for (; i < left_size; i++, k++) {
        array[k] = left_array[i];
    }
    for (; j < right_size; j++, k++) {
        array[k] = right_array[j];
    }
}
// подпрограмма сортировки timsort
void timsort(int* array, int size) {
    for (int i = 0; i < size; i = i + RUN) { // если размер массива меньше 64, то он просто сортируется с помощью сортировки по вставке
        vstavka(array, i, min((i + RUN - 1), (size - 1))); // сортировка вставками
    }
    for (int n = RUN; n < size; n *= 2) {   // после каждой итерации удваивается размер объединенного подмассива
        for (int start_index = 0; start_index < size; start_index += 2 * n) {
            int mid = start_index + n - 1;
            int end_index = min((start_index + 2 * n - 1), (size - 1));
            if (mid < end_index) {
                sliaynie(array, start_index, mid, end_index); // подпрограмма слияния
            }
        }
    }
}
int main() {  // определение массива чисел
    int* array;
    int size;
    cout << "Enter size:" << endl; // определение размерности массива
    cin >> size;
    array = new int[size];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i]; // ввод массива целых чисел
    }
    timsort(array, size); // вызов подпрограммы сортировки чисел 
    cout << "Sorted Array:" << endl; // вывод на экран массива отсортированных чисел
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
