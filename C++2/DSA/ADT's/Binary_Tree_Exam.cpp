#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder traversal
void preorder(Node* node) {
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Inorder traversal
void inorder(Node* node) {
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Postorder traversal
void postorder(Node* node) {
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Traversals
    cout << "Preorder traversal: ";
    preorder(root);
    cout << "\nInorder traversal: ";
    inorder(root);
    cout << "\nPostorder traversal: ";
    postorder(root);

    return 0;
}
