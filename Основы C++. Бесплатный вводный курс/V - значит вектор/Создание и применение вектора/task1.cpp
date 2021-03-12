/*
Напишите программу, которая считывает номер месяца в нумерации с нуля (0 — это январь, 11 — декабрь) и выводит количество дней в нём.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> month_lengths = {31,28,31,30,31,30,31,31,30,31,30,31};
	int month; cin >> month;
	cout << month_lengths[month];
}
