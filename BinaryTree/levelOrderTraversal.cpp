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
void printLevelorder(node*root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* node1=q.front();
        q.pop();
        if(node1!=NULL){
            cout<<node1->data<<" ";
        
        if(node1->left){
            q.push(node1->left);
        }
        if(node1->right){
            q.push(node1->right);
        }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
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
    printLevelorder(root);
}