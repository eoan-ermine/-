/*
Напишите функцию MoveStrings. Она принимает векторы строк source и destination
и дописывает все строки из первого вектора в конец второго. После выполнения
функции вектор source должен быть пустым.
Чтобы очистить содержимое вектора, вызовите у него метод clear
*/


#include <string>
#include <utility>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for(string& x: source) {
		destination.push_back(move(x));
	}
	source.clear();
}
