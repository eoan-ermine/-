/*
Теперь выведите сами слова, заключённые в квадратные скобки. Например, если ввод был green  parrot, вывод должен быть:

[green]
[]
[parrot]

В квадратных скобках посередине здесь — пустое слово. То есть между скобками ничего нет, так как в исходной строке было два пробела подряд. Накапливайте в строковую переменную символы текущего слова. Когда слово закончится, выведите его в квадратных скобках и начните накапливать следующее.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string query;
    getline(cin, query);

    string current_string = "";

    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == ' ') {
            cout << "[" << current_string << "]" << endl;
            current_string = "";
        } else {
            current_string += query[i];
        }
    }
    cout << "[" << current_string << "]" << endl;
}
