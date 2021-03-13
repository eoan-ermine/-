/*
Не всегда ответ на запрос соответствует ожиданиям. Чем результат ближе к
ожидаемому, тем выше его релевантность исходному запросу.
Научите свою поисковую систему считать релевантность возвращённого в
ответе документа — то есть количество уникальных слов, пересекающихся с
запросом.

Релевантность нужно возвращать вместе с идентификатором документа как пару из
двух целых чисел {document_id, relevance}. Иными словами, функция
FindDocuments теперь должна выглядеть так:

vector<pair<int, int>> FindDocuments(
        const map<string, set<int>>& word_to_documents,
        const set<string>& stop_words,
        const string& query);

*/

#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>

using namespace std;

vector<pair<int, int>> FindDocuments(const map<string, set<int>>& word_to_documents,
                          const set<string>& stop_words,
                          const string& query) {
	const vector<string> query_words = SplitIntoWordsNoStop(query, stop_words);
    map<int, int> document_to_relevance;

	for (const string& word : query_words) {
		if (word_to_documents.count(word) == 0) {
			continue;
		}
        for(int document_id: word_to_documents.at(word)) {
            ++document_to_relevance[document_id];
        }
	}
	return {document_to_relevance.begin(), document_to_relevance.end()};
}
