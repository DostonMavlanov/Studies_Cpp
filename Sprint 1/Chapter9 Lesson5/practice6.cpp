#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;

template <typename Type, typename Key>
ostream& operator<<(ostream& out, const pair<Type, Key>& container){
    return out << "("s << container.first << ", "s << container.second << ")"s;
}

template <typename Type>
void Print(ostream& out, const Type& container){
    bool is_first = true;
    for (const auto& element: container){
        if (is_first){
            out << element;
            is_first = false;
        }else{
            out << ", " << element;
        }
    }
}

template <typename Type>
ostream& operator<<(ostream& out, const vector<Type>& container){
    out << "["s;
    Print(out, container);
    out << "]"s;
    return out;
}

template <typename Type>
ostream& operator<<(ostream& out, const set<Type>& container){
    out << "{"s;
    Print(out, container);
    out << "}"s;
    return out;
}

template <typename Type, typename Key>
ostream& operator<<(ostream& out, const map<Type, Key>& container){
    out << "<"s;
    Print(out, container);
    out << ">"s;
    return out;
} 

int main(){
    const set<string> cats = { "Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s };
    cout << cats << endl;

    const vector<int> ages = { 10, 5, 2, 12 };
    cout << ages << endl;

    const map<string, int> cat_ages = {
        {"Мурка"s, 10},
        {"Белка"s, 5},
        {"Георгий"s, 2},
        {"Рюрик"s, 12}
    };
    cout << cat_ages << endl;
}
