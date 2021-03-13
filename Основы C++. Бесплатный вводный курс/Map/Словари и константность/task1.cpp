/*
У вас есть четыре документа:

1. a fat cat sat on a mat and ate a fat rat,
2. little funny fluffy cat,
3. the cat,
4. huge green crocodile.

И есть стоп-слова: “a”, “the”, “on”, “cat”. Приходит запрос: funny fat cat.
Найдите все документы, где есть хотя бы одно слово из запроса.
Учтите стоп-слова и не включайте их в результаты поиска. Примерный алгоритм:

1. Берёте слово из запроса, проверяя, что это не стоп-слово;
2. Ищете слово в контейнере;
3. Спрашиваете у контейнера, в каких документах это слово встречается.
У контейнера уже есть ответ;
4. Добавляете индексы документов к результату;
5. Повторяем все шаги для каждого из слов в запросе;
6. Помещаете все результаты в вектор и отправляете пользователю.

Упомянутый в алгоритме контейнер — это map. Ключом в map будет слово,
а значением — некий контейнер документов, в которых это слово встречается.
Важно правильно записывать в словарь элементы в момент добавления документа.

Запрос funny fat cat должен сработать так:

1. Берёте слово “funny”, которое не входит в список стоп-слов;
2. Обращаетесь к словарю и находите в нём “funny”;
3. В словаре по ключу “funny” уже должен быть записан документ 1;
4. Добавляете документ 1 в результирующий вектор;
5. Берёте слово “fat”. Оно тоже не входит в список стоп-слов;
6. В словаре по ключу “fat” лежит документ 0;
7. Добавляете документ к результату;
8. “Cat” — стоп-слово, поэтому оно вам не интересно;
9. Возвращаете пользователю вектор с двумя элементами: 0 и 1.

Напишите функции AddDocument и FindDocuments, которые бы реализовывали решение
описанной задачи. AddDocument должна заполнять индекс word_to_documents:

void AddDocument(map<string, set<int>>& word_to_documents,
                 const set<string>& stop_words,
                 int document_id,
                 const string& document);

Функция FindDocuments должна искать и выдавать требуемые идентификаторы документов
в виде вектора:

vector<int> FindDocuments(const map<string, set<int>>& word_to_documents,
                          const set<string>& stop_words,
                          const string& query);

В векторе с результатами не должно быть повторов. Используйте для избегания
дубликатов контейнер set как промежуточный. При копировании из set в вектор
результатов не меняйте порядок элементов.
Не меняйте сигнатуру FindDocuments.
*/

void AddDocument(map<string, set<int>>& word_to_documents,
                 const set<string>& stop_words,
                 int document_id,
                 const string& document) {
    for(const string& doc: SplitIntoWords(document)) {
        if(!stop_words.count(doc)) {
            word_to_documents[doc].insert(document_id);
        }
    }
}

vector<int> FindDocuments(const map<string, set<int>>& word_to_documents,
                          const set<string>& stop_words,
                          const string& query) {
    set<int> result;
    for(const string& doc: SplitIntoWords(query)) {
        if(!stop_words.count(doc) && word_to_documents.count(doc)) {
            for(int x: word_to_documents.at(doc)) {
                result.insert(x);
            }
        }
    }
    return vector<int>{result.begin(), result.end()};
}

