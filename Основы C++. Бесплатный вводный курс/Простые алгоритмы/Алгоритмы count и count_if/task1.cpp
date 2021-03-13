/*
Ранее вы реализовали функцию PrintWorryCount. Перепишите её, используя count.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintWorryCount(const vector<bool>& is_nervous) {
	cout << count(is_nervous.begin(), is_nervous.end(), true) << endl;
}

int main() {
    // не меняйте содержимое функции main
    PrintWorryCount({true, true, false, true});
    return 0;
}
