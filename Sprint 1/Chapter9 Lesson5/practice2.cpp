#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Type>
ostream& operator<<(ostream& out, const vector<Type>& container){
    bool flag = true;
    for (const Type& element: container){
        if (flag){
            out << element;
            flag = false;
        }else{
            out << ", "s << element;
        } 
    }
    return out;
}

int main() {
    const vector<int> ages = { 10, 5, 2, 12 };
    cout << ages << endl;
}