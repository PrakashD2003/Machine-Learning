#include <iostream>
using namespace std;

// Template class for Queue using Array
template <typename T>
class Queue_Using_Array
{
    int Front, Rear, Size; // Variables to track the front, rear, and size of the queue
    T *array;              // Pointer to the array

public:
    // Constructor to initialize the queue with given capacity
    Queue_Using_Array(int capacity) : Size(capacity)
    {
        Front = Rear = -1;       // Initialize front and rear to -1 indicating the queue is empty
        array = new T[capacity]; // Allocate memory for the array
    }

    // Destructor to free the allocated memory
    ~Queue_Using_Array()
    {
        delete[] array; // Delete the array
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (Front == -1 || Front > Rear); // Return true if the queue is empty
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (Rear == Size - 1); // Return true if the queue is full
    }

    // Function to add an element to the queue
    void enqueue(T value)
    {
        if (isFull())
        {                            // Check if the queue is full
            cout << "Queue is Full"; // Print message and return if full
            return;
        }
        if (Front == -1)
        {            // If the queue is initially empty
            Front++; // Update front
        }
        array[++Rear] = value;                // Insert the element at the rear and update rear
        cout << "Enqueued:" << value << endl; // Print the enqueued value
    }

    // Function to remove an element from the queue
    T dequeue()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message and return -1 if empty
            return -1;
        }
        T item = array[Front++]; // Retrieve the front element and update front
        if (Front > Rear)
        {                      // If the queue becomes empty after dequeuing
            Front = Rear = -1; // Reset front and rear to -1
        }
        return item; // Return the dequeued item
    }

    // Function to get the front element without removing it
    T peek()
    {
        if (isEmpty())
        {                                     // Check if the queue is empty
            cout << "Queue is Empty" << endl; // Print message and return -1 if empty
            return -1;
        }
        return array[Front]; // Return the front element
    }

    // Function to display the elements of the queue
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

// Main function to demonstrate the queue operations
int main()
{
    Queue_Using_Array<int> queue(10); // Create a queue of integers with capacity 10

    cout << queue.isEmpty() << endl; // Check if the queue is empty

    queue.enqueue(5); // Enqueue elements
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);

    queue.show(); // Display the queue

    queue.dequeue(); // Dequeue elements
    queue.dequeue();

    queue.show();                 // Display the queue again
    cout << queue.peek() << endl; // Peek the front element

    cout << queue.isFull() << endl; // Check if the queue is full

    return 0; // End of the program
}
