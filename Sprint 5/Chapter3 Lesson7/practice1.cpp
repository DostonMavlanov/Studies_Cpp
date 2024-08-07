#include <iostream>
#include <cstdint>

using namespace std;

int64_t T(int i){
    if (i == 0){
        return 0;
    }

    int prev0 = 0, prev1 = 0, prev2 = 1;
    for (int t = 1; t < i; ++t){
        int64_t next = prev0 + prev1 + prev2;
        prev0 = prev1;
        prev1 = prev2;
        prev2 = next;
    }
    return prev1;
}

int main(){
    int i;
    
    while (true) {
        cout << "Enter index: "s;
        if (!(cin >> i)) {
            break;
        }

        cout << "Ti = "s << T(i) << endl;
    }
}   