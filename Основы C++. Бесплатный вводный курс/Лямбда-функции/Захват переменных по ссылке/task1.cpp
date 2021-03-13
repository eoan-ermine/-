/*
В приют привозят собак разных пород. В словаре shelter по названию хранится
количество особей каждого вида на текущий момент. Приют может принять определённое
количество собак каждой породы. Оно указано в словаре max_amount. Напишите функцию,
которая будет на основании вектора с именами поступивших собак обновлять словарь
shelter и возвращать общее количество попавших в приют собак. Гарантируется, что
никакие другие собаки, кроме известных из словаря max_amount, в приют не приедут.
*/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs,
    const map<string, int>& max_amount, map<string, int>& shelter) {
    return count_if(new_dogs.begin(), new_dogs.end(), [&shelter, &max_amount](const string& dog) {
        bool pred = shelter[dog] < max_amount.at(dog);
        if(pred) { ++shelter[dog]; }
        return pred;
    });
}

int main() {}
