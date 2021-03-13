/*
Вычислите среднее арифметическое вектора чисел.
Считайте, что среднее арифметическое пустого массива равно нулю.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double Average(const vector<int>& xs) {
    if(xs.size() == 0) {
        return 0;
    }
    return accumulate(xs.begin(), xs.end(), 0.0) / xs.size();
}

int main() {
    // не меняйте код main
    cout << Average({1, 2, 2}) << endl;
    return 0;
}