/*
Напишите функцию CountNames. Пусть она выясняет, какие слова из списка
содержатся во множестве, и возвращает ответ в виде вектора единиц и нулей.
Список кандидатов дан в виде вектора строк. Если слово есть во множестве,
в ответе будет единица, иначе — ноль. В коде вы видите библиотеку <chrono>.
Она содержит элементы, связанные с концептами времени.
*/

#include <vector>
#include <set>
#include <string>

vector<int> CountNames(const set<string>& storage, const vector<string>& candidates) {
    vector<int> output;
    for(auto& name: candidates) {
        output.push_back(storage.count(name));
    }
    return output;
}
