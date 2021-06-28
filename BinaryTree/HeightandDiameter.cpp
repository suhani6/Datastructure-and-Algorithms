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
int calculateDiameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight= calculateheight(root->left);
    int rheight= calculateheight(root->right);
    int currDiameter = lheight +rheight+1;
    int ldiameter= calculateDiameter(root->left);
    int rdiameter= calculateDiameter(root->right);
    return max(currDiameter,max(ldiameter,rdiameter));
}
int calcDiameter(node*root,int *height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int ld=calcDiameter(root->left,&lh);
    int rd=calcDiameter(root->right,&rh);
    int currd=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currd,max(ld,rd));

}
int main() {
    node*root=new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    //cout<<countNodes(root)<<endl;
    //cout<<calculateheight(root)<<endl;
    int height=0;
    cout<<calcDiameter(root,&height);

}