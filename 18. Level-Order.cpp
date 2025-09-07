#include <vector>
#include <iostream>

using std::vector;

class Node{
    public:
        int data;
        Node *left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr){}
};

void levelOrder(Node* root){
    vector<Node*> queue;
    queue.push_back(root);int curr=0;
    while(curr<queue.size()){
        std::cout<<queue[curr]->data<<" ";
        if(queue[curr]->left)
            queue.push_back(queue[curr]->left);
        if(queue[curr]->right)
            queue.push_back(queue[curr]->right);
        curr++;
    }
}

int main(){
    Node* root=new Node(2);
    root->left=new Node(3);
    root->right=new Node(5);
    root->left->right=new Node(10);
    root->right->left=new Node(1);
    levelOrder(root);
}