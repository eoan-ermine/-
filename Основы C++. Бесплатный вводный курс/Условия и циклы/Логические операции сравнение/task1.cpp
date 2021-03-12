/*
Вы узнали, как сравнивать неравные объекты. С равными объектами то же самое, только оператор сравнения будет ==. 
Напишите код, который сравнивает половины апельсина. Программа считывает два вещественных числа — размеры половинок.
Если числа равны, программа должна выводить на экран The orange is divided into two equal parts. Если первое число больше,
пусть программа выводит Cut off X from the first part. Если больше второе число — пусть выводит Cut off X
from the second part. Вместо X подставьте разницу в размере.
*/

#include <iostream>

using namespace std;

int main() {
	double first_size, second_size;
	cin >> first_size >> second_size;
	double delta = std::abs(second_size - first_size);

	if(first_size == second_size) {
		cout << "The orange is divided into two equal parts";
	} else if(first_size > second_size) {
		cout << "Cut off " << delta << " from the first part";
	} else {
		cout << "Cut off " << delta << " from the second part";
	}
}
