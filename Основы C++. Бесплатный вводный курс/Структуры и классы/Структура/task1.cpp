/*
Начнём избавляться от пар в коде поисковой системы. Вам понадобятся
функции из урока «‎Ранжирование по релевантности» из предыдущей темы.
Перепишите на структуру Document функцию FindAllDocuments, которая
возвращает все подходящие документы. Объявите структуру Document так же,
как в уроке. Замените все пары на структуры. Верните из функции вектор
этих структур.
*/

#include <vector>

struct Document {
    int id;
    int relevance;
};

vector<Document> FindAllDocuments(...) {
    // ...
    vector<Document> matched_documents;
    for (auto [document_id, relevance] : document_to_relevance) {
            matched_documents.push_back(Document{document_id, relevance});
    }
    return matched_documents;
}