/*
    Напишите программу, которая считывает число
    (количество документов) и выводит на экран
    <число документов> documents found. Сначала сформируйте
    строку с ответом, только потом выведите её на экран
    целиком.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int count_of_documents; cin >> count_of_documents;
    std::string output = to_string(count_of_documents) + " documents found";
    cout << output;
}