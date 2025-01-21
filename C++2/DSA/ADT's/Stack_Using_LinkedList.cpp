#include <iostream>

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
        head = newNode; // Update the head to the new node (new top)
    }

    T pop()
    {
        if (head == nullptr)
        {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return T(-1); // Return a sentinel value
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
            cout << "Stack is Empty." << endl;
            return T(-1);
        }
        return head->data; // Return the value of the top element
    }

    T peek(int position)
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return T(-1); // Return a sentinel value
        }

        Node<T> *temp = head;
        for (int i = 0; i < position && temp != nullptr; i++)
        {
            if (!temp)
            {
                cout << "Position out of range.\n";
                return T(-1); // Return a sentinel value
            }
            temp = temp->next; // Traverse to the specified position
        }

        if (temp)
            return temp->data; // Return the value at the specified position
        else
            return T(-1); // Return a sentinel value
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
};

int main()
{
    Stack_Using_Linked_List<int> myStack;
    cout<<myStack.pop()<<endl;
    cout << "isEmpty Operation: " << myStack.isEmpty() << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Element at position 0: " << myStack.peek(0) <<endl;
    cout << "Element at position 1: " << myStack.peek(1) <<endl;
    cout << "Element at position 2: " << myStack.peek(2) <<endl;

    cout << "Element Popped: " << myStack.pop() << endl;

    myStack.display();

    cout << "Current Top of Stack: " << myStack.Top() << endl;
    cout << "isFull Operation: " << myStack.isFull() << endl;

    return 0;
}
