#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool IsPalindrome(const string& text){
    if (text.empty()) return false;

    string text_without_spaces;
    for (size_t i = 0; i < text.size(); ++i){
        if (text[i] != ' '){
            text_without_spaces += text[i];
        }
    }
    if (text_without_spaces.empty()) return false;
    for (size_t i = 0; i < text_without_spaces.size() / 2; ++i){
        if (text_without_spaces[i] != text_without_spaces[text_without_spaces.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    string text;
    getline(cin, text);

    if (IsPalindrome(text)) {
        cout << "palindrome"s << endl;
    } else {
        cout << "not a palindrome"s << endl;
    }
}