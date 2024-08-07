#include <iostream>
#include <new>
#include <string>

using namespace std;

int main(){
    size_t n = 0;
    try{
        for (;;){
            new string(100'000'000, ' ');
            ++n;
        }
    }catch(const bad_alloc&){
        cout << "bad_alloc after "s << " allocation"s << endl;
    }
}