/*
Вы уже можете начать рефакторить код поисковой системы. Перенесите основную логику
в класс SearchServer.
Начните с метода AddDocument, чтобы получился такой класс, как в примере. Названия
полей остаются на ваше усмотрение, но сам класс надо назвать SearchServer, а его
пока единственный метод — AddDocument. Проверки main и других функций, не нужных в
AddDocument, в этот раз не будет. Но их код ещё предстоит переделать. Не теряйте
его. Для комментирования кода в этой задаче используйте многострочные комментарии.
*/

#include <set>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <execution>
#include <algorithm>

using namespace std;

int MAX_RESULT_DOCUMENT_COUNT = 5;

struct Document {
	int id;
	int relevance;
};

bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
	return lhs.relevance > rhs.relevance;
}

class SearchServer {
private:
	set<string> stop_words;
	map<string, set<int>> word_to_documents;

	vector<string> SplitIntoWords(const string& text) const {
		vector<string> words;
		string word;
		for(const char c: text) {
			if(c == ' ') {
				words.push_back(word);
				word = "";
			} else {
				word += c;
			}
		}
		words.push_back(word);
		return words;
	}

	vector<string> SplitIntoWordsNoStop(const string& text) const {
		vector<string> words;
		for(const string& word: SplitIntoWords(text)) {
			if(stop_words.count(word) == 0) {
				words.push_back(word);
			}
		}
		return words;
	}

	vector<Document> FindAllDocuments(const string& query) const {
		map<int, int> document_to_relevance;
		const vector<string> query_words = SplitIntoWordsNoStop(query);
		for(const string& word: query_words) {
			if(word_to_documents.count(word) == 0) {
				continue;
			}
			for(const int document_id: word_to_documents.at(word)) {
				++document_to_relevance[document_id];
			}
		}
		vector<Document> matched_documents;
		for(auto [document_id, relevance]: document_to_relevance) {
			matched_documents.push_back({document_id, relevance});
		}
		return matched_documents;
	}
public:
	void AddDocument(int document_id, const string& document) {
		for(const string& word: SplitIntoWordsNoStop(document)) {
			word_to_documents[word].insert(document_id);
		}
	}
	void SetStopWords(const string& text) {
		for(const string& word: SplitIntoWords(text)) {
			stop_words.insert(word);
		}
	}

	vector<Document> FindTopDocuments(const string& query) const {
		auto matched_documents = FindAllDocuments(query);

		sort(execution::par, matched_documents.begin(), matched_documents.end(),
			 HasDocumentGreaterRelevance);
		if(matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
			matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
		}
		return matched_documents;
	}
};

string ReadLine() {
	string s;
	getline(cin, s);
	return s;
}

int ReadLineWithNumber() {
	int result;
	cin >> result;
	ReadLine();
	return result;
}

SearchServer CreateSearchServer() {
	SearchServer server;

	const string stop_words_joined = ReadLine();
	server.SetStopWords(stop_words_joined);

	const int document_count = ReadLineWithNumber();
	for(int document_id = 0; document_id < document_count; ++document_id) {
		server.AddDocument(document_id, ReadLine());
	}

	return server;
}

int main() {
	const SearchServer server = CreateSearchServer();
	server.FindTopDocuments("hello"s);
}
