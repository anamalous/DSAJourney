#include <iostream>

class Node{
    public:
        int data;
        Node* next;
    Node(int d):data(d),next(nullptr){}
};

void reverse(Node* root){
    if(root==nullptr)
        return;
    reverse(root->next);
    std::cout<<root->data<<" ";
}

Node* iterReverse(Node* root){
    Node *prev=root,*curr=root->next,*track=root->next->next;
    prev->next=nullptr;
    while(track!=nullptr){
        curr->next=prev;
        prev=curr;
        curr=track;
        track=track->next;
    }
    curr->next=prev;
    return curr;
}

int main(){
    std::cout<<"original: ";
    Node* n=new Node(2);
    n->next=new Node(3);
    n->next->next=new Node(5);
    n->next->next->next=new Node(10);
    Node* curr=n;
    while(n!=nullptr){
        std::cout<<n->data<<" ";
        n=n->next;
    }
    std::cout<<"\nrecursive: ";
    reverse(curr);
    std::cout<<"\niterative: ";
    Node* res=iterReverse(curr);
    while(res!=nullptr){
        std::cout<<res->data<<" ";
        res=res->next;
    }
}