#include <iostream>
#include <string>

using namespace std;

int IsPowOfTwo(int num){
    if (num != 1 && num % 2 != 0){
        return 0;
    }else if (num == 1){
        return 1;
    }
    else{
        return IsPowOfTwo(num / 2);
    }
}


int main(){
    cout << IsPowOfTwo(2048) << '\n';
}
