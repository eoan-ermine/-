/*
Внедрите лямбда-функцию в код метода FindTopDocuments вашей поисковой системы.
*/

// ...
vector<Document> FindTopDocuments(const string& query) const {
	// ...
	sort(matched_documents.begin(), matched_documents.end(),
		[](const Document& lhs, const Document& rhs) {
			return lhs.relevance > rhs.relevance;
	});
	// ...
}
// ...
