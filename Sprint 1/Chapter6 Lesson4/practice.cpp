#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

int main(){
    const int64_t min = std::numeric_limits<int64_t>::min();
    const uint64_t max = std::numeric_limits<uint64_t>::max();

    cout << min << '\n';
    cout << max << '\n';
    cout << min + max << '\n';
    cout << 2 * min << '\n';
    cout << 2 * max << '\n';
    return 0;
}