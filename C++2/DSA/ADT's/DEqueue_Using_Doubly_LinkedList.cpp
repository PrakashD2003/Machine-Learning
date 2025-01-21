#include <iostream>
using namespace std;

// Node structure for doubly linked list
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

// Template class for Deque using doubly linked list
template <typename T>
class Deque
{
    Node<T> *front;
    Node<T> *rear;
    int size;
    int capacity;

public:
    // Constructor to initialize the deque
    Deque(int cap) : capacity(cap), size(0), front(nullptr), rear(nullptr) {}

    // Destructor to free the allocated memory
    ~Deque()
    {
        while (front != nullptr)
        {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to check if the deque is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Function to check if the deque is full
    bool isFull()
    {
        return size == capacity;
    }

    // Function to insert an element at the front
    void insertFront(T item)
    {
        if (isFull())
        {
            cout << "Deque is full\n";
            return;
        }
        Node<T> *newNode = new Node<T>();
        newNode->data = item;
        newNode->next = front;
        newNode->prev = nullptr;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            front->prev = newNode;
            front = newNode;
        }
        size++;
        cout << "Inserted at front: " << item << endl;
    }

    // Function to insert an element at the rear
    void insertRear(T item)
    {
        if (isFull())
        {
            cout << "Deque is full\n";
            return;
        }
        Node<T> *newNode = new Node<T>();
        newNode->data = item;
        newNode->next = nullptr;
        newNode->prev = rear;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Inserted at rear: " << item << endl;
    }

    // Function to delete an element from the front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }
        Node<T> *temp = front;
        front = front->next;
        if (front != nullptr)
        {
            front->prev = nullptr;
        }
        else
        {
            rear = nullptr;
        }
        delete temp;
        size--;
        cout << "Deleted from front\n";
    }

    // Function to delete an element from the rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }
        Node<T> *temp = rear;
        rear = rear->prev;
        if (rear != nullptr)
        {
            rear->next = nullptr;
        }
        else
        {
            front = nullptr;
        }
        delete temp;
        size--;
        cout << "Deleted from rear\n";
    }

    // Function to get the front element
    T getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return T(); // Return a default-constructed value of T
        }
        return front->data;
    }

    // Function to get the rear element
    T getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return T(); // Return a default-constructed value of T
        }
        return rear->data;
    }

    // Function to display the elements of the queue
    void show()
    {
        if (isEmpty())
        {                                     
            cout << "Queue is Empty" << endl; 
            return;
        }
        Node<T> *temp = Front; 
        cout << "{";           
        while (temp != nullptr)
        {                       
            cout << temp->data; 
            if (temp->next != nullptr)
            {                
                cout << ","; 
            }
            temp = temp->next; 
        }
        cout << "}" << endl; 
    }
};

// Example usage
int main()
{
    Deque<int> deque(5); // Create a deque of integers with capacity 5

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.insertRear(25);

    cout << "Front element: " << deque.getFront() << endl;
    cout << "Rear element: " << deque.getRear() << endl;

    deque.deleteFront();
    deque.deleteRear();

    cout << "Front element after deletion: " << deque.getFront() << endl;
    cout << "Rear element after deletion: " << deque.getRear() << endl;

    return 0;
}
