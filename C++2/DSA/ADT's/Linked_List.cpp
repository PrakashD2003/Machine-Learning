#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    Node<T> *insertAtBeginning(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return newNode;
    }
    Node<T> *insertAtEnd(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return newNode;
    }

    Node<T> *insertAtindex(int positon, T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        if (positon == 0)
        {
            newNode->next = head;
            head = newNode;
            return newNode;
        }

        Node<T> *temp = head;
        for (int i = 0; i < positon - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        return newNode;
    }
    Node<T> *insertAfterNode(Node<T> *&ptr, int value)
    {
        if (ptr == nullptr)
        {
            return nullptr; // Exit the function and return nullptr
        }
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        newNode->next = ptr->next;
        ptr->next = newNode;
        return newNode;
    }

    void delete_From_Beginning()
    {
        if (head != nullptr)
        {
            Node<T> *nodeTodelete = head;
            head = head->next;
            delete nodeTodelete;
        }
    }

    void delete_From_End()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<T> *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void delete_From_index(int index)
    {
        if (head == nullptr)
        {
            return;
        }
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T> *temp = head;
        for (int i = 0; i < index - 1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp->next != nullptr)
        {
            Node<T> *nodeTodelete = temp->next;
            temp->next = nodeTodelete->next;
            delete nodeTodelete;
        }
    }
    void delete_First_Node_With_Given_Value(T value)
    {
        if (head == nullptr)
        {
            // List is empty; nothing to delete
            return;
        }

        // Check if the head node contains the value
        if (head->data == value)
        {
            Node<T> *nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            // Value not found in the list
            cout << "Value not found in the list." << endl;
            return;
        }
        Node<T> *nodeTodelete = temp->next;
        temp->next = nodeTodelete->next;
        delete nodeTodelete;
    }

    int search(T value)
    {
        Node<T> *temp = head;
        int i = 0; // Initialize i to 0
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return i; // Return the index where the value is found
            }
            temp = temp->next;
            i++;
        }
        return -1; // Return -1 to indicate value not found
    }

    void sort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node<T> *i = head;
        while (i != nullptr)
        {
            Node<T> *j = i->next;
            while (j != nullptr)
            {
                if (i->data > j->data)
                {
                    swap(i->data, j->data);
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    void display_list()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()

{
    LinkedList<int> list;

    
    list.insertAtBeginning(6);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    Node<int> *ptr = list.insertAtindex(3, 3);
    list.insertAfterNode(ptr, 4);
    list.insertAtEnd(5);

    list.display_list();

    cout << list.search(3) << endl;
    list.sort();
    list.display_list();
    list.delete_From_index(4);
    
    list.display_list();
    return 0;
}