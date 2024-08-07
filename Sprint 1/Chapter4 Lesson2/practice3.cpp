#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ReadNumbers(){
    int count;
    cin >> count;
    vector<int> result;
    for (int i = 0; i < count; ++i){
        int num;
        cin >> num;
        result.push_back(num);
    }
    return result;
}

void PrintNumbers(const vector<int>& numbers){
    for (size_t i = 0; i < numbers.size(); ++i){
        cout << numbers[i] << " "s;
    }
}

int main(){
    vector<int> numbers = ReadNumbers();
    sort(numbers.begin(), numbers.end(),
        [](int n1, int n2){
            if (n1 % 2 == 0 && n2 % 2 == 0) return n1 < n2;
            if (n1 % 2 == 0) return true;
            if (n2 % 2 == 0) return false;
            return n1 > n2;
        });
    PrintNumbers(numbers);   
}