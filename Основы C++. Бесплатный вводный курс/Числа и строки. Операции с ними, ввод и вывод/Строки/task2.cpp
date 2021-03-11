/*
    Напишите программу, которая считывает имя и фамилию и
    выводит полное имя в формате <Фамилия>, <Имя>.
    Примените оператор сложения, чтобы соединить части строк
    в одну строку. Имя и фамилия во вводе даны на одной строке
    и разделены пробелом.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string name, surname;
    cin >> name >> surname;
    cout << surname + ", " + name;
}