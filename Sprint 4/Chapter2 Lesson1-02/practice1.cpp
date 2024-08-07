#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> langs = {"Python"s, "Java"s, "C#"s, "Ruby"s, "C++"s};
    auto it = find_if(langs.begin(), langs.end(), [](const string& lang){
        return lang.at(0) == 'C';
    });
    cout << *it << endl;
}
