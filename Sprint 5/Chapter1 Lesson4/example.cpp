#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace literals;

class LogDuration{
public:
    
    LogDuration(){
    }

    ~LogDuration(){
        const auto end_time = steady_clock::now();
        const auto dur = end_time - start_time;
        cerr << duration_cast<milliseconds>(dur).count() << "ms"s << endl;
    }

private:
    const steady_clock::time_point start_time = steady_clock::now();
};


int main(){
    cout << "Wait 5s..."s << endl;
    {
        LogDuration sleep_guard;
        
        this_thread::sleep_for(5s);
    }
    cout << "Waiting comleted"s << endl;
}