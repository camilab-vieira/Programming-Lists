#include <iostream>

using namespace std;

typedef struct Node{
    long long int element;
    Node* left;
    Node* right;
    long long int lchild;
    long long int rchild; 
    long long int height;
};

class BST{
    private:
        Node* root;
        long long int cnt;
        Node* createNode(long long int item);
        Node* insertHelp(Node* root, long long int item);
        long long int findElement(Node* root, long long int item);
        long long int getBalance(Node* root);
        long long int h(Node* root);
        Node* rightRotate(Node* root);
        Node* leftRotate(Node* root);
        int element(Node* root, long long int item);
    public:
        void create(long long int item);
        void insert(long long int item);
        void find(long long int item);
};

Node* BST::createNode(long long int item){
    Node *node;
    node = new Node;
    node->element = item;
    node->right = NULL;
    node->left = NULL;
    node->height = 0;
    node->lchild = 0;
    node->rchild = 0;
    return node;
}

void BST::create(long long int item){
    this->root = NULL;
    this->cnt = 0;
}

void BST::insert(long long int item){
    this->root = insertHelp(this->root, item);
    this->cnt++;
}

Node* BST::insertHelp(Node* root, long long int item){
    if(root == NULL){
        Node* node;
        node = createNode(item);
        return node;
    }
    if(root->element > item) root->left = insertHelp(root->left, item);
    else root->right = insertHelp(root->right, item);
    root->height = 1 + max(h(root->left), h(root->right));
    if(root->right != NULL) root->rchild = root->right->rchild + root->right->lchild + 1;
    if(root->left != NULL) root->lchild = root->left->rchild + root->left->lchild + 1;
    long long int balance = getBalance(root);
    if(balance < -1 && item >= root->right->element) return leftRotate(root);
    if(balance > 1 && item < root->left->element) return rightRotate(root);
    if(balance > 1 && item >= root->left->element){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && item < root->right->element){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

long long int BST::getBalance(Node* root){
    if(root == NULL) return 0 ;
    return h(root->left) - h(root->right);
}

long long int BST::h(Node* root){
    if(root == NULL) return -1;
    return root->height;
}

Node* BST::rightRotate(Node* root){
    Node* l = root->left;
    Node* lr = l->right;
    l->right = root;
    root->left = lr;
    root->height = max(h(root->left), h(root->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    root->lchild = l->rchild;
    l->rchild = root->rchild + root->lchild + 1;
    return l;
}

Node* BST::leftRotate(Node* root){
    Node* r = root->right;
    Node* rl = r->left;
    r->left = root;
    root->right = rl;
    root->height = max(h(root->left), h(root->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    root->rchild = r->lchild;
    r->lchild = root->rchild + root->lchild + 1;
    return r;
}

int BST::element(Node* root, long long int item){
	if(root == NULL) return 0;
	if(root->element == item) return 1;
	else if(root->element < item) return element(root->right, item);
	else return element (root->left, item);
}

        
long long int BST::findElement(Node* root, long long int item){
    if(root->element == item){
        return root->lchild + 1;
    }
    else if ( root->element < item){
        return  (root->lchild)+ 1 + findElement(root->right, item);
    }
    else{
        return findElement(root->left,item);
    }
    
}

void BST::find(long long int item){
	if(element(this->root, item)) cout<<findElement(this->root, item)<<endl;
	else cout<<"Data tidak ada"<<endl;
}

int main(){
    long long int tam, item[2];
    BST bst;
    cin>>tam;
    bst.create(tam); 
    for(long long int i = 0; i < tam; i++){
        cin>>item[0]>>item[1];
        if(item[0] == 1) bst.insert(item[1]);
        else bst.find(item[1]);
    }
    return 0;
}