#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Lang{
    string name;
    int age;
};

int main(){
    vector<Lang> langs = {{"Python"s, 29}, {"Java"s, 24}, {"C#"s, 20}, {"Ruby"s, 25}, {"C++"s, 37}};
    auto it = find_if(langs.begin(), langs.end(), [](const Lang& lang){
        return lang.name.at(0) == 'J';
    });
    cout << it->name << ", " << it->age << endl;
    return 0;
}