#include <iostream>
using namespace std;

// Node Structure
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

// Circular Linked list class
template <typename T>
class Circular_Linked_List
{
public:
    Node<T> *head;
    Circular_Linked_List()
    {
        head = nullptr;
    }
    Node<T> *insert_At_Beginnging(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        if (head == nullptr)
        {
            newNode->next = newNode;
            head = newNode;
            return head;
        }
        Node<T> *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return head;
    }
    
    void delete_From_Beginning(){
        if (head == nullptr) return;
        Node<T>* temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next!=head);
        Node<T>* nodeTodelete = head;
        head = head->next;
        temp->next = head;
        delete nodeTodelete;       
    }
    void display_list()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node<T> *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    Circular_Linked_List<int> list;
    list.insert_At_Beginnging(1);
    list.insert_At_Beginnging(2);
    list.insert_At_Beginnging(3);

    list.display_list();
     
    list.delete_From_Beginning();
    list.display_list();
    return 0;
}
