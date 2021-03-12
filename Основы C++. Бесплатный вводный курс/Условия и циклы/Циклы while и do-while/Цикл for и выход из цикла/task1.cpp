/*
Считайте два целых числа и выведите все числа от первого до второго включительно. Например, ввели -1 2 — выводите -1, 0, 1, 2
по одному на строке. А если ввели 2 -1 — нужно вывести те же числа в обратном порядке. Примените цикл for.
*/

#include <iostream>

using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int inc = a < b ? 1 : -1;
	for(int i = a; i <= b; i += inc) {
		cout << i << endl;
	}
}


