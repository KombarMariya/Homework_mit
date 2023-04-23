#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <iterator>
using namespace std;
int main() {
	setlocale(LC_ALL, "russian");
	string s1 = "Did you do your homework yesterday? I am not going with you tomorrow. I have been looking for you for so long!";
	string razd = "!.?";
	char tmp;
	string word;  
	set <string> vopr, vosk, pov, voskvopr, res;
	string::size_type k, k1, pos, pos1;
	pos = 0;
	k = s1.find_first_of(razd, pos); // поиск конца 1 предложения
	while (k != string::npos) {  // выполняется, пока не закончится текст
		tmp = s1[k]; // выделяется разделительный знак предложения . или ? или !
		string temp = s1.substr(pos, k - pos); // выделяется из текста строка предложения
		temp = temp + " ";  // добавление в конце предложения пробела
		pos1 = 0;
		k1 = temp.find_first_of(" ", pos1); // поиск конца первого слова предложения
		while (k1 != string::npos) {  // выполняется, пока предложение не закончится
			word = temp.substr(pos1, k1 - pos1); // выделяется слово предложения
			transform(word.begin(), word.end(), word.begin(), ::tolower); // перевод слова в нижний регистр
			switch (tmp) { // проверка знака в конце предложения
			case '!':
				vosk.insert(word); // запись в сет восклицательного предложения
				break;
			case '?':
				vopr.insert(word); // запись в сет вопросительного предложения
				break;
			case '.':
				pov.insert(word); // запись в сет повествовательного предложения
				break;
			}
			pos1 = k1 + 1; // pos1 - начало следующего слова предложения
			k1 = temp.find_first_of(" ", pos1); // к1 -  конец следующего слова предложения
		}
		pos = k + 2; // переход к началу следующего предложения
		k = s1.find_first_of(razd, pos); // поиск конца следующего предложения
	}
	// печать содержимого сетов
	cout << '\n' << "Слова вопросительных предложений:" << endl;
	copy(vopr.begin(), vopr.end(), ostream_iterator<string>(cout, " "));
	cout << '\n' << "Слова восклицательных предложений:" << endl;
	copy(vosk.begin(), vosk.end(), ostream_iterator<string>(cout, " "));
	cout << '\n' << "Слова повествовательных предложений:" << endl;
	copy(pov.begin(), pov.end(), ostream_iterator<string>(cout, " "));
	// слияние вопросительных предложений и восклицательных предложений
	voskvopr.insert(vosk.begin(), vosk.end());
	voskvopr.insert(vopr.begin(), vopr.end());
	cout << '\n' << "Слова, которые есть только в повествовательных предложениях:" << endl;
	set_difference(pov.begin(), pov.end(), voskvopr.begin(), voskvopr.end(), inserter(res, res.end()));
	copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
	cout << '\n' << "Количество слов, которые есть только в повествовательных предложениях:" << endl;
	cout << res.size();
	return 0;
}