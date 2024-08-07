#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int main(){
    cout << "Expectation 5s..."s << endl;
    const auto start_time = chrono::steady_clock::now();
    
    this_thread::sleep_for(chrono::seconds(5));

    const auto end_time = chrono::steady_clock::now();

    const auto dur = end_time - start_time;
    cerr << "Sleep duration: "s << duration_cast<milliseconds>(dur).count() << "ms"s << endl;

    cout << "The wait is over"s << endl;
    return 0;
}