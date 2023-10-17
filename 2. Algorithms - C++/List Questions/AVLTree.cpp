#include <iostream>

using namespace std;

typedef struct Node{
    long long int element;
    Node* left;
    Node* right;
    int height;
};

class BST{
    private:
        Node* root;
        long long int cnt;
        long long int* Array; 
        int crr;
        int flag;
        Node* createNode(long long int item);
        Node* insertHelp(Node* root, long long int item);
    public:
        void create();
        void insert(long long int item);
        void find(long long int item);       
        int getBalance(Node* root);
        void inorder(Node* root);
        int h(Node* root);
        void firstInorder();
        Node* rightRotate(Node* root);
        Node* leftRotate(Node* root);
};

Node* BST::createNode(long long int item){
    Node *node;
    node = new Node;
    node->element = item;
    node->right = NULL;
    node->left = NULL;
    node->height = 0;
    return node;
}

void BST::create(){
    Node *node;
    node = createNode(NULL);
    this->root = node;
    this->flag = 0;
    this->cnt = 0;
    this->crr = 0;
}

void BST::insert(long long int item){
    if(this->flag == 1){
        this->flag = 0;
        delete[] this->Array;
    }
    this->root = insertHelp(this->root, item);
    this->cnt++;
}

Node* BST::insertHelp(Node* root, long long int item){
    if(root == NULL || root->element == NULL){
        Node* node;
        node = createNode(item);
        return node;
    }
    if(root->element > item){
        root->left = insertHelp(root->left, item);
    }
    else root->right = insertHelp(root->right, item);
    root->height = 1 + max(h(root->left), h(root->right));
    int balance = getBalance(root);
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

int BST::getBalance(Node* root){
    if(root == NULL) return 0 ;
    return h(root->left) - h(root->right);
}

int BST::h(Node* root){
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
    return l;
}

Node* BST::leftRotate(Node* root){
    Node* r = root->right;
    Node* rl = r->left;
    r->left = root;
    root->right = rl;
    root->height = max(h(root->left), h(root->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

void BST::firstInorder(){
    this->flag = 1;
    if(this->root != NULL){ 
        this->Array = new long long int[this->cnt];
        this->crr = 0;
        inorder(root->left);
        this->Array[this->crr] = root->element;
        this->crr++;
        inorder(root->right); 
    }
}

void BST::inorder(Node* root){
    if(root != NULL){ 
        inorder(root->left);
        this->Array[this->crr] = root->element;
        this->crr++;
        if(this->Array[crr - 1] < this->Array[crr - 2] && crr > 1){
            int j = this->crr - 2, temp = this->crr - 1, f = 0;
            if(this->crr > 2){
                do{
                    if(this->Array[crr-1] < this->Array[j-1]) j--;
                    else f = 1;    
                }while(j != 0 && f == 0);
            }
            while(temp > j){
                this->Array[temp] = this->Array[temp-1];
                temp--;
            }
            Array[j] = root->element;
        }
        inorder(root->right);
    }
}

long long int BS(long long int A[], long long int caso, long long int size){
	long long int l = 0, r = (size - 1), m, indice; 
    while(l <= r){
        indice = (l + r)/2;
        if(caso == A[indice]){
            while(caso == A[indice]){
                indice--;
            }indice++;
            return indice;
        } 
        else if(caso < A[indice]) r = indice - 1;
        else l = indice + 1;
    }
    return -1;
}

void BST::find(long long int item){
    if(this->flag == 0) firstInorder();
    /*for(int i = 0; i < this->crr; i++){
        cout<<this->Array[i]<<" ";
    }*/
    long long int f = BS(this->Array, item, this->cnt);
    if(f != -1) cout<<f + 1<<"\n";
    else cout<<"Data tidak ada\n";
}


int main(){
    long long int tam, item[2];
    BST bst;
    cin>>tam;
    bst.create(); 
    for(int i = 0; i < tam; i++){
        cin>>item[0]>>item[1];
        if(item[0] == 1) bst.insert(item[1]);
        else bst.find(item[1]);
    }
    return 0;
}