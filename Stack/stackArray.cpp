#include <iostream>
#include <stack>

using namespace std;

class Stack
{

public:
    int *arr;
    int top, size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
            cout << "PUSHED:" << element << endl;
        }
        else
        {

            cout << "Stack Overflow!!" << endl;
        }
    }

    void pop()
    {
        if (top > 0) // atleast one element is present
        {
            int ans = arr[top];
            top--;
            cout << "POPPED:" << ans << endl;
        }
        else
        {

            cout << "Stack Underflow!!" << endl;
        }
    }

    int peek()
    {
        if (top > 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Top element of stack: " << st.peek() << endl;

    st.pop();

    cout << "Top element of stack: " << st.peek() << endl;
}