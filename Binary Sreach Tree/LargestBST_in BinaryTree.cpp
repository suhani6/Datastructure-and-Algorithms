#include <iostream>
#include<climits>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
info largestBST(node* root){
    if(root==NULL){
        return{0,INT_MIN, INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return(1,root->data,root->data,1,true);
    }
    info leftInfo= largestBST(root->left);
    info rightInfo= largestBST(root->right);
    info curr;
    curr.size= (1+ leftInfo.size+ rightInfo.size);
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min> root->data){
        curr.min= min(leftInfo.min, min(rightInfo.min,root->data));
        curr.max= max(rightInfo.max, max(leftInfo.max,root->data));
        curr.ans= curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(leftInfo.ans, rightInfo.ans);
    curr.isBST=false;
    return curr;
}
int main() {
   node* root= new node(15);
   root->left= new node(20);
   root->right= new node(30);
   root->left->left= new node(5);
   cout<<"largest bst :"<<largestBST(root).ans<<endl;

}
