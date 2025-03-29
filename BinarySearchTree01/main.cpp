#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> data = {10,30,20,40,50,60,70};
    BST bst;
    for(int i = 0; i < data.size(); i++){
        bst.addLeaf(data[i]);
    }
    
    cout << "In-order traversal: ";
    bst.printInOrder();
    bst.returnNode(20);
    bst.returnNode(100);

    return 0;
}
