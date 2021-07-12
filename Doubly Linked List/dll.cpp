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
    cout<<endl;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<head->data<<" "; 
}
int main(){
    Node *head=take_input();
    print(head);
    return 0;
}