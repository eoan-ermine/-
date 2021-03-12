/*
В прошлой теме вы усовершенствовали разбиение строки на слова: создали и
заполнили вектор строк words. Теперь вынесите разбиение в отдельную функцию
vector<string> SplitIntoWords(string text), которая принимает на вход строку и
возвращает вектор слов.
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> SplitIntoWords(const string& text) {
	vector<string> words;
	string word;

	for(int i = 0; i < text.size(); ++i) {
		if(text[i] == ' ') {
			words.push_back(word);
			word = "";
		} else {
			word += text[i];
		}
	}
	words.push_back(word);
	return words;
}

int main() {
	string query;
	getline(cin, query);
	for(string& word: SplitIntoWords(query)) {
		cout << '[' << word << ']' << endl;
	}
}
