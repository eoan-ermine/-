/*
Научите свою поисковую систему отбрасывать стоп-слова. На вход примите сначала
строку стоп-слов, а затем с нового абзаца — строку-запрос.
Выводите только те слова, которых нет в списке запрещённых.
Формат вывода слов оставьте как в заготовке кода.

Функция разбиения строки на слова у вас уже реализована, осталось сделать
фильтрацию.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> RemoveStopWords(const vector<string>& words, const vector<string>& stop_words) {    
    std::set<string> stop_s{stop_words.begin(), stop_words.end()};
    std::vector<string> result;

    for(auto& x: words) {
        if(!stop_s.count(x)) {
            result.push_back(x);
        }
    }
    return result;
}

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
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
    string stop_words;
    getline(cin, stop_words);

    string query;
    getline(cin, query);

    for(string word: RemoveStopWords(SplitIntoWords(query), SplitIntoWords(stop_words))) {
        cout << '[' << word << ']' << endl;
    }
}
