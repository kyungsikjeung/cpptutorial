class BST{
    private:
        struct Node{
            int data;
            Node* left;
            Node* right;
        };
        Node* root;
        void addLeafPrivate(int data, Node* Ptr);
        void printInOrderPrivaet(Node* Ptr);
        Node*  returnNodePrivate(int data,Node* Ptr);

    public:
        BST();
        Node* createLeaf(int data);
        void addLeaf(int data);
        void printInOrder();
        Node*  returnNode(int data); // 삭제할 노드를 찾아야 함 , in order to delete node, we need to find it first
        int returnRootKey(); // 삭제할 노드의 부모 노드를 찾아야 함, in order to delete node, we need to find its parent
        void printChild(int data); // 삭제할 노드의 자식 노드를 찾아야 함, in order to delete node, we need to find its child
    };