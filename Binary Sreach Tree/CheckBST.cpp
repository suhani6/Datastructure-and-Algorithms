#include <iostream>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
bool checkBST(node* root, node* min=NULL, node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false; 
    }
    if(max!=NULL && root->data >=max->data){
        return false;
    }
    bool leftValid = checkBST(root->left,min,root);
    bool rightValid= checkBST(root->right,root,max);
    return leftValid and rightValid;
}
int main() {
    node* root1= new node(1);
    root1->left= new node(2);
    root1->right= new node(3);
    if(checkBST(root1,NULL,NULL)){
        cout<<"valid";
    }
    else{
        cout<<"not valid";
    }
}
