#include <vector>
#include <iostream>
using std::vector;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d,Node* l, Node* r):data(d),left(l),right(r){};

    void addLeftChild(Node &n){
        this->left=&n;
    }
    void addRightChild(Node &n){
        this->right=&n;
    }

    bool hasLeftChild(){
        if(left!=nullptr)
            return true;
        else    
            return false;
    }
    bool hasRightChild(){
        if(right!=nullptr)
            return true;
        else    
            return false;
    }
};

class minHeap{
    Node* root;
    Node* insertParent;
    minHeap(Node* r):root(r){};
    bool insertNode(int data){
        
    }
};

vector<int> treeToArray(Node* root){
    vector<int> arrayrep;
    vector<Node*> toTraverse;
    Node* curr;
    toTraverse.push_back(root);
    int i=0;
    while(i<toTraverse.size()){
        curr=toTraverse[i];
        arrayrep.push_back(curr->data);
        if(curr->hasLeftChild())
            toTraverse.push_back(curr->left);
        if(curr->hasRightChild())
            toTraverse.push_back(curr->right);
        i+=1;
    }
    return arrayrep;
}

int main(){
    Node root(1,nullptr,nullptr);
    root.left=new Node(2,nullptr,nullptr);
    root.right=new Node(5,nullptr,nullptr);
    root.left->left=new Node(4,nullptr,nullptr);
    root.left->right=new Node(3,nullptr,nullptr);
    //children occur at 2i+1 and 2i+2 indices
    vector<int> rep=treeToArray(&root);
    for(auto item:rep){
        std::cout<<item<<"\t";
    }
}