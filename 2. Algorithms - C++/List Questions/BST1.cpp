#include <iostream>

using namespace std;

typedef struct Node{
    int element;
    Node* left;
    Node* right;
    Node* parent;
};

class BST{
    private:
        Node* root;
        int cnt;
        int* Array; 
        int crr;
        Node* createNode(int item, Node* root);
        Node* insertHelp(Node* root, int item, Node* parent);
        void posOrder(Node* root);
    public:
        void create();
        void insert(int item);
        void firstPosOrder();
        void print();
};

Node* BST::createNode(int item, Node* root){
    Node *node;
    node = new Node;
    node->element = item;
    node->right = NULL;
    node->left = NULL;
    node->parent = root;
    return node;
}

void BST::create(){
    Node *node;
    node = createNode(NULL, NULL);
    this->root = node;
    this->cnt = 0;
    this->crr = 0;
}

void BST::insert(int item){
    this->root = insertHelp(this->root, item, NULL);
    this->cnt++;
}

Node* BST::insertHelp(Node* root, int item, Node* parent){
    if(root == NULL){
        Node* node;
        node = createNode(item, parent);
        return node;
    }
    if(root->element > item) root->left = insertHelp(root->left, item, root);
    else root->right = insertHelp(root->right, item, root);
    return root;
}

void BST::firstPosOrder(){
    if(this->root != NULL){ 
        this->Array = new int[this->cnt];
        posOrder(root->right);
        posOrder(root->left); 
        this->Array[this->crr] = root->element;
        this->crr++;
    }
}

void BST::posOrder(Node* root){
    if(root != NULL){ 
        this->Array[this->crr] = root->element;
        this->crr++;
        posOrder(root->right);
        posOrder(root->left);
    }
}

void BST::print(){
    this->crr--;
    for(int i = 0; i <this->cnt; i++){
        this->crr--;
        cout<<this->Array[this->crr]<<"\n";
    }
}

int main(){
    int item;
    BST bst;
    bst.create();
    while(cin>>item){
        bst.insert(item);
    }
    bst.firstPosOrder();
    bst.print();
    return 0;
}