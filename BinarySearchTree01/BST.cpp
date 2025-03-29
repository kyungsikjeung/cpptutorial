#include "BST.h"
#include <iostream>
using namespace std;


BST:: BST(){
    root = nullptr;
}

BST::Node* BST::createLeaf(int data){
    Node* n = new Node;
    n-> data = data;
    n-> left = nullptr;
    n->right = nullptr;
    return n;
}

void BST:: addLeaf(int data){
    addLeafPrivate(data, root);
}

void BST:: addLeafPrivate(int data, Node* Ptr){
    if(root == nullptr){
        root  = createLeaf(data);
    }else{
        if(data < Ptr->data){
            if(Ptr->left != nullptr){
                addLeafPrivate(data, Ptr->left);
            }else{
                Ptr->left = createLeaf(data);
            }
        }else if(data > Ptr-> data){
            if(Ptr->right != nullptr){
                addLeafPrivate(data, Ptr->right);
            }else{
                Ptr->right = createLeaf(data);
            }
        }else{
            cout << "Value alread in tree"<<endl;
        }   
    }
}
void BST:: printInOrderPrivaet(Node* Ptr){
    if(root == nullptr){
        cout << "Tree is empty" << endl;
        return;
    }else{
        if(Ptr->left != nullptr){
            printInOrderPrivaet(Ptr->left);
        }
        cout << Ptr->data << " ";
        if(Ptr->right != nullptr){
            printInOrderPrivaet(Ptr->right);
        }
    }
}


void BST:: printInOrder(){
    printInOrderPrivaet(root);
}

BST::Node* BST::returnNode(int data){
    returnNodePrivate(data, root);
}

BST::Node* BST::returnNodePrivate(int data,Node* Ptr){
    if(root == nullptr){
        cout << "Tree is empty" << endl;
        return nullptr;
    }else{
        if(data == Ptr->data){
            cout << "Value found: " << Ptr->data << endl;
            return Ptr;
        }else{
            if(data < Ptr->data){
                if(Ptr->left != nullptr){
                    return returnNodePrivate(data, Ptr->left);
                }else{
                    cout << "Value not found" << endl;
                    return nullptr;
                }
            }else{
                if(Ptr->right != nullptr){
                    return returnNodePrivate(data, Ptr->right);
                }else{
                    cout << "Value not found" << endl;
                    return nullptr;
                }
            }
        }
    }
}
