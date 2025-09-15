#include <unordered_map>
#include <iostream>
#include <string>

using std::unordered_map;
using std::string;

class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
};

class TRIE{
    public:
    TrieNode* root;
    void insertWord(string s){
        TrieNode* curr=this->root;
        for(char c:s){
            if(!curr->children.count(c))
                curr->children[c]=new TrieNode();
            curr=curr->children[c];
        }
        curr->children['\0']=new TrieNode();//end of string character
    }
    void deleteWord(string s){
        TrieNode* curr=this->root;
        for(char c:s){
            if(!curr->children.count(c))
                return;
            curr=curr->children[c];
        }
        curr->children.erase('\0');
    }
    bool searchWord(string s){
        TrieNode* curr=this->root;
        for(char c:s){
            if(!curr->children.count(c))
                return false;
            curr=curr->children[c];
        }
        if(curr->children.count('\0'))
            return true;
        return false;
    }
};