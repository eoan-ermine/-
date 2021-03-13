#include <set>
#include <string>
#include <numeric>

using namespace std;

string AddStopWords(const string& query, const set<string>& stop_words) {
    if(stop_words.size() == 0) { return query; }
    return query + " " + accumulate(
        std::next(stop_words.begin()), stop_words.end(), *stop_words.begin(),
        [](const string& lhs, const string& rhs) {
            return "-"s + lhs + " "s + "-"s + rhs;
        });
}