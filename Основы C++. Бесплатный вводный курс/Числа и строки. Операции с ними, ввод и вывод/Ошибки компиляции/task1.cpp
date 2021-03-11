/*
    #include <io_stream>

    // using namespace std;

    int ma() {
        int x;
        cin >> x, y;

        z = 1;
        cout << 'Your answer: ';
    }

    cout < x + y + z;
*/

/*
    Перед вами программа. Она должна считывать два целых
    числа — x и y — и выводить в одну строку "Your answer: "
    и сумму чисел x + y + z, где z = 1. Но в коде есть ошибки
    компиляции. Исправьте их по одной и посмотрите,
    как меняются сообщения об ошибках.
*/

#include <iostream>

using namespace std;

int main() {
    int x, y, z = 1;
    cin >> x >> y;

    cout << "Your answer: ";
    cout << x + y + z;
}
