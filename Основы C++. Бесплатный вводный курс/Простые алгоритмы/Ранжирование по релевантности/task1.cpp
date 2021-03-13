/*
Пусть ваша поисковая система возвращает не любые документы, а документы
с самой высокой релевантностью. Напишите функцию FindTopDocuments,
которая должна находить только MAX_RESULT_DOCUMENT_COUNT = 5 результатов.
Объявите эту глобальную константу вверху своего решения. Функцию
FindTopDocuments поместите там же, где для вывода итогового результат мы
вызывали FindDocuments. Саму FindDocuments замените на функцию
FindAllDocuments, которая будет возвращать все результаты поиска в виде
пар из идентификатора документа и релевантности {document_id, relevance}.
Отсортируйте результат FindAllDocuments по убыванию, чтобы использовать
его в FindTopDocuments.
*/

#include <vector>
#include <map>
#include <string>
#include <set>
#include <utility>

vector<pair<int, int>> FindTopDocuments(
        const map<string, set<int>>& word_to_documents,
        const set<string>& stop_words,
        const string& query
) {
    vector<pair<int, int>> allDocs = FindAllDocuments(
        word_to_documents, stop_words,
        query
    );
    sort(allDocs.begin(), allDocs.end(),
    [](const auto& lhs, const auto& rhs) {
        return pair(lhs.second, lhs.first) > pair(rhs.second, rhs.first);
    });
    if(allDocs.size() > MAX_RESULT_DOCUMENT_COUNT) {
        allDocs.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    return allDocs;
}
