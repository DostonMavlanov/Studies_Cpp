#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& text){
    vector<string>words;
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
    return words;
}

class SearchServer{
public:
    void AddDocuments(int document_id, const string& document){
        const vector<string> words = SplitIntoWordsNoStop(document);
        documents_.push_back({document_id, words});
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

int main(){
    
}