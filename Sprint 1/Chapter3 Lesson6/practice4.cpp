#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string ReadLine(){
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber(){
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}   

vector<string> SplitIntoWords(const string& text){
    vector<string> words;
    string word;
    for (const char c: text){
        if (c == ' '){
            if (!word.empty()){
                words.push_back(word);
            }
        }else{
            word += c;
        }
    }
    if (!word.empty()){
        words.push_back(word);
    }
    return words;
}


class SearchServer{
public:
    void AddDocument(int document_id, const string& document){
        const vector<string> words = SplitIntoWordsNoStop(document);
        documents_.push_back({document_id, words});
    }   

    set<string> SetStopWords(const string& text){
        for (const string& word: SplitIntoWords(text)){
            stop_words_.insert(word);
        }
        return stop_words_;
    }

private:
    struct DocumentContent{
        int id;
        vector<string> words;
    };
    vector<DocumentContent> documents_;
    set<string> stop_words_;

    vector<string> SplitIntoWordsNoStop(const string& text){
        vector<string> words;
        for (const string& word: SplitIntoWords(text)){
            if (stop_words_.count(word) == 0){
                words.push_back(word);
            }
        }
        return words;
    }
};


SearchServer CreateSearchSetver(){
    SearchServer search_server;
    search_server.SetStopWords(ReadLine());
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id){
        search_server.AddDocument(document_id, ReadLine());
    }
    return search_server;
}

int main(){
    
}
