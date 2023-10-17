#include<iostream>
#include<vector>


using namespace std;
struct node {               //NODE DEFINATION
  long long int key;
  struct node *left;
  struct node *right;
  long long int height;
  long long int left_child ;
  long long int right_child;
};

long long int height(struct node *n){  //THIS RETURNS THE HEIGHT OF ANY NODE
  if(n == NULL){
    return -1;
  }
  else{
    return n->height;
  }
}

struct node *rightRotate(struct node *y){   // THIS ROTATES THE NODE Y RIGHT AND REPLACES IT BY ITS LEFT CHILD ,X
  struct node *x = y->left;
  struct node *z = x->right;
  x->right = y;
  y->left = z;
  y->height = max(height(y->left),height(y->right))+1;
  x->height = max(height(x->left),height(x->right))+1;
  y->left_child = x->right_child;
  x->right_child = y->right_child+y->left_child +1;
  return x;
}
struct node *leftRotate(struct node *y){      // THIS ROTATES THE NODE Y LEFT AND REPLACES IT BY ITS RIGHT CHILD, X
  struct node *x = y->right;
  struct node *z = x->left;
  x->left = y;
  y->right = z;
  y->height = max(height(y->left),height(y->right))+1;
  x->height = max(height(x->left),height(x->right))+1;
  //cout<<x->left_child<<" "<<x->right_child<<endl;
  //cout<<y->left_child<<" "<<y->right_child<<endl;
  y->right_child = x->left_child;
  x->left_child = y->left_child + y->right_child +1;
  return x;
}

long long int getBalance(struct node *n){   //THIS IS TO OBTAIN THE BALANCE BETWEEN THE NODES
  if(n == NULL){
    return 0;
  }
  return height(n->left) - height(n->right);
}

struct node *insert(struct node *n, long long int key){
    if(n == NULL){
    //cout<<"ey"<<endl;
    struct node* temp = new node();
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    temp->left_child = 0;
    temp->right_child = 0;
    return temp;
  }
  if(key < n->key){
    n->left = insert(n->left,key);
  }
  else if(key > n->key){
    n->right = insert(n->right,key);
  }
  n->height = max(height(n->left),height(n->right))+1;
  if(n->right != NULL ){  //UPDATE THE VALUE OF NODES IN THE RIGHT SUBTREE
  n->right_child = (n->right->right_child)+ (n->right->left_child)+1;
}
  if(n->left != NULL){    //UPDATE THE VALUE OF THE NODES IN THE LEFT SUBTREE
  n->left_child = (n->left->right_child)+ (n->left->left_child)+1;
}
  long long int balance = getBalance(n);
  if(balance > 1 && key < n->left->key){
    return rightRotate(n);
  }
  if(balance < -1 && key > n->right->key){
    return leftRotate(n);
  }
  if(balance > 1 && key > n->left->key){
    n->left = leftRotate(n->left);
    return rightRotate(n);
  }
  if(balance < -1 && key < n->right->key){
    n->right = rightRotate(n->right);
    return leftRotate(n);
  }

  return n;

}

int  ifPresent(struct node * root, long long int key){
  if(root==NULL){
    return 0;
  }
  if(root->key == key){
    return 1;
  }
  else if(root->key < key){
    return ifPresent(root->right,key);
  }
  else{
    return ifPresent(root->left,key);
  }
}
long long int findRank(struct node *root, long long int key){
   if(root->key == key){
     return root->left_child+ 1;
   }
   else if ( root->key < key){
     return  (root->left_child)+ 1 + findRank(root->right,key);
   }
   else{
     return findRank(root->left,key);
   }
}

int main(){
  long long int n;
  cin>>n;
  struct node *root = NULL;

  for(long long int i = 1; i<= n;i++){
    long long int x;
    cin>>x;
    if(x == 1){
      long long int y;
      cin>>y;
      root = insert(root,y);
    }
    else{
       long long int y;
       cin>>y;
       if(ifPresent(root,y)){
         cout<<findRank(root,y)<<endl;
       }
       else cout<<"Data tidak ada"<<endl;
     }
  }
}