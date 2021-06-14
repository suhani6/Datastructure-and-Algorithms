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
        return;
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
node* reverse(node* &head){
    node* preptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=preptr;
        preptr= currptr;
        currptr=nextptr;
    }
    return preptr;
}
node *reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*newhead= reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node* reversek(node* &head, int k){
    node* preptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=preptr;
        preptr=currptr;
        currptr=nextptr;
        count++;

    }
    if(nextptr!=NULL){
    head->next= reversek(nextptr,k);
    }
    return preptr;
}
void makeCycle(node*&head, int pos){
    node*temp=head;
    node* startnode;
    int count =1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}
bool detectcycle(node* &head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void removeCycle(node* &head){
    node*slow=head;
    node*fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int length(node* head){
    int l=0;
    node*temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;

}
node* kappend(node* &head, int k){
    node*newHead;
    node*newTail;
    node* tail=head;
    int l=length(head);
    int count=1;
    k=k%l;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}
int main() {
    node * head= NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtEnd(head,arr[i]);
    }
    display(head);

    node* newHead= kappend(head,3);
    display(newHead);
}