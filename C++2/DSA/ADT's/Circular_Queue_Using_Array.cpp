#include <iostream>
using namespace std;

// Template class for a Circular Queue using Array
template <typename T>
class Circular_Queue_Using_Array
{
    int Front, Rear, Size; // Variables to track the front, rear, and size of the queue
    T *array;              // Pointer to the array holding the queue elements

public:
    // Constructor to initialize the queue with the given capacity
    Circular_Queue_Using_Array(int Capacity) : Size(Capacity)
    {
        Front = Rear = -1;       // Initialize front and rear to -1 indicating the queue is empty
        array = new T[Capacity]; // Allocate memory for the array
    }

    // Destructor to free the allocated memory
    ~Circular_Queue_Using_Array()
    {
        delete[] array; // Delete the array
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return Front == -1; // Return true if the queue is empty
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (((Rear + 1) % Size) == Front); // Return true if the queue is full
    }

    // Function to add an element to the queue
    void enqueue(T item)
    {
        if (isFull())
        {                                    // Check if the queue is full
            cout << "Queue is Full" << endl; // Print message if the queue is full
            return;
        }
        if (Front == -1)
        {                     // If the queue is initially empty
            Front = Rear = 0; // Update front and rear to 0
        }
        else
        {
            Rear = (Rear + 1) % Size; // Increment rear in a circular manner
        }
        array[Rear] = item;                   // Insert the item at the rear
        cout << "Enqueued: " << item << endl; // Print the enqueued item
    }

    // Function to remove an element from the queue
    T dequeue()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message if the queue is empty
            return -1;                        // Return -1 if the queue is empty
        }
        T item = array[Front]; // Retrieve the front element
        if (Front == Rear)
        {                      // If the queue becomes empty after dequeuing
            Front = Rear = -1; // Reset front and rear to -1
        }
        else
        {
            Front = (Front + 1) % Size; // Increment front in a circular manner
        }
        cout << "Dequeued: " << item << endl; // Print the dequeued item
        return item;                          // Return the dequeued item
    }

    // Function to get the front element without removing it
    T peek()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message if the queue is empty
            return -1;                        // Return -1 if the queue is empty
        }
        return array[Front]; // Return the front element
    }
    
    void show()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message and return if empty
            return;
        }
        cout << "{"; // Start the output format
        for (int i = Front; i <= Rear; i++)
        { // Loop through the queue elements
            if (i != Rear)
            {
                cout << array[i] << ","; // Print each element followed by a comma
            }
            else
            {
                cout << array[i]; // Print the last element without a comma
            }
        }
        cout << "}" << endl; // End the output format
    }
};

int main()

{
    Circular_Queue_Using_Array<int> queue(5);

    cout << queue.isEmpty() << endl;

    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);

    cout << queue.isFull() << endl;

    queue.show();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.show();

    return 0;
}