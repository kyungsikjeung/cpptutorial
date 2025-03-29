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
        Node*  returnNode(int data); // 삭제할 노드를 찾아야 함
};