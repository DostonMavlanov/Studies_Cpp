#include <iostream>
#include <stack>

using namespace std;

template <typename Type>
class SortedStack{
public:
    void Push(const Type& element) {
        if (elements_.empty()){
            elements_.push(element);
            count_insert_++;
            return;
        }
    
        Type last_elem = elements_.top();
        if (last_elem < element) {
            count_if_++;
            elements_.pop();
            Push(element);

            elements_.push(last_elem);
            count_insert_++;
        }else{
            elements_.push(element);
            count_insert_++;
        }
    }

    void Count(){
        cout << count_insert_;
    }

    void Count_If(){
        cout << count_if_;
    }
private:
    stack<Type> elements_;
    int count_insert_ = 0;
    int count_if_ = 0;
};

int main(){
    SortedStack<int> my_stack;
    for (int i = 1; i <= 100; ++i){
        my_stack.Push(i);
    }
    my_stack.Count();
    my_stack.Count_If();
}