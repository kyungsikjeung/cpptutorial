// BST.h
#ifndef BST_H
#define BST_H

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* createLeaf(int data);
    void addLeafPrivate(int data, Node* Ptr);
    void printInOrderPrivate(Node* Ptr);
    Node* returnNodePrivate(int data, Node* Ptr);
    Node* findSmallestPrivate(Node* Ptr);
    Node* removeNodePrivate(int data, Node* Ptr);

public:
    BST();
    void addLeaf(int data);
    void printInOrder();
    Node* returnNode(int data);
    int returnRootKey();
    void printChild(int data);
    void findSmallest();
    void removeNode(int data);
};

#endif
