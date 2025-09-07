#include <iostream>
class Node{
    public:
        int data;
        Node *left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr){}
};

int BSTSearch(Node* root,int target){
    if(root==nullptr)
        return -1;
    if(target==root->data)
        return 1;
    if(target<root->data)
        return(BSTSearch(root->left,target));
    if(target>root->data)
        return(BSTSearch(root->right,target));
}

int main(){
    Node* root=new Node(7);
    root->left=new Node(5);
    root->right=new Node(9);
    root->left->right=new Node(6);
    root->right->left=new Node(8);
    std::cout<<BSTSearch(root,3);
}