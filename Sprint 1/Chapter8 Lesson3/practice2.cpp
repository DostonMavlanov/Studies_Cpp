#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

enum class Status{
    ACTUAL, 
    EXPIRED, 
    DELETED
};

struct Document {
    int id;
    Status status;
    double relevance;
    int rating;
};

void SortDocuments (vector<Document>& matched_documents){
    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs){
            if (lhs.status != rhs.status) {
                return lhs.status < rhs.status;
            }
            if (lhs.rating != rhs.rating) {
                return lhs.rating > rhs.rating;
            }
            return lhs.relevance > rhs.relevance;
        });
}



int main(){
    vector<Document> documents = {
        {100, Status::ACTUAL,  0.5, 4},
        {101, Status::EXPIRED, 0.5, 4},
        {102, Status::ACTUAL,  1.2, 4},
        {103, Status::DELETED, 1.2, 4},
        {104, Status::ACTUAL,  0.3, 5},
    };

    SortDocuments(documents);

    for (const Document& document: documents){
        cout << document.id << ' '
             << static_cast<int>(document.status) << ' '
             << document.relevance << ' '
             << document.rating << endl;
    }
}
