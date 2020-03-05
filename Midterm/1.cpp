#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
Node(int data){
    this->data=data; 
    this->right = NULL;
    this->left = NULL;
}

Node * find_max(Node * node){
    while(node->right != NULL) node = node -> right;
    return node;
}

};

class BST{
    public:
        Node * root;
    BST(){
        this->root=NULL;
    }
    Node * insert(Node * root, int data){
        if(root == NULL) return new Node(data);
        else if(root->data > data) root->left = insert(root->left, data); 
        else if(root->data < data) root->right = insert(root->right, data);
        return root;
    }
    void print(Node * root){
        if(root==NULL) return;
        print(root->left);
        cout << root->data << endl;
        print(root->right);
    }
};

int main(){
    BST *bst = new BST();
    int n;
    while(cin>>n){
        if (n!=0) bst -> root = bst -> insert(bst->root,n);
        else break;
    }
    bst->print(bst->root);
    return 0;
}
