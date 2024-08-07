#include <iostream>
#include <string>

using namespace std;

template <typename T>
void RunTestImpl (T func, const string& func_str){
    func();
    cerr << func_str << " Ok"s << endl;
}

#define RUN_TEST(func) RunTestImpl((func), #func)

void Test1(){

}

int main(){
    RUN_TEST(Test1);
    return 0;
}