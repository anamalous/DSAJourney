#include <vector>
#include <iostream>
#include <cmath>
using std::vector;
using std::floor;


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

class minHeapArray{
    public:
        vector<int> heaparr;
        minHeapArray(int r){
            heaparr.push_back(r);
        };

        int getRoot(){
            return heaparr[0];
        }
        void insertNode(int data){
            heaparr.push_back(data);
            int temp,parent,curr=heaparr.size()-1;
            while(curr>0){
                parent=floor((curr-1)/2);
                if(heaparr[parent]>heaparr[curr]){
                    temp=heaparr[parent];
                    heaparr[parent]=heaparr[curr];
                    heaparr[curr]=temp;
                    curr=parent;
                }
                else{
                    break;
                }
            }
        }
        void deleteNode(int index=0){
            heaparr[index]=heaparr[heaparr.size()-1];
            heaparr.pop_back();
            int temp,child;
            while(index<heaparr.size()-1){
                child=heaparr[2*index+1]<=heaparr[2*index+2]?2*index+1:2*index+2;
                if(heaparr[child]<heaparr[index]){
                    temp=heaparr[child];
                    heaparr[child]=heaparr[index];
                    heaparr[index]=temp;
                    index=child;
                }
                else
                    break;
            }
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
    /*
    Node root(1,nullptr,nullptr);
    root.left=new Node(2,nullptr,nullptr);
    root.right=new Node(5,nullptr,nullptr);
    root.left->left=new Node(4,nullptr,nullptr);
    root.left->right=new Node(3,nullptr,nullptr);*/
    minHeapArray m(2);
    m.insertNode(5);
    m.insertNode(4);
    m.insertNode(10);
    m.insertNode(3);
    m.insertNode(1);
    m.insertNode(6);
    //children occur at 2i+1 and 2i+2 indices
    for(auto item:m.heaparr)
        std::cout<<item<<"\t";
    std::cout<<std::endl;

    for(int i=0;i<4;i++){
        m.deleteNode();
        for(auto item:m.heaparr)
            std::cout<<item<<"\t";
        std::cout<<std::endl;
    }

    std::cout<<m.getRoot();
}