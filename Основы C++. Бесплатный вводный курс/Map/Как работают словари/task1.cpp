/*
Иногда нужно срочно найти что-нибудь в значениях, а быстрый поиск работает только
среди ключей. Напишите функцию, которая переворачивает словарь: ключи становятся
значениями, а значения — ключами.
*/

#include <map>
#include <string>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string>& m) {
	map<string, string> result;
	for(const auto& [key, value]: m) {
		result[value] = key;
	}
	return result;
}
