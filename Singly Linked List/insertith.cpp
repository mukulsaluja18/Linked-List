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
Node* insert_at_i(Node *head,int i,int val){
    Node *newnode=new Node(val);
    if(i==0){
        newnode->next=head;
        head=newnode;
        return head;
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL && count<i-1){
        count++;
        temp=temp->next;
    }
    if(temp!=NULL){
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;

}
int main(){
    int i,val;
    Node* head=take_input();
    cin>>i>>val;
    head=insert_at_i(head,i,val);
    print(head);
}