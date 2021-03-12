/*
Напишите функцию IsPalindrome(string), которая проверяет, будет ли строка
палиндромом. Если строка — палиндром, пусть функция печатает 1, а если нет — 0.
Пустая строка считается палиндромом.
*/

#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    cout << (s == string{s.rbegin(), s.rend()}) << endl;
}

int main() {
    IsPalindrome("ara"s);
    IsPalindrome("deer"s);
    return 0;
}
