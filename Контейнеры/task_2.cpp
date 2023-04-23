#include <algorithm>
#include <iostream>
#include <set>
#include <iterator> 
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	set <int> st, new2st, new3st, reslt; // определение сетов
	for (int i = 0; i < 10; i++) { // добавление случайных значений
		int random = rand() % 300 + 1;
		st.insert(random);
	}
	cout << "Содержимое st: " << endl;
	copy(st.begin(), st.end(), ostream_iterator<int>(cout, " "));
	for (int i = 10; i <= 99; i++) {
		auto result = st.find(i);
		if (result != st.end()) { // если двузначное число нашлось
			int numb = i;
			while (numb > 0) { // разбиение двузначного числа на цифры
				int dig = numb % 10;
				numb = numb / 10;
				new2st.insert(dig); // запись цифр двузначного числа в set
			}
		}
	}
	cout << '\n' << "Цифры двузначных чисел: " << endl;
	copy(new2st.begin(), new2st.end(), ostream_iterator<int>(cout, " "));
	for (int i = 100; i <= 999; i++) { 
		auto result = st.find(i);
		if (result != st.end()) {  // если трехзначное число нашлось
			int numb = i;
			while (numb > 0) {   // разбиение трехзначного числа на цифры
				int dig = numb % 10;
				numb = numb / 10;
				new3st.insert(dig); // запись цифр трехзначного числа в set
			}
		}
	}
	cout << '\n' << "Цифры трехзначных чисел: " << endl;
	copy(new3st.begin(), new3st.end(), ostream_iterator<int>(cout, " "));

	// вычитание new3st из new2st и запись остатка в reslt
	set_difference(new2st.begin(), new2st.end(), new3st.begin(), new3st.end(), inserter(reslt, reslt.end()));
	cout << '\n' << "Результат : " << endl;
	copy(reslt.begin(), reslt.end(), ostream_iterator<int>(cout, " "));
	return 0;
}