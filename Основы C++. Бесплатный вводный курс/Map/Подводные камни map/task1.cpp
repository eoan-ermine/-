/*
Слова называются анаграммами, если одно из них можно получить перестановкой букв
в другом. Например, “eat” и “tea” — анаграммы, потому что состоят из одних и тех же
букв в разном порядке.
У вас есть пары слов. Проверьте, можно ли назвать слова в каждой паре анаграммами.
Примените map и для всех слов посчитайте, сколько раз в них встречается каждая буква.
Если для обоих слов пары эти словари равны, значит, слова — анаграммы.
В противном случае — нет. Равенство словарей проверяют обычным оператором ==.

Формат ввода
Сначала дано число пар слов N, затем в N-строках содержатся пары слов, которые
необходимо проверить. Гарантируется, что все слова состоят из строчных латинских букв.

Формат вывода
Выведите N строк: для каждой введённой пары слов напечатайте YES, если эти
слова — анаграммы, и NO в противном случае.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> buildFrequencyMap(const string& x) {
	map<char, int> result;
	for(const char& c: x) {
		++result[c];
	}
	return result;
}

bool isAnagram(const string& lhs, const string& rhs) {
	return buildFrequencyMap(lhs) == buildFrequencyMap(rhs);
}

int main() {
	int n; cin >> n;

	for(int i = 0;i < n; ++i) {
		string first_word, second_word;
		cin >> first_word >> second_word;
		if(isAnagram(first_word, second_word)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
