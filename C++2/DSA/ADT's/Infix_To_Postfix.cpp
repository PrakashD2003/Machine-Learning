#include <iostream>
#include <cctype> // For isalpha and isdigit

using namespace std;

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
        head = newNode;       // Update the head to the new node (new top)
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


// Define precedence function to return precedence level of operators
int Precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 2; // Higher precedence for '*' and '/'
    }
    else if (op == '+' || op == '-')
    {
        return 1; // Lower precedence for '+' and '-'
    }
    else
    {
        return 0; // Default precedence for other characters (e.g., parentheses)
    }
}

string Infix_To_Postfix(string infix)
{
    Stack_Using_Linked_List<char> stack; // Stack to hold operators
    string postfix = "";                 // Output string for postfix expression

    // Iterate through each character in the infix expression
    for (int i = 0; i < infix.length(); i++)
    {
        // If the character is an operand (letter or digit), add it to postfix
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix += infix[i];
        }
        // If the character is an operator
        else
        {
            // Pop from stack to postfix while precedence of stack top is >= current operator
            while (!stack.isEmpty() && Precedence(stack.Top()) >= Precedence(infix[i]))
            {
                postfix += stack.Top(); // Add operator to postfix
                stack.pop();            // Remove operator from stack
            }
            // Push the current operator onto the stack
            stack.push(infix[i]);
        }
    }

    // Pop all remaining operators from the stack to postfix
    while (!stack.isEmpty())
    {
        postfix += stack.Top(); // Add operator to postfix
        stack.pop();            // Remove operator from stack
    }

    return postfix; // Return the resulting postfix expression
}

int main()
{
    string infix = "a+b*c";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << Infix_To_Postfix(infix) << endl;
    return 0;
}
