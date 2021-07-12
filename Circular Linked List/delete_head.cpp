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
Node* head_deleter(Node*head){
    if(head==NULL){
        return head;
    }
    if(head->next==head){
        delete head;
        return NULL;
    }
    Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    delete head;
    head=temp->next;
    return head;
}
Node *dlt_opt(Node*head){
    if(head==NULL){
        return head;
    }
    if(head->next==head){
        delete head;
        return NULL;
    }
    // copies the next head data to head
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
        
}
int main(){
    Node*head=take_input();
    head=head_deleter(head);
    print(head);
    return 0;
}