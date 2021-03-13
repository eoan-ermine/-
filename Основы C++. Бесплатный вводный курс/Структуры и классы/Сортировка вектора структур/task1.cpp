/*
В коде поисковой системы документы должны быть отсортированы по
убыванию релевантности. Напишите функцию-компаратор,
которую нужно передать в такую сортировку.
*/

bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
	return lhs.relevance > rhs.relevance;
}
