#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian"); 
	const int max_mist = 8; // максимально количество ошибок, которое можно допустить
	vector<string>words; // слова для угадывания
	words.push_back("FREEDOM");
	words.push_back("HAPPINESS");
	words.push_back("SUCCESS");
	words.push_back("HEALTH");
	words.push_back("ENTHUSIASM");
	words.push_back("INSPIRATION");
	words.push_back("SECURITY");
	words.push_back("CONDITION");
	words.push_back("FORWARD");
	words.push_back("DISCUSS");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end()); // произвольная перестановка
	const string word = words[0]; // слово для отгадывания 
	int cnt_mist = 0; // количество ошибок
	string part_word(word.size(), '-'); // открытая часть слова
	string used = "";  // отгаданные буквы

	cout << "Добро пожаловать в игру Виселица " << endl;
	while ((cnt_mist < max_mist) && (part_word != word)) {  // пока кол-во ошибок меньше макс кол-ва ошибок и часть слова не равна слову
		cout << "Осталось неправильных попыток " << (max_mist - cnt_mist) << endl;
		cout << "Вы использовали следующие буквы: " << used << endl;
		cout << "Слово\n" << part_word << endl;
		char bukv;
		cout << "Введите вашу букву ";
		cin >> bukv;
		bukv = toupper(bukv); // перевод буквы в верхний регистр
		while (used.find(bukv) != string::npos) {
			cout << "\nВы уже вводили " << bukv << endl;
			cout << "Введите вашу букву: " << endl;
			cin >> bukv;
			bukv = toupper(bukv);
		}
		used += bukv; // добавление буквы в отгаданные
		if (word.find(bukv) != string::npos) {
			cout << "Правильно. Буква " << bukv << " есть в слове. " << endl;
			for (int i = 0; i < word.length(); ++i) { // включение новой угаданной буквы в part_word
				if (word[i] == bukv) {
					part_word[i] = bukv;
				}
			}
		}
		else {
			cout << "Сожалею. Буквы " << bukv << " нет в слове. " << endl;
			cnt_mist += 1;
		}

	}

	if (cnt_mist == max_mist) {  // если кол-во ошибок равно максимальному
		cout << "Вы проиграли" << endl;
	}
	else {
		cout << "Вы отгадали слово" << endl;
	}
	cout << "Это слово " << word << endl;
	
	return 0;
}
