#include <string>
#include <iostream>

using std::string;

string reverse(string s){
    int left=0,right=s.length()-1;char temp;
    while(left<=right){
        temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;right--;
    }
    return s;
}

int main(){
    std::cout<<reverse("hello");
}