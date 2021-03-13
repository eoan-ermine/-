/*
В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N
строк S. Между собой число и строки разделены пробелом.

Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя
регистр букв, и выведите их в стандартный поток вывода через пробел.

После последней строки также выведите пробел и, затем, перевод строки.
*/

#include <iostream>
#include <string>
#include <vector>
#include <execution>

using namespace std;

int main() {
	int n; cin >> n;
	vector<string> words;

	for(int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		words.push_back(word);
	}



	sort(execution::par, words.begin(), words.end(), [](const string& lhs,
		const string& rhs) {
		return lexicographical_compare(
			lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end(),
			[](char c1, char cr) { return tolower(cl) < tolower(cr); }
		);
	});

	for(int i = 0; i < n; ++i) {
		cout << words[i] << " ";
	}
	return 0;
}
