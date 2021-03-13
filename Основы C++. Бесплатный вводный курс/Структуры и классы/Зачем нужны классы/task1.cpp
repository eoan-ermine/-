/*
Посмотрите, как работает тип данных class.
Объявите в функции main переменную типа SearchServer и обратитесь к одному из её
полей — например, выведите количество стоп-слов во множестве. Вы получите ошибку
компиляции об обращении к приватному полю. Это нормально.

Напишите прямо внутри класса функцию, которая будет возвращать нужный размер
множества стоп-слов. Такая функция называется метод. Так как метод находится внутри
класса, он имеет доступ к его полям. Чтобы вызвать метод, снабдите его пометкой
public: как показано в примере кода.

Сделайте свободную функцию GetStopWordsSize. Вызовите в ней вышеописанный метод у
переданного в функцию по константной ссылке сервера.
*/

#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class SearchServer {
    map<string, set<int>> word_to_documents_;
    set<string> stop_words_;
public:
    int GetStopWordsSize() const {
        return stop_words_.size();
    }
};

int GetStopWordsSize(const SearchServer& server) {
    return server.GetStopWordsSize();
}

int main() {
	SearchServer server;
	cout << server.GetStopWordsSize() << endl;
}
