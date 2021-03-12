/*
Представьте, что анализируете запросы пользователей в вашей поисковой системе.
Есть слова запроса и описание животного. Посчитайте релевантность запроса — размер
множества слов, которые входят и в запрос, и в описание.

Формат ввода
Сначала вводится строка-запрос, затем с новой строчки строка-описание.
В примерах \n — символ переноса строчки. Слова до \n — это запрос.
Слова после \n — **описание.

Формат вывода
Выведите единственное целое число — размер пересечения множеств слов из запроса и описания.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int CalculateSimilarity(vector<string> first, vector<string> second) {
    std::set<string> lhs{first.begin(), first.end()};
    std::set<string> rhs{second.begin(), second.end()};

    vector<string> result;
    std::set_intersection(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), back_inserter(result));
    return result.size();
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
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;

    return 0;
}
