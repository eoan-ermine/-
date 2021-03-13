/*
Код поисковой можно ускорить. Примените политику параллельного исполнения.
Новая для вас библиотека utility содержит реализацию пары.
*/

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <execution>


vector<pair<int, int>> FindTopDocuments(
        const map<string, set<int>>& word_to_documents,
        const set<string>& stop_words,
        const string& query) {
    auto matched_documents = FindAllDocuments(word_to_documents, stop_words, query);

    sort(execution::par, matched_documents.begin(), matched_documents.end());
    reverse(execution::par, matched_documents.begin(), matched_documents.end());
    if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
        matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    for (auto& matched_document : matched_documents) {
        swap(matched_document.first, matched_document.second);
    }
    return matched_documents;

    /*
        Паралелльный accumulate:

        #include <numeric>
        reduce(execution::par, vec.begin(), vec.end(), 0);
    */
}
