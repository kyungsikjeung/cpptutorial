# 이진 탐색 트리 (Binary Search Tree, BST) - C++ 구현

이 프로젝트는 C++로 작성된 **이진 탐색 트리(BST)**를 구현합니다. 노드 삽입, 중위 순회 출력, 특정 값 검색 등의 기능을 포함합니다.

---

## 📁 파일 구조

```
├── BST.h          # BST 클래스 선언부
├── BST.cpp        # BST 클래스 구현부
├── main.cpp       # 사용 예제 (여기엔 포함되지 않음)
└── README.md      # 이 문서
```

---

## 📦 클래스 다이어그램

```mermaid
classDiagram
    class BST {
        - Node* root
        + BST()
        + addLeaf(int)
        + printInOrder()
        + returnNode(int): Node*
        + returnRootKey(): int
        + printChild(int): void
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

## 🌱 `addLeaf()` 함수 로직

```mermaid
flowchart TD
    A["addLeaf(data)"] --> B["addLeafPrivate(data, root)"]
    B --> C{"root == nullptr"}
    C -- "Yes" --> D["createLeaf(data)를 생성하여 root에 할당"]
    C -- "No" --> E{"data < Ptr.data"}
    E -- "Yes" --> F{"Ptr.left != nullptr"}
    F -- "Yes" --> G["addLeafPrivate(data, Ptr.left)"]
    F -- "No" --> H["Ptr.left = createLeaf(data)"]
    E -- "No" --> I{"data > Ptr.data"}
    I -- "Yes" --> J{"Ptr.right != nullptr"}
    J -- "Yes" --> K["addLeafPrivate(data, Ptr.right)"]
    J -- "No" --> L["Ptr.right = createLeaf(data)"]
    I -- "No" --> M["출력: 값이 이미 존재함"]
```

---

## 🧾 중위 순회 로직 (`printInOrder()`)

```mermaid
flowchart TD
    A["printInOrder()"] --> B["printInOrderPrivaet(root)"]
    B --> C{"root == nullptr"}
    C -- "Yes" --> D["출력: 트리가 비어 있음"]
    C -- "No" --> E{"Ptr.left != nullptr"}
    E -- "Yes" --> F["printInOrderPrivaet(Ptr.left)"]
    E -- "No" --> G["왼쪽 자식 없음"]
    F --> H["현재 노드 출력"]
    H --> I{"Ptr.right != nullptr"}
    I -- "Yes" --> J["printInOrderPrivaet(Ptr.right)"]
    I -- "No" --> K["오른쪽 자식 없음"]
```

---

## 🔍 검색 로직 (`returnNode()`)

```mermaid
flowchart TD
    A["returnNode(data)"] --> B["returnNodePrivate(data, root)"]
    B --> C{"root == nullptr"}
    C -- "Yes" --> D["출력: 트리가 비어 있음, nullptr 반환"]
    C -- "No" --> E{"data == Ptr.data"}
    E -- "Yes" --> F["출력: 값 발견, 노드 반환"]
    E -- "No" --> G{"data < Ptr.data"}
    G -- "Yes" --> H{"Ptr.left != nullptr"}
    H -- "Yes" --> I["returnNodePrivate(data, Ptr.left)"]
    H -- "No" --> J["출력: 값 없음, nullptr 반환"]
    G -- "No" --> K{"Ptr.right != nullptr"}
    K -- "Yes" --> L["returnNodePrivate(data, Ptr.right)"]
    K -- "No" --> M["출력: 값 없음, nullptr 반환"]
```

---

## 🌳 자식 노드 정보 출력 (`printChild()`)

다음 함수는 입력된 값에 해당하는 노드의 **왼쪽 및 오른쪽 자식 노드**를 출력합니다.

```cpp
void BST::printChild(int data){
    Node* node = returnNode(data);
    if(node != nullptr){
        if(node->left != nullptr){
            cout << "Left child: " << node->left->data << endl;
        }else{
            cout << "No left child" << endl;
        }
        if(node->right != nullptr){
            cout << "Right child: " << node->right->data << endl;
        }else{
            cout << "No right child" << endl;
        }
    }else{
        cout << "Node not found" << endl;
    }
}
```

---

## ✅ 컴파일 및 실행 방법

### 컴파일

```bash
g++ -std=c++11 main.cpp BST.cpp -o bst
```

### 실행

```bash
./bst
```



---

## 📝 참고 사항

- 노드는 `new` 연산자로 동적 생성됩니다.
- 삭제 기능은 포함되어 있지 않습니다.
- 중복 값은 삽입되지 않습니다.

---

## 📌 요구 사항

- C++11 이상
- g++ 컴파일러
- 권장 도구: VS Code + Mermaid 미리보기 확장

---


