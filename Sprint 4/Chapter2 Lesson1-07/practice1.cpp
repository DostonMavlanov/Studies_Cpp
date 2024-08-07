#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Fibonacci(int num){
    if (num <= 2){
        return 1;
    }else{
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}

int main(){
    cout << Fibonacci(6) << '\n';
}