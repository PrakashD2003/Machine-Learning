#include <iostream>
using namespace std;

template <typename T>
class Stack_Using_Array
{
    T *array;     // Dynamic array to store the stack elements
    int capacity; // Maximum capacity of the stack
    int top; // Index of the top element

public:
    Stack_Using_Array(int Maxsize) : capacity(Maxsize)
    {
        top = -1;               // Initialize top to indicate an empty stack
        array = new T[Maxsize]; // Allocate memory for the stack
    }

    // Destructor to deallocate memory when the object is destroyed
    ~Stack_Using_Array()
    {
        delete[] array; // Free the dynamically allocated memory for the stack
    }

    // Function to push an element onto the stack
    void push(T value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow: Cannot push more elements." << endl;
            return;
        }
        array[++top] = value;
    }

    // Function to pop an element from the stack
    T pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return T(-1); // Return a sentinel value
        }
        return array[top--];
    }

    // Function to return value at a specific index
    T peek(int index)
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return T(-1); // Return a sentinel value (e.g., -1 for int)
        }
        if (index >= 0 && index <= top)
        {
            return array[index];
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }

    // Function to display all elements of stack
    void show()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = 0; i < top + 1; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Function to return Top element of stack
    T Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return T(-1); // Return a sentinel value (e.g., -1 for int)
        }
        return array[top];
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Funtion to check if the stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }
};

int main()
{
    Stack_Using_Array<int> stack1(4);
    
    cout<<stack1.isEmpty()<<endl;

    stack1.push(5);
    stack1.push(6);
    stack1.push(7);
    stack1.push(8);

    stack1.show();
    cout<<stack1.isFull()<<endl;

    stack1.pop();

    stack1.show();

    cout << stack1.peek(1)<<endl;
    cout<< stack1.Top();

    return 0;
}