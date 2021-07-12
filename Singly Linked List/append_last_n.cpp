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
int length(Node *head){
    if(!head){
        return 0;
    }
    return 1+length(head->next);
}

Node* append_last_n(Node* head,int n){
    int my_index=length(head)-n;
    Node*temp=head;
    Node*temp_new=head;
    int count=0;
    while(temp_new!=NULL && count<my_index-1){
        temp_new=temp_new->next;
        count++;
    }
    Node * temp_head=temp_new->next;
    temp_new->next=NULL;
    Node* k=temp_head;
    while(k->next!=NULL){
        k=k->next;
    }
    k->next=temp;
    return temp_head;
}
Node *append(Node*head,int n){
    Node *temp=head;
    Node*tail=head;
    int x=length(head)-n;
    int count=0;
    Node* newnode=NULL;
    while(tail!=NULL){
        tail=tail->next;
    }
    while(count<x-1){
        temp=temp->next;
        count++;
    }
    newnode=temp->next;
    tail->next=head;
    head=newnode;
    temp->next=NULL;
    return head;

}
int main(){
    int n;
    Node *head=take_input();
    cin>>n;
    head=append_last_n(head,n);
    print(head);
    return 0;
}