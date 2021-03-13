/*
Считайте количество людей, имя и возраст каждого. Выведите все имена с
новой строки по старшинству — от старых к молодым.

Вектор пар сортируется лексикографически. Например, у вас есть вектор:

vector<pair<int, double>> values = {{5, -1.1}, {5, -1.0}, {1, 0.0}};

После сортировки значения будут в таком порядке:
{1, 0.0}
{5, -1.1} // 1 < 5
{5, -1.0}, // 5 == 5, -1.1 < -1.0
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int count;
    cin >> count;
    vector<pair<int, string>> people;

    for(int i = 0; i < count; ++i) {
        string name; int age;
        cin >> name >> age;
        people.push_back(pair(age, name));
    }

    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());

    for(const auto& [_, name]: people) {
        cout << name << endl;
    }
}

