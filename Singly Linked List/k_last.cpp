#include<iostream>
#include "Node.h"
using namespace std;
Node *take_input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next; // or tail=newnode
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
// do iteration and dont use size and do in single traversal
int k_last(Node *head,int k){
    Node* slow=head;
    Node* fast=head;
    for(int i=0;i<k;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
int mid(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int main(){
    int k;
    Node*head=take_input();
   // cin>>k;
   // cout<<k_last(head,k)<<endl;
   cout<<mid(head)<<endl;
    return 0;

}