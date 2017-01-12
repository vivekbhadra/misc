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
    Stack<int> s;
    int num;

    do {
        cout << "Enter a number ";         cin >> num;
        cout << "Number entered is " << num << endl;
        while (num)
        {
            int n = num % 2;
            num = num/2;
            s.push(n);
        }

        cout << "The binary equivalent of the number is " << endl;
        while(!s.is_stack_empty()) {
            cout << s.pop();
        }
        cout << endl;
        cout << "Do you want to continue? (y/n) ";
        getchar();
    } while (getchar() == 'y');

    return 0;
}
