#include<iostream>
#include "Node.h"
using namespace std;
Node* take_input(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            head->prev=NULL;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    tail->next=head;
    head->prev=tail;
    return head;
}
void print(Node*head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    Node*temp=head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
bool check_cll(Node *head){
    if(head==NULL){
    return true;
    }
    Node *temp=head->next;
    while(temp!=head && temp!=NULL){
        temp=temp->next;
    }
    return (temp==head);
}
void midpoint(Node* head){
    Node *slow=head;
    Node* fast=head->next;
    while(fast!=head && fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}
int main(){
    Node* head=take_input();
    midpoint(head);
    return 0;
}