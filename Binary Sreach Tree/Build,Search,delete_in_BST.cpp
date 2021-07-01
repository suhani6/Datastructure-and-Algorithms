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
node* insertBST(node* root, int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left= insertBST(root->left,val);
    }
    else{
        root->right= insertBST(root->right,val);
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* searchBST(node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data<key){
        return searchBST(root->right,key);
    }
        return searchBST(root->left,key);
}
node* inorderSucc(node* root){
    node* curr= root;
    while(curr && curr->left!=NULL){
        curr= curr->left;
    }
    return curr;
}
node* deleteBST(node* root,int key){
    if(root==NULL){
        return 0;
    }
    if(key<root->data){
        root->left= deleteBST(root->left,key);
    }else if(key>root->data){
        root->right= deleteBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp= inorderSucc(root->right);
        root->data=temp->data;
        root->right= deleteBST(root->right,temp->data);

    }
    return root;

}
int main() {
    node* root=NULL;
    root= insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    inorder(root);
    if(searchBST(root,5)==NULL){
        cout<<"key doesnt exist"<<endl;
    }
    else{
        cout<<"key exist"<<endl;
    }
root= deleteBST(root,5);
inorder(root);
}
