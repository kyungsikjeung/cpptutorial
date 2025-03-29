// main.cpp
#include "BST.h"
#include <iostream>
using namespace std;

int main() {
    BST tree;

    // 노드 삽입
    tree.addLeaf(8);
    tree.addLeaf(3);
    tree.addLeaf(10);
    tree.addLeaf(1);
    tree.addLeaf(6);
    tree.addLeaf(14);
    tree.addLeaf(4);
    tree.addLeaf(7);
    tree.addLeaf(13);
    tree.addLeaf(12);

    // 중위 순회 출력
    cout << "\n[중위 순회 결과]" << endl;
    tree.printInOrder();

    // 특정 노드 자식 출력
    cout << "\n[노드 10의 자식 정보]" << endl;
    tree.printChild(10);

    // 노드 삭제 후 다시 중위 순회 출력
    cout << "\n[노드 10 삭제 후 중위 순회 결과]" << endl;
    tree.removeNode(10);
    tree.printInOrder();

    // 최소값 출력
    cout << "\n[트리에서 가장 작은 값]" << endl;
    tree.findSmallest();

    return 0;
}
