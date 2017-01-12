#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    int top;
    T datastore[100];
public:
    Stack() : top(-1) {}
    bool is_stack_empty(void) {return (top == -1) ? true : false;}
    bool is_stack_full(void) {return (top >= 100) ? true : false;}
    void push(T elem)
    {
        if (!is_stack_full()) {
            top++;
            datastore[top] = elem;
        }
    }

    T pop()
    {
        if (is_stack_empty()) {
            cout << "Stack is empty" << endl;
        } else {
            int data = datastore[top];
            top--;
            return data;
        }
    }

    T peek(void)
    {
        if (is_stack_empty()) {
            cout << "Stack is empty" << endl;
        } else {
            int data = datastore[top];
            return data;
        }
    }
};

int main()
{
    Stack<char> word;
    string str;
    string pali = "";

    cout << "Enter a word ";
    cin >> str;
    char w;
    for (auto i = 0; i < str.size(); ++i) {
        w = str[i];
        word.push(w);
    }
    while(!word.is_stack_empty()) {
        stringstream ss;
        char c = word.pop();
        ss << c;
        string s = ss.str();
        pali += s;
    }

    if (str == pali)
        cout << "The word is a palindrome " << endl;
    else
        cout << "The word is not a palindrome " << endl;

    return 0;
}
