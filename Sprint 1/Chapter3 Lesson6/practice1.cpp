#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& text){
    vector<string> words;
    string word;
    for (const char c: text){
        if (c == ' '){
            if (!word.empty()){
                words.push_back(word);
                word.clear();
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

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words){
    vector<string> words;
    for (const string& word: SplitIntoWords(text)){
        if (stop_words.count(word) == 0){
            words.push_back(word);
        }
    }
    return words;
}


class SerchServer{
public:
    void AddDocument(int document_id, const string& document){
        const vector<string> words = SplitIntoWordsNoStop(document, stop_words_);
        documents_.push_back({document_id, words});
    }
private:
    struct DocumentContent{
        int id;
        vector<string> words;
    };
    vector<DocumentContent> documents_;
    set<string> stop_words_;
};

int main(){
    return 0;
}