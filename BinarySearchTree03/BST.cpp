// BST.cpp
#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    root = nullptr;
}

BST::Node* BST::createLeaf(int data) {
    Node* n = new Node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void BST::addLeaf(int data) {
    addLeafPrivate(data, root);
}

void BST::addLeafPrivate(int data, Node* Ptr) {
    if (root == nullptr) {
        root = createLeaf(data);
    } else {
        if (data < Ptr->data) {
            if (Ptr->left != nullptr) {
                addLeafPrivate(data, Ptr->left);
            } else {
                Ptr->left = createLeaf(data);
            }
        } else if (data > Ptr->data) {
            if (Ptr->right != nullptr) {
                addLeafPrivate(data, Ptr->right);
            } else {
                Ptr->right = createLeaf(data);
            }
        } else {
            cout << "Value already in tree" << endl;
        }
    }
}

void BST::printInOrder() {
    printInOrderPrivate(root);
    cout << endl;
}

void BST::printInOrderPrivate(Node* Ptr) {
    if (Ptr == nullptr) return;
    printInOrderPrivate(Ptr->left);
    cout << Ptr->data << " ";
    printInOrderPrivate(Ptr->right);
}

BST::Node* BST::returnNode(int data) {
    return returnNodePrivate(data, root);
}

BST::Node* BST::returnNodePrivate(int data, Node* Ptr) {
    if (Ptr == nullptr) {
        cout << "Value not found" << endl;
        return nullptr;
    } else if (data == Ptr->data) {
        cout << "Value found: " << Ptr->data << endl;
        return Ptr;
    } else if (data < Ptr->data) {
        return returnNodePrivate(data, Ptr->left);
    } else {
        return returnNodePrivate(data, Ptr->right);
    }
}

int BST::returnRootKey() {
    if (root != nullptr) {
        return root->data;
    } else {
        cout << "Tree is empty" << endl;
        return -1;
    }
}

void BST::printChild(int data) {
    Node* node = returnNode(data);
    if (node != nullptr) {
        if (node->left != nullptr) {
            cout << "Left child: " << node->left->data << endl;
        } else {
            cout << "No left child" << endl;
        }
        if (node->right != nullptr) {
            cout << "Right child: " << node->right->data << endl;
        } else {
            cout << "No right child" << endl;
        }
    } else {
        cout << "Node not found" << endl;
    }
}

void BST::findSmallest() {
    Node* smallest = findSmallestPrivate(root);
    if (smallest != nullptr) {
        cout << "Smallest value in the tree: " << smallest->data << endl;
    } else {
        cout << "Tree is empty" << endl;
    }
}

BST::Node* BST::findSmallestPrivate(Node* Ptr) {
    if (Ptr == nullptr) return nullptr;
    else if (Ptr->left == nullptr) return Ptr;
    else return findSmallestPrivate(Ptr->left);
}

void BST::removeNode(int data) {
    root = removeNodePrivate(data, root);
}

BST::Node* BST::removeNodePrivate(int data, Node* Ptr) {
    if (Ptr == nullptr) return nullptr;

    if (data < Ptr->data) {
        Ptr->left = removeNodePrivate(data, Ptr->left);
    } else if (data > Ptr->data) {
        Ptr->right = removeNodePrivate(data, Ptr->right);
    } else {
        if (Ptr->left == nullptr && Ptr->right == nullptr) {
            delete Ptr;
            return nullptr;
        } else if (Ptr->left == nullptr) {
            Node* temp = Ptr->right;
            delete Ptr;
            return temp;
        } else if (Ptr->right == nullptr) {
            Node* temp = Ptr->left;
            delete Ptr;
            return temp;
        } else {
            Node* temp = findSmallestPrivate(Ptr->right);
            Ptr->data = temp->data;
            Ptr->right = removeNodePrivate(temp->data, Ptr->right);
        }
    }
    return Ptr;
}