#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

using namespace std;


int main(){
    int r;
    cin >> r;
    vector<int> v(r);

    std::mt19937 g;

    // 1. заполним числами от 1 до r
    iota(v.begin(), v.end(), 1);
    
    // 2. перемишаем их случайным образом
    shuffle(v.begin(), v.end(), g);

    // 3. ищем число r / 2
    int pos = find(v.begin(), v.end(), r / 2) - v.begin();
    cout << r / 2 << " находится на позиции "s << pos << endl;

}