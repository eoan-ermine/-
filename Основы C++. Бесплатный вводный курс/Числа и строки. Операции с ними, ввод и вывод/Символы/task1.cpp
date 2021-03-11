/*
    Считайте пять слов, разделённых пробельными символами,
    и выведите их первые символы слитно как строку.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n = 5;
    std::string value;
    for(int i = 0; i < n; ++i) {
        cin >> value;
        cout << value[0];
    }
}