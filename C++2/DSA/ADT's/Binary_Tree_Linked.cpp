#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T dataval)
    {
        data = dataval;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class Binary_Tree
{
private:
    Node<T> *Root;

    Node<T> *InsertRec(Node<T> *node, T value)
    {
        if (node == nullptr)
        {
            return new Node<T>(value);
        }
        if (value < node->data)
        {
            node->left = InsertRec(node->left, value);
        }
        else
        {
            node->right = InsertRec(node->right, value);
        }
        return node;
    }

    void PreOrderRec(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        PreOrderRec(node->left);
        PreOrderRec(node->right);
    }

    void InOrderRec(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        InOrderRec(node->left);
        cout << node->data << " ";
        InOrderRec(node->right);
    }

    void PostOrderRec(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        PostOrderRec(node->left);
        PostOrderRec(node->right);
        cout << node->data << " ";
    }

public:
    Binary_Tree()
    {
        Root = nullptr;
    }

    void Insert(T item)
    {
        Root = InsertRec(Root, item);
    }

    void PreOrder()
    {
        PreOrderRec(Root);
    }
    void InOrder()
    {
        InOrderRec(Root);
    }
    void PostOrder()
    {
        PostOrderRec(Root);
    }
   
};

int main()
{
    Binary_Tree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);

    tree.PreOrder();
    cout<<endl;
    tree.PostOrder();
    cout<<endl;
    tree.InOrder();
    return 0;
}