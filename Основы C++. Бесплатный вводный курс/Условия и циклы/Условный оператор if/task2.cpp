/*
В предыдущей теме вы написали код программы, которая:
считывает число — количество документов;
выводит на экран, сколько документов найдено: <число документов> documents found

Программа работает, но слово “document” всегда пишет во множественном числе —
например, 1 documents found. Отредактируйте код. Если на вход дан 0,
пусть программа выводит No documents found, если 1 — One document found.
Во всех остальных случаях программа должна выводить <число документов>
documents found.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
        int document_found = 0;
        cin >> document_found;

        string message;
        if(document_found == 0) {
                message = "No documents found";
        } else if(document_found == 1) {
                message = "One document found";
        } else {
                message = to_string(document_found) + " documents found"s;
        }
        cout << message << endl;
}
