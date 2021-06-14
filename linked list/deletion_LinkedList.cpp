#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head, int val){
    node *n= new node(val);
    n->next= head;
    head=n;

}
void insertAtEnd(node* &head, int val){
    node*n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head, int val){
    if(head==NULL){
        returnl
    }
    if(head->next=NULL){
        deleteAtHead(head);
        return;
    }
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
bool search(node* head,int key){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main() {
    node * head= NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head, 3);
    insertAtHead(head,0);
    display(head);
    cout<<search(head,4)<<endl;;
    deletion(head,3);
    display(head);
    deleteAtHead(head);
    display(head);
}

