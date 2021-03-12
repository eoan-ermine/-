
/*
Напишите функцию, которая
называется PalindromeFilter,
возвращает vector<string>,
принимает vector<string> words и int min_length ,
возвращает из вектора words все строки-палиндромы длиной не меньше min_length.
*/

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool IsPalindrome(const string& s) {
    return std::equal(s.begin(), s.end(), s.rbegin(), s.rend());
}

vector<string> PalindromeFilter(const vector<string>& words, int min_length) {
    vector<string> result;

    std::copy_if(words.begin(), words.end(), back_inserter(result), [min_length](const string& e) {
        return ((IsPalindrome(e)) && (e.size() >= min_length));
    });
    return result;
}

int main() { }
