/* Напишите функцию, которая принимает вектор строк и возвращает число строк,
начинающихся на большую или маленькую английскую букву "a". */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* C++ 20

int CountStartsWithA(const vector<string>& xs) {
	return count_if(xs.begin(), xs.end(), [](const string& e)
					{ return e.starts_with('a') || e.starts_with('A'); });
}

*/

int CountStartsWithA(const vector<string>& xs) {
    return count_if(xs.begin(), xs.end(), [](const string& e)
                    { return e.starts_with('a') || e.starts_with('A'); });
}

