#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

#include "log_duration.hpp"
using namespace std;

bool TestPermut(const vector<int>& v1, const vector<int>& v2){
    
    LOG_DURATION("Test"s);
    if (v1.size() != v2.size()){
        return false;
    }

    vector<int> sort_v1 = v1;
    vector<int> sort_v2 = v2;

    return sort_v1 == sort_v2;
}

int main(){
    std::mt19937 g;

    int n;
    cin >> n;
    vector<int> v1, v2;
    v1.reserve(n);
    v2.reserve(n);

    for (int i = 0; i < n; ++i){
        v1.push_back(rand());
        v2.push_back(rand());
    }
    cout << "Random vectors match? "s << flush;
    
    cout << (TestPermut(v1, v2) ? "Yes"s : "No"s) << endl;
}