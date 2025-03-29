# Binary Search Tree (BST) in C++

This project implements a **Binary Search Tree (BST)** in C++. It allows inserting nodes, printing the tree in in-order, and searching for a specific value.

---

## 📁 File Structure

```
├── BST.h          # BST class declaration
├── BST.cpp        # BST class implementation
├── main.cpp       # Example usage (not shown here)
└── README.md      # This documentation
```

---

## 📦 Class Diagram

```mermaid
classDiagram
    class BST {
        - Node* root
        + BST()
        + addLeaf(int)
        + printInOrder()
        + returnNode(int): Node*
        - addLeafPrivate(int, Node*)
        - printInOrderPrivaet(Node*)
        - returnNodePrivate(int, Node*): Node*
        - createLeaf(int): Node*
    }

    class Node {
        int data
        Node* left
        Node* right
    }

    BST --> Node : uses
```

---

## 🌱 `addLeaf()` Logic

```mermaid
flowchart TD
    A["addLeaf(data)"] --> B["addLeafPrivate(data, root)"]
    B --> C{"root == nullptr"}
    C -- "Yes" --> D["createLeaf(data) and assign to root"]
    C -- "No" --> E{"data < Ptr.data"}
    E -- "Yes" --> F{"Ptr.left != nullptr"}
    F -- "Yes" --> G["addLeafPrivate(data, Ptr.left)"]
    F -- "No" --> H["Ptr.left = createLeaf(data)"]
    E -- "No" --> I{"data > Ptr.data"}
    I -- "Yes" --> J{"Ptr.right != nullptr"}
    J -- "Yes" --> K["addLeafPrivate(data, Ptr.right)"]
    J -- "No" --> L["Ptr.right = createLeaf(data)"]
    I -- "No" --> M["Print: Value already in tree"]
```

---

## 🧾 In-order Traversal Logic

```mermaid
flowchart TD
    A["printInOrder()"] --> B["printInOrderPrivaet(root)"]
    B --> C{"root == nullptr"}
    C -- "Yes" --> D["Print: Tree is empty"]
    C -- "No" --> E{"Ptr.left != nullptr"}
    E -- "Yes" --> F["printInOrderPrivaet(Ptr.left)"]
    E -- "No" --> G["No left child"]
    F --> H["Print Ptr.data"]
    H --> I{"Ptr.right != nullptr"}
    I -- "Yes" --> J["printInOrderPrivaet(Ptr.right)"]
    I -- "No" --> K["No right child"]
```

---

## 🔍 Search Logic (`returnNode()`)

```mermaid
flowchart TD
    A["returnNode(data)"] --> B["returnNodePrivate(data, root)"]
    B --> C{"root == nullptr"}
    C -- "Yes" --> D["Print: Tree is empty, return nullptr"]
    C -- "No" --> E{"data == Ptr.data"}
    E -- "Yes" --> F["Print: Value found, return Ptr"]
    E -- "No" --> G{"data < Ptr.data"}
    G -- "Yes" --> H{"Ptr.left != nullptr"}
    H -- "Yes" --> I["returnNodePrivate(data, Ptr.left)"]
    H -- "No" --> J["Print: Not found, return nullptr"]
    G -- "No" --> K{"Ptr.right != nullptr"}
    K -- "Yes" --> L["returnNodePrivate(data, Ptr.right)"]
    K -- "No" --> M["Print: Not found, return nullptr"]
```

---

## ✅ How to Build and Run

### Compile:
```bash
g++ -std=c++11 main.cpp BST.cpp -o bst
```

### Run:
```bash
./bst
```

> Ensure `main.cpp` includes usage of `addLeaf()`, `printInOrder()`, and `returnNode()` for testing.

---

## 📝 Notes

- Tree nodes are dynamically allocated with `new`.
[동적 트리노드 생성]
- No delete functionality is included.[레슨 01에서는 바이너리서치 트리 insert만 ]
- Duplicate values are not inserted.
(중복되는 값 삽입 안함)
---

## 📌 Requirements

- C++11 or newer
- g++ compiler
- Recommended: VS Code + Markdown Preview Mermaid Support extension for diagram previews

---


