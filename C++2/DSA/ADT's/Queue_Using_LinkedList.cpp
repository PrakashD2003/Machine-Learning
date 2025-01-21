#include <iostream>

using namespace std;

// Template structure for a Node
template <typename T>
struct Node
{
    T data;     // Data part of the node
    Node *next; // Pointer to the next node
};

// Template class for Queue using Linked List
template <typename T>
class Queue_Using_LinkedList
{
    Node<T> *Front; // Pointer to the front node
    Node<T> *Rear;  // Pointer to the rear node

public:
    // Constructor to initialize the queue
    Queue_Using_LinkedList()
    {
        Front = Rear = nullptr; // Initialize front and rear to nullptr indicating the queue is empty
    }

    // Destructor to free the allocated memory
    ~Queue_Using_LinkedList()
    {
        while (Front != nullptr)
        {                          // Loop to delete each node
            Node<T> *temp = Front; // Temporary pointer to store the current front node
            Front = Front->next;   // Move front to the next node
            delete temp;           // Delete the previous front node
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (Front == nullptr); // Return true if the queue is empty
    }

    // Function to check if the queue is full
    // Note: In a linked list implementation, isFull is usually not necessary, but we'll check memory allocation
    bool isFull()
    {
        Node<T> *temp = new Node<T>();
        return temp == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(T item)
    {
        if (isFull())
        {                                    // Check if the queue is full
            cout << "Queue is Full" << endl; // Print message if the queue is full
            return;
        }
        Node<T> *newNode = new Node<T>(); // Allocate memory for a new node
        newNode->data = item;             // Set the data for the new node
        newNode->next = nullptr;          // Set the next pointer of the new node to nullptr
        if (Front == nullptr && Rear == nullptr)
        {                           // If the queue is empty
            Front = Rear = newNode; // Both front and rear will point to the new node
        }
        else
        {
            Rear->next = newNode; // Link the new node at the end of the queue
            Rear = newNode;       // Update the rear to the new node
        }
        cout << "Enqueued: " << item << endl; // Print the enqueued item
        return;
    }

    // Function to remove an element from the queue
    T dequeue()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message if the queue is empty
            return T();                       // Return a default-constructed value of T
        }
        Node<T> *NodeToDelete = Front; // Temporary pointer to store the front node
        T item = Front->data;          // Retrieve the data from the front node
        Front = Front->next;           // Move front to the next node
        if (Front == nullptr)
        {                   // If the queue becomes empty after dequeuing
            Rear = nullptr; // Update rear to nullptr
        }
        delete NodeToDelete;                  // Delete the old front node
        cout << "Dequeued: " << item << endl; // Print the dequeued item
        return item;                          // Return the dequeued item
    }

    // Function to get the front element without removing it
    T peek()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message if the queue is empty
            return T();                       // Return a default-constructed value of T
        }
        return Front->data; // Return the data of the front node
    }

    // Function to display the elements of the queue
    void show()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message and return if empty
            return;
        }
        Node<T> *temp = Front; // Use a temporary pointer to traverse the queue
        cout << "{";           // Start the output format
        while (temp != nullptr)
        {                       // Loop through the queue elements
            cout << temp->data; // Print the data of each node
            if (temp->next != nullptr)
            {                // Check if the next node is not null
                cout << ","; // Print a comma after each element except the last one
            }
            temp = temp->next; // Move to the next node
        }
        cout << "}" << endl; // End the output format
    }
};

// Main function to demonstrate the queue operations
int main()
{
    Queue_Using_LinkedList<int> queue; // Create a queue of integers

    cout << queue.isEmpty() << endl; // Check if the queue is empty

    queue.enqueue(6); // Enqueue elements
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);

    cout << queue.isFull() << endl; // Check if the queue is full

    queue.show(); // Display the queue

    queue.dequeue(); // Dequeue elements
    queue.dequeue();
    queue.dequeue();

    queue.show(); // Display the queue again
}
