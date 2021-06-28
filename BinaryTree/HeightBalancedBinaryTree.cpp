#include <iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int calculateheight(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight= calculateheight(root->left);
    int rheight= calculateheight(root->right);
    return max(lheight,rheight)+1;
}
bool isBalanced(node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)==false){
        return false;

    }
    if(isBalanced(root->right)==false){
        return false;
    }
    int lh= calculateheight(root->left);
    int rh= calculateheight(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }

}
bool checkbalanced(node* root, int *height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(checkbalanced(root->left,&lh)==false){
        return false;

    }
    if(checkbalanced(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}
int main() {
    node*root=new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    int height=0;
    if(checkbalanced(root,&height)){
        cout<<"balanced tree"<<endl;
    }
    else{
        cout<<"not balanced";
    }

}