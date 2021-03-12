/*
Напишите программу, которая считывает три целых числа и проверяет, что ровно два из них — положительные.
Например, если на вход подаётся 1 1 0, программа должна вывести true, а если введено 1 1 1 или 0 0 0 — false.
Попробуйте решить задачу, не применяя yf.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector values{a, b, c};
    cout << boolalpha << (count_if(values.begin(), values.end(), [](int value) { return value > 0; }) == 2);
}
