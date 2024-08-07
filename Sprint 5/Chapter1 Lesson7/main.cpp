#include <chrono>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "log_duration.hpp"

using namespace std;

vector<int> ReverseVector(vector<int>& source_vector){
    return {source_vector.rbegin(), source_vector.rend()};
}

int CountPos(const vector<int>& source_vector, int begin, int end){
    int res = 0;

    for (int i = begin; i < end; ++i){
        if (source_vector[i]){
            ++res;
        }
    }

    return res;
}

void AppendRandom(vector<int>& v, int n){
    v.reserve(n);
    for (int i = 0; i < n; ++i){
        v.push_back(rand() % 2);
    }
}

void Operate(){
    
    LOG_DURATION("Total"s);

    vector<int> random_bits;

    static const int N = 1 << 17;

    {
        LOG_DURATION("Append random"s);
        AppendRandom(random_bits, N);
    }

    vector<int> reversed_bits;
    {
        LOG_DURATION("Reverse"s);
        reversed_bits = ReverseVector(random_bits);
    }

    {
        LOG_DURATION("Counting"s);

        for (int i = 1, step = 1; i <= N; i += step, step *= 2) {
            double rate = CountPos(reversed_bits, 0, i) * 100./i;
            cout << "After"s << i << " bits we found"s << rate << "% pops"s << endl; 
        }
    }
}    

int main(){
    Operate();
}