#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end){
    for (It it = range_begin; it != range_end; ++it){
        cout << *it << " "s;
    }
    cout << endl;
}

template <typename Container, typename Iterator>
void EraseAndPrint(Container& container, Iterator it){
    auto it_to_erase = find(container.begin(), container.end(), *it);
    PrintRange(container.begin(), it_to_erase);
    PrintRange(it_to_erase, container.end());
}


int main() {
    vector<string> langs = { "Python"s, "Java"s, "C#"s, "Ruby"s, "C++"s };
    EraseAndPrint(langs, langs.begin());
}