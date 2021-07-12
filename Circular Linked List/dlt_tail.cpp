#include<iostream>
#include "Node.h"
using namespace std;
Node *take_input(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    tail->next=head;
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
Node* tail_deleter(Node *head){
    if(head==NULL){
        return head;
    }
    else{
        Node *temp=head;
        Node *prev=head;
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        head=prev->next;
        delete temp;
        return head;
    }
}
int main(){
    Node *head=take_input();
    head=tail_deleter(head);
    print(head);
    return 0;
}