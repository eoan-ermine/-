/*
    Напишите программу, которая считывает два double-числа и
    выводит целую часть их суммы.
*/

#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout << static_cast<int>(a + b) << endl;
}