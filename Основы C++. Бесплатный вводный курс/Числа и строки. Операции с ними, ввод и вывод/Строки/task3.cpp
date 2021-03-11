/*
    Напишите программу, которая считывает названия трёх книг
    по одному в строке и выводит их в обратном порядке,
    тоже по одному в строке
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long unsigned int n = 3;
    std::vector<std::string> lines(n);

    std::string value;
    for(int i = 0; i < n; ++i) {
        getline(cin, value);
        lines[i] = value;
    }

    for(auto it = lines.rbegin(); it != lines.rend(); ++it) {
        cout << *it << '\n';
    }
}