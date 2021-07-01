#include <iostream>
#include<vector>
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
vector <node*> constructTrees(int start,int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> leftSubtrees = constructTrees(start,i-1);

        vector<node*> rightSubtrees = constructTrees(i+1,end);
        for(int j=0;j<leftSubtrees.size();j++){
            node* left= leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                node* right= rightSubtrees[k];
                node* node1= new node(i);
                node1->left=left;
                node1->right=right;
                trees.push_back(node1);
            }
        }
    }
    return trees;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    vector<node*> totalTrees= constructTrees(1,3);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<": ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
}
