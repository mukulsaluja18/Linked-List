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
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    // below code is for printing in reverse order
    cout<<endl;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<head->data<<" ";   
}
Node *reverse(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *newnode=head->next;
    Node*temp=reverse(head->next);
    newnode->next=head;
    head->next=NULL;
    head->prev=newnode;
    return temp;
}
Node *reverse_1(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        // in this approach we are doing swapping 
        prev=curr->next;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}
int main(){
    Node* head=take_input();
    head=reverse(head);
    print(head);
    return 0;
}