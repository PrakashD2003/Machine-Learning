#include <iostream>
#include <string>

using namespace std;

// Define a node structure for the linked list
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

// Stack class using a linked list
template <class T>
class Stack_Using_Linked_List
{
private:
    Node<T> *head; // Pointer to the head of the linked list

public:
    Stack_Using_Linked_List()
    {
        head = nullptr; // Initialize an empty stack
    }

    bool isEmpty()
    {
        return head == nullptr; // Check if the stack is empty
    }

    bool isFull()
    {
        Node<T> *temp = new Node<T>();
        return temp == nullptr; // Check if memory allocation failed (unlikely for linked lists)
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(); // Create a new node
        newNode->data = value;
        newNode->next = head; // Point the new node to the current top
        head = newNode;       // Update the head to the new node (new top)
    }

    T pop()
    {
        if (head == nullptr)
        {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return T(); // Return a sentinel value
        }
        Node<T> *nodeToDelete = head;
        head = head->next; // Update the head to the next node
        T rval = nodeToDelete->data;
        delete nodeToDelete; // Free memory for the popped node
        return rval;
    }

    T Top()
    {
        if (head == nullptr)
        {
            return T();
        }
        return head->data; // Return the value of the top element
    }

    T peek(int position)
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return T(); // Return a sentinel value
        }

        Node<T> *temp = head;
        for (int i = 0; i < position && temp != nullptr; i++)
        {
            if (!temp)
            {
                cout << "Position out of range.\n";
                return T(); // Return a sentinel value
            }
            temp = temp->next; // Traverse to the specified position
        }

        if (temp)
            return temp->data; // Return the value at the specified position
        else
            return T(); // Return a sentinel value
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " "; // Print each element
            temp = temp->next;
        }
        cout << endl;
    }

    T get_sentinel_value()
    {
    }
};

// Function to check if brackets are balanced
bool Parentheses_Matching(string exp)
{
    // Declare a stack to hold the brackets.
    Stack_Using_Linked_List<char> temp;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            // push the current bracket
            temp.push(exp[i]);
        }
        else if (temp.Top() == '(' && exp[i] == ')' ||
                 temp.Top() == '{' && exp[i] == '}' ||
                 temp.Top() == '[' && exp[i] == ']')
        {
            // If we found any complete pair of bracket
            // then pop
            temp.pop();
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // If we encounter a closing bracket without a matching opening bracket
            return false;
        }
    }

   // If the stack is empty, the expression is balanced
    return temp.isEmpty();
}
int main()
{
    string expression = "{(2*5)(5*10))";
    cout << Parentheses_Matching(expression);
}
