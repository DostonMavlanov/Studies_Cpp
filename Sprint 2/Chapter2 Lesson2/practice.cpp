#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void Assert(bool value, const string& hint){
    if (value != true){
        cout << "Assertion failed. "s;
        if (!hint.empty()){
            cout << "Hint: "s << hint;
        }
        cout << endl;
        abort();
    }
}

int main() {
    const string greeting = "Dosotn"s;
    Assert(greeting.empty(), "Greeting must be non-empty"s);
    cout << "This line will not be printed"s << endl;
}