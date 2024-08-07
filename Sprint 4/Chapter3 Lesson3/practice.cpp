#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdint>
#include <stack>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end){
    for (auto it = range_begin; it != range_end; ++it){
        cout << *it << " ";
    }
    cout << endl;
}

template <typename Type>
class Queue {
public:
    void Push(const Type& element){
        stack_1.push(element);
    }
    void Pop() {
        MoveElements();
        stack_2.pop();
    }

    Type& Front(){
        MoveElements();
        return stack_2.top();
    }

    uint64_t Size(){
        return stack_1.size() + stack_2.size();
    }

    bool IsEmpty(){
        return (stack_1.empty() && stack_2.empty());
    }
private:
    stack<Type> stack_1;
    stack<Type> stack_2;

    void MoveElements(){
        if (stack_2.empty()){
            while (!stack_1.empty()){
                stack_2.push(stack_1.top());
                stack_1.pop();
            }
        }
    }
};


int main() {
    setlocale(LC_ALL, "Russian");

    Queue<int> queue;
    vector<int> values(5);

    // заполняем вектор для тестирования очереди
    iota(values.begin(), values.end(), 1);
    // перемешиваем значения
    random_shuffle(values.begin(), values.end());

    PrintRange(values.begin(), values.end());

    cout << "Заполняем очередь"s << endl;

    // заполняем очередь и выводим элемент в начале очереди
    for (int i = 0; i < 5; ++i) {
        queue.Push(values[i]);
        cout << "Вставленный элемент "s << values[i] << endl;
        cout << "Первый элемент очереди "s << queue.Front() << endl;
    }

    cout << "Вынимаем элементы из очереди"s << endl;

    // выводим элемент в начале очереди и вытаскиваем элементы по одному
    while (!queue.IsEmpty()) {
        // сначала будем проверять начальный элемент, а потом вытаскивать,
        // так как операция Front на пустой очереди не определена
        cout << "Будем вынимать элемент "s << queue.Front() << endl;
        queue.Pop();
    }
    return 0;
}