/*
Поисковые системы логируют запросы, чтобы потом исследовать их и улучшать качество
поиска. Смоделируйте такое исследование и напишите программу, которая изучает
популярность определённой темы у пользователей. На вход программа получает
список поисковых запросов и слово. Программа должна вывести количество
поисковых запросов, содержащих данное слово.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}

int main() {
    int queryCount = ReadLineWithNumber();

    vector<string> queries(queryCount);
    for (string& query : queries) {
        query = ReadLine();
    }
    string buzzword = ReadLine();

    cout << count_if(queries.begin(), queries.end(), [&buzzword](const string& query) {
        return query.find(buzzword) != string::npos;
    });
    cout << endl; 
}
