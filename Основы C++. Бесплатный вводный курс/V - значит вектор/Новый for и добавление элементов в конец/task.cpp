/*
Доработайте разбиение строки на слова. Сложите слова в вектор строк words, а затем выведите его содержимое в формате:
for (string word : words) {
    cout << '[' << word << ']' << endl;
}
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string query;
    getline(cin, query);

	string current_string = "";
	vector<string> words;

    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == ' ') {
            words.push_back(current_string);
			current_string.clear();
        } else {
			current_string += query[i];
		}
    }
	words.push_back(current_string);

	for(string& e: words) {
		cout << '[' << e << ']' << endl;
	}
}


