#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> ComputeTermFreqs(const vector<string>& terms) {
    map<string, int> result;
    for (const string& tmp: terms){
        ++result[tmp];
    }
    return result;
}

int main() {
    const vector<string> terms = {"first"s, "time"s, "first"s, "class"s};
    for (const auto& [term, freq] : ComputeTermFreqs(terms)) {
        cout << term << " x "s << freq << endl;
    }
		// вывод:
		// class x 1
		// first x 2
		// time x 1
}